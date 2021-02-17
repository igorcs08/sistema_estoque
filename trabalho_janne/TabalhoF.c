#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cont = 0, i, j, n, confirma = 0, verifica_C = 0, verifica_V = 0, p = 0, C = 0, v = 0;
typedef struct Produto {
	char nome[30];
	float valor;
	char marca[20];
	int compras;
	int vendas;
};
struct Produto *produtos = ((Produto*) malloc(100 * sizeof(Produto)));
 
typedef struct Compra {
	char nome[30];
	int Qnt_Compra;
	char hora_C[9];
	char Data_C[11];
};
struct Compra *compras = ((Compra*)malloc(100 * sizeof(Compra)));

typedef struct Venda {
	char nome[30];
	int Qnt_Venda;
	char hora_V[9];
	char Data_V[11];

};
struct Venda *vendas=((Venda*)malloc(100 * sizeof(Venda)));

typedef struct Arquivo {
	char nome[30];
	char marca[10];
	char valor[10];

};
Arquivo *arquivo = ((Arquivo*)malloc(sizeof(Arquivo)));
Arquivo *alterar = ( (Arquivo*)malloc(100 * sizeof(Arquivo)));

FILE *cadastro;
FILE *compra;
FILE *venda;
FILE *estoque;
void Menu1();
void CadastroP();
void ComprasP();
void VendasP();
void RealizarC();
void ExibirC();
void AlterarC();
void SalvarC();
void ExcluirC();
void Comprar();
void VerCompras();
void Vender();
void VerVendas();
void Cadastro();
void CarregaA();

void Cadastro() {
	char a[100], b[30];
	cadastro = fopen("cadastro.txt", "r");

	i = 0;
	fscanf(cadastro, "%s", arquivo->nome);
	fscanf(cadastro, "%s", arquivo->valor);
	fscanf(cadastro, "%s", arquivo->marca);
	while (fgets(a, 100, cadastro) != NULL) {
		printf("[%d]-Nome: %s\n", i, arquivo->nome);
		fscanf(cadastro, "%s", arquivo->nome);
		fscanf(cadastro, "%s", arquivo->valor);
		fscanf(cadastro, "%s", arquivo->marca);
		i++;
	}
	fclose(cadastro);

}
void Menu1() {
	int n;
	printf("1- Cadastro\n");
	printf("2- Compras de Produtos\n");
	printf("3- Vendas de Produtos\n");
	printf("4-Sair\n");
	printf("Opcao: ");
	scanf("%d", &n);
	switch (n) {
	case 1: CadastroP();
		break;
	case 2: ComprasP();
		break;
	case 3: VendasP();
		break;
	case 4: exit(0);
		break;
	default: printf("Opcao invalida!\n");
		Menu1();
		break;
	}
}
void CadastroP() {
	int n;
	printf("1- Realizar Cadastro\n");
	printf("2- Exibir Cadastro\n");
	printf("3- Alterar Cadastro\n");
	printf("4- Salvar Cadastro\n");
	printf("5- Excluir Cadastro\n");
	printf("6- Voltar ao Menu inicial\n");
	scanf("%d", &n);
	switch (n) {
	case 1: RealizarC();
		break;
	case 2: ExibirC();
		break;
	case 3: AlterarC();
		break;
	case 4: SalvarC();
		break;
	case 5: ExcluirC();
		break;
	default: Menu1();
		break;
	}
}
void RealizarC() {

	if (cont < 100) {
		printf("Informe o nome do Produto:\n");
		scanf("%s", produtos->nome);
		printf("Informe a marca do Produto:\n");
		scanf("%s", produtos->marca);
		printf("Informe o valor do Produto:\n");
		scanf("%f", &produtos->valor);
		produtos->compras = 0;
		produtos->vendas = 0;
		confirma++;
		cont++;

		Menu1();
	}


}
void ExibirC() {

	if (confirma > 0) {
		Cadastro();
		printf("Informe o produto que deseja ver os dados:\n");
		scanf("%d", &n);
		while (n != -1) {
			printf("[%d]-Nome: %s	Marca: %s	Valor:%.2f	Estoque_Qnt:%d\n", n, produtos[n].nome, produtos[n].marca, produtos[n].valor, produtos[n].compras);
			printf("Informe o produto que deseja ver os dados:\n");
			scanf("%d", &n);
		}

		Menu1();
	}
	else {
		printf("Nao ha cadastro para exibir!\n");
		Menu1();
	}



}
void AlterarC() {
	char a[100];

	if (confirma > 0) {
		cadastro = fopen("cadastro.txt", "r");
		i = 0;
		fscanf(cadastro, "%s", alterar->nome);
		fscanf(cadastro, "%s", alterar->valor);
		fscanf(cadastro, "%s", alterar->marca);
		i = 1;
		while (fgets(a, 100, cadastro) != NULL) {
			fscanf(cadastro, "%s", alterar->nome);
			fscanf(cadastro, "%s", alterar->valor);
			fscanf(cadastro, "%s", alterar->marca);
			i++;

		}
		fclose(cadastro);
		Cadastro();
		printf("Qual cadastro deseja Alterar:\n");
		setbuf(stdin, NULL);
		scanf("%d", &n);
		printf("Informe o nome do novo Produto\n");
		scanf("%s", alterar[n].nome);
		printf("Informe a marca do novo Produto:\n");
		scanf("%s", alterar[n].marca);
		printf("Informe o valor do novo Produto:\n");
		scanf("%s", alterar[n].valor);
		cadastro = fopen("cadastro.txt", "w");
		rewind(cadastro);
		for (i = 0; i < cont; i++) {
			fprintf(cadastro, "%s ", alterar[i].nome);
			fprintf(cadastro, "%s ", alterar[i].valor);
			fprintf(cadastro, "%s\n", alterar[i].marca);
		}
		fclose(cadastro);

		Menu1();
	}
	else {
		printf("Nao ha cadastro para ser alterado!");
		Menu1();
	}



}
void SalvarC() {
	cadastro = fopen("cadastro.txt", "r");

	if ((fscanf(cadastro, "%s", arquivo->nome)) != EOF) {
		fclose(cadastro);
		cadastro = fopen("cadastro.txt", "w");
		if (cont) {

			for (i = 0; i < cont; i++) {
				fprintf(cadastro, "%s %f %s\n", produtos[i].nome, produtos[i].valor, produtos[i].marca);
			}
			fclose(cadastro);
			printf("Cadastro(os) salvo(os) com sucesso!!\n");
			Menu1();
			confirma++;
		}

	}
	else {
		fclose(cadastro);
		cadastro = fopen("cadastro.txt", "a");
		if (cont>0) {

			for (i = 0; i < cont; i++) {
				fprintf(cadastro, "%s %f %s\n", produtos[i].nome, produtos[i].valor, produtos[i].marca);
			}
			fclose(cadastro);
			printf("Cadastro(os) salvo(os) com sucesso!!\n");
			Menu1();
		}
		confirma++;
	}
	if (cadastro == NULL) {
		printf("Nao foi possivel abrir o arquivo!\n");
		exit(0);
		system("pause");
	}

	system("pause");
}
void ExcluirC() {
	char a[100];

	if (confirma > 0) {
		cadastro = fopen("cadastro.txt", "r+");
		i = 0;
		fscanf(cadastro, "%s", alterar[0].nome);
		fscanf(cadastro, "%s", alterar[0].valor);
		fscanf(cadastro, "%s", alterar[0].marca);
		i = 1;
		while (fgets(a, 100, cadastro) != NULL) {
			fscanf(cadastro, "%s", alterar[i].nome);
			fscanf(cadastro, "%s", alterar[i].valor);
			fscanf(cadastro, "%s", alterar[i].marca);
			i++;

		}
		fclose(cadastro);
		Cadastro();
		printf("Qual cadastro deseja Excluir:\n");
		setbuf(stdin, NULL);
		scanf("%d", &n);
		if (n == 0) {
			printf("Entrei\n");
			for (i = 0; i < cont; i++) {
				strcpy(alterar[i].nome, alterar[i + 1].nome);
				strcpy(alterar[i].marca, alterar[i + 1].marca);
				strcpy(alterar[i].valor, alterar[i + 1].valor);
			}
			fclose(cadastro);
			cadastro = fopen("cadastro.txt", "w");
			for (i = 0; i < cont; i++) {
				fprintf(cadastro, "%s ", alterar[i].nome);
				fprintf(cadastro, "%s ", alterar[i].valor);
				fprintf(cadastro, "%s\n", alterar[i].marca);
			}
			confirma--;
			printf("Cadastro Excluido com sucesso!\n");
			cont--;
			fclose(cadastro);
		}
		else if (n > 0) {
			for (i = n; i > 2; i++) {
				strcpy(alterar[i - 1].nome, alterar[i].nome);
				strcpy(alterar[i - 1].marca, alterar[i].marca);
				strcpy(alterar[i - 1].valor, alterar[i].valor);

			}
			fclose(cadastro);
			cadastro = fopen("cadastro.txt", "w");
			for (i = 0; i < cont; i++) {
				fprintf(cadastro, "%s ", alterar[i].nome);
				fprintf(cadastro, "%s ", alterar[i].valor);
				fprintf(cadastro, "%s\n", alterar[i].marca);
			}
			confirma--;
			printf("Cadastro Excluido com sucesso!\n");
			cont--;
			fclose(cadastro);
		}
		else if (n == cont) {
			fclose(cadastro);
			cadastro = fopen("cadastro.txt", "w");
			for (i = 0; i < cont; i++) {
				fprintf(cadastro, "%s ", alterar[i].nome);
				fprintf(cadastro, "%s ", alterar[i].valor);
				fprintf(cadastro, "%s\n", alterar[i].marca);
			}
			confirma--;
			cont--;
			printf("Cadastro Excluido com sucesso!\n");
			fclose(cadastro);
		}
		Menu1();
	}
	else {
		printf("Nao tem cadastro para excluir!\n");
		Menu1();
	}

}
void ComprasP() {
	int n;
	printf("1- Realizar Compra\n");
	printf("2- Ver historico de compras\n");
	printf("3- Voltar\n");
	printf("Opcao: ");
	scanf("%d", &n);
	switch (n) {
	case 1: Comprar();
		break;
	case 2: VerCompras();
		break;
	default: Menu1();
		break;
	}
}
void Comprar() {
	Cadastro();
	char teste[10];

	compra = fopen("compra.txt", "r");
	if (compra == NULL) {
		printf("Impossivel realizar compra!!");
		Menu1();
	}
	if (confirma > 0) {
		if (fscanf(compra, "%s", teste) != EOF) {
			fclose(compra);
			compra = fopen("compra.txt", "a");
			printf("Informe o produto vc deseja Comprar:\n");
			scanf("%d", &n);
			printf("Informe a quantidade de intens que sera compra:");

			if (verifica_C < 100) {
				scanf("%d", &compras[verifica_C].Qnt_Compra);
				if (__DATE__[4] == ' ') {
					compras->Data_C[0] = __DATE__[0];
					compras->Data_C[1] = __DATE__[1];
					compras->Data_C[2] = __DATE__[2];
					compras->Data_C[3] = '-';
					compras->Data_C[4] = '0';
					compras->Data_C[5] = __DATE__[5];
					compras->Data_C[6] = '-';
					compras->Data_C[7] = __DATE__[7];
					compras->Data_C[8] = __DATE__[8];
					compras->Data_C[9] = __DATE__[9];
					compras->Data_C[10] = __DATE__[10];

				}
				else {
					compras->Data_C[0] = __DATE__[0];
					compras->Data_C[1] = __DATE__[1];
					compras->Data_C[2] = __DATE__[2];
					compras->Data_C[3] = '-';
					compras->Data_C[4] = __DATE__[4];
					compras->Data_C[5] = __DATE__[5];
					compras->Data_C[6] = '-';
					compras->Data_C[7] = __DATE__[7];
					compras->Data_C[8] = __DATE__[8];
					compras->Data_C[9] = __DATE__[9];
					compras->Data_C[10] = __DATE__[10];
				}
				strcpy(compras->hora_C, __TIME__);
				strcpy(compras->nome, produtos[n].nome);
				produtos[n].compras += compras->Qnt_Compra;
				fprintf(compra, "%s ", produtos[n].nome);
				fprintf(compra, "%s ", compras->Data_C);
				fprintf(compra, "%s ", compras->hora_C);
				fprintf(compra, "%d\n", compras->Qnt_Compra);




				printf("Compra Efetuada com  Sucesso!\n");
				verifica_C++;

				fclose(compra);

				Menu1();

			}
			else {
				printf("Nao pode comprar mais!!\n");
				Menu1();
			}


		}
		else {
			fclose(compra);
			compra = fopen("compra.txt", "w");
			printf("Informe o produto vc deseja Comprar:\n");
			scanf("%d", &n);
			printf("Informe a quantidade de intens que sera compra:");

			if (verifica_C < 100) {
				scanf("%d", &compras->Qnt_Compra);
				if (__DATE__[4] == ' ') {
					compras->Data_C[0] = __DATE__[0];
					compras->Data_C[1] = __DATE__[1];
					compras->Data_C[2] = __DATE__[2];
					compras->Data_C[3] = '-';
					compras->Data_C[4] = '0';
					compras->Data_C[5] = __DATE__[5];
					compras->Data_C[6] = '-';
					compras->Data_C[7] = __DATE__[7];
					compras->Data_C[8] = __DATE__[8];
					compras->Data_C[9] = __DATE__[9];
					compras->Data_C[10] = __DATE__[10];

				}
				else {
					compras->Data_C[0] = __DATE__[0];
					compras->Data_C[1] = __DATE__[1];
					compras->Data_C[2] = __DATE__[2];
					compras->Data_C[3] = '-';
					compras->Data_C[4] = __DATE__[4];
					compras->Data_C[5] = __DATE__[5];
					compras->Data_C[6] = '-';
					compras->Data_C[7] = __DATE__[7];
					compras->Data_C[8] = __DATE__[8];
					compras->Data_C[9] = __DATE__[9];
					compras->Data_C[10] = __DATE__[10];
				}


				strcpy(compras->hora_C, __TIME__);
				strcpy(compras->nome, produtos[n].nome);
				fprintf(compra, "%s ", produtos[n].nome);
				fprintf(compra, "%s ", compras->Data_C);
				fprintf(compra, "%s ", compras->hora_C);
				fprintf(compra, "%d\n", compras->Qnt_Compra);
				printf("Compra Efetuada com  Sucesso!\n");
				produtos[n].compras += compras->Qnt_Compra;
				verifica_C++;

				fclose(compra);
				Menu1();

				if (compra == NULL) {
					printf("Impossivel realizar compra!!");
					Menu1();
				}

			}
			else {
				printf("Nao pode comprar mais!!\n");
				Menu1();
			}

		}

		if (compra == NULL) {
			printf("nao abri!\n");
		}
	}
	else {
		printf("Noa ha produtos para comprar!\n Cadastre e salve  Produtos!\n");
		Menu1();
	}

}
void VerCompras() {
	compra = fopen("compra.txt", "r+");

	i = 0;
	if (verifica_C) {
		while ((fscanf(compra, "%s %s %s %d\n", compras->nome, compras->Data_C, compras->hora_C, &compras->Qnt_Compra)) != EOF) {
			printf("Compra [%d]:\n", i);
			printf("Data: [%s]\t", compras[i].Data_C);
			printf("Hora: [%s]\n", compras[i].hora_C);
			i++;

		}
		printf("Deseja ver os produtos comprados e as quantidades:\n1-Sim\n2-Nao\n");
		scanf("%d", &n);
		switch (n) {
		case 1:
			for (i = 0; i < cont; i++) {

				printf("Produto [%d]:\n", i);
				printf("Nome:[ %s]\t", produtos[i].nome);
				printf("Quantidade comprada:[%d]\n", produtos[i].vendas + produtos[i].compras);
			}
			break;
		default: Menu1();
			break;
		}
	}
	else {
		printf("Nao ha historico de compras!\nCompre produtos!\n");
		Menu1();
	}
}
void VendasP() {
	int n;
	printf("1- Realizar Venda\n");
	printf("2- Ver hitorico de vendas\n");
	printf("3- Voltar\n");
	printf("Opcao: ");
	scanf("%d", &n);
	switch (n) {
	case 1: Vender();
		break;
	case 2: VerVendas();
		break;
	default: Menu1();
	}

}
void Vender() {
	Cadastro();

	venda = fopen("venda.txt", "a");
	if (confirma > 0) {
		for (i = 0; i < cont; i++) {
			printf("Informe o produto que vc deseja Vender:\n");
			setbuf(stdin, NULL);
			scanf("%d", &n);
			if (n != -1) {
				if (produtos[n].compras > 0) {
					for (j = 0; j < verifica_C; j++) {
						if (!strcmp(produtos[n].nome, compras[j].nome)) {
							printf("Existe %d intens desse produto", produtos[n].compras);
							printf("Informe a quantidade de intens que sera vendido:");
							setbuf(stdin, NULL);
							if (verifica_V < 100) {
								scanf("%d", &vendas->Qnt_Venda);
								if (__DATE__[4] == ' ') {
									vendas->Data_V[0] = __DATE__[0];
									vendas->Data_V[1] = __DATE__[1];
									vendas->Data_V[2] = __DATE__[2];
									vendas->Data_V[3] = '-';
									vendas->Data_V[4] = '0';
									vendas->Data_V[5] = __DATE__[5];
									vendas->Data_V[6] = '-';
									vendas->Data_V[7] = __DATE__[7];
									vendas->Data_V[8] = __DATE__[8];
									vendas->Data_V[9] = __DATE__[9];
									vendas->Data_V[10] = __DATE__[10];

								}
								else {
									vendas->Data_V[0] = __DATE__[0];
									vendas->Data_V[1] = __DATE__[1];
									vendas->Data_V[2] = __DATE__[2];
									vendas->Data_V[3] = '-';
									vendas->Data_V[4] = __DATE__[4];
									vendas->Data_V[5] = __DATE__[5];
									vendas->Data_V[6] = '-';
									vendas->Data_V[7] = __DATE__[7];
									vendas->Data_V[8] = __DATE__[8];
									vendas->Data_V[9] = __DATE__[9];
									vendas->Data_V[10] = __DATE__[10];
								}
								strcpy(vendas->hora_V, __TIME__);
								strcpy(vendas->nome, produtos[n].nome);
								fprintf(venda, "%s ", vendas->nome);
								fprintf(venda, "%s ", vendas->Data_V);
								fprintf(venda, "%s ", vendas->hora_V);
								fprintf(venda, "%d\n", vendas->Qnt_Venda);
								printf("Venda Efetuada com  Sucesso!\n");
								produtos[n].vendas += vendas->Qnt_Venda;
								produtos[n].compras -= vendas->Qnt_Venda;
								verifica_V++;

								Menu1();
							}
							else {
								printf("Vendas acabou..");
								Menu1();
							}

						}
					}
				}
				else {
					printf("Nao ha itens deste produto!\n");
				}
			}
			else {
				Menu1();
			}

		}
	}
	else {
		printf("Nao ha produtos cadastrados!\nCadastre e salve produtos antes\n");
		Menu1();
	}
}
void VerVendas() {
	venda = fopen("venda.txt", "r+");

	i = 0;
	if (verifica_V) {
		while (fscanf(venda, "%s %s %s %d\n", vendas->nome, vendas->Data_V, vendas->hora_V, &vendas->Qnt_Venda) != EOF) {
			printf("Compra [%d]:\n", i);
			printf("Data: [%s]\t", vendas[i].Data_V);
			printf("Hora: [%s]\n", vendas[i].hora_V);
			i++;

		}
		printf("Deseja ver os produtos vendidos e as quantidades:\n1-Sim\n2-Nao\n");
		scanf("%d", &n);

		switch (n) {
		case 1:
			for (i = 0; i < cont; i++) {

				printf("Produto[%d]:\n", i);
				printf("Nome:[%s]\t", produtos[i].nome);
				printf("Quantidade vendidas:[%d]\n", produtos[i].vendas);
			}
			break;
		default: Menu1();
			break;
		}
		Menu1();
	}
	else {
		printf("Nao ha historico de vendas!\n");
		Menu1();
	}
}
void CarregaA() {
	cadastro = fopen("cadastro.txt", "r+");

	if (cadastro == NULL) {
		printf("Arquivo nao pode ser aberto!\n");
		Menu1();
	}
	else {
		p = 0;
		while ((fscanf(cadastro, "%s %f %s\n", produtos->nome, &produtos->valor, produtos->marca)) != EOF) {
			produtos->compras = 0;
			produtos->vendas = 0;
			cont++;
			p++;
			confirma++;
		}
		fclose(cadastro);
	}
	compra = fopen("compra.txt", "r+");
	if (compra == NULL) {
		printf("Arquivo nao pode ser aberto!\n");
		Menu1();
	}
	else {
		C = 0;

		while ((fscanf(compra, "%s %s %s %d\n", compras->nome, compras->Data_C, compras->hora_C, &compras->Qnt_Compra)) != EOF) {
			verifica_C++;


			for (i = 0; i < cont; i++) {
				if (!strcmp(produtos[i].nome, compras[C].nome)) {
					produtos[i].compras += compras[C].Qnt_Compra;
				}
			}
			C++;

		}
		fclose(compra);
	}
	venda = fopen("venda.txt", "r+");
	if (venda == NULL) {
		printf("Arquivo nao pode ser aberto!");
	}
	else {
		v = 0;
		while ((fscanf(venda, "%s %s %s %d\n", vendas->nome, vendas->Data_V, vendas->hora_V, &vendas->Qnt_Venda)) != EOF) {
			verifica_V++;
			for (i = 0; i < cont; i++) {
				if (!strcmp(produtos[i].nome, vendas[v].nome)) {
					produtos[i].compras -= vendas[v].Qnt_Venda;
					produtos[i].vendas += vendas[v].Qnt_Venda;
				}
			}
			v++;

		}
		fclose(venda);
	}
	Menu1();
}
int main() {
	CarregaA();
	Menu1();
	free(produtos);
	free(compras);
	free(vendas);
	free(alterar);
	free(arquivo);
	return 0;
}


