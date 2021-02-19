from produtos import Produtos
teste = Produtos()

teste.cadastrarProduto('sabao', 'omo', 9.3, 10.5, 50)
teste.cadastrarProduto('arroz', 'tio_joao', 3.3, 4.5, 100)
teste.cadastrarProduto('feijao', 'gostozzo', 6.4, 9.5, 30)
teste.cadastrarProduto('farinha_de_trigo', 'dona_benta', 5.5, 6.8, 25)


while True:
    print("1 - MANTER PRODUTOS\n2 - REALIZAR TRANSACAO DE ENTRADA\n3 - REALIZAR TRANSACAO DE SAIDA\n4 - EXIBIR HISTORICO DE ENTRADAS\n5 - EXIBIR HISTORICO DE SAIDAS\n6 - SAIR\n")
    n = int(input())
    if(n == 1):
        #MANTER PRODUTOS
        while True:
            print("1 - CADASTRAR PRODUTO\n2 - EXIBIR PRODUTOS\n3 - ALTERAR PRODUTO\n4 - EXCLUIR PRODUTO\n5 - SAIR\n")
            m = int(input())
            if(m == 1):
                #CADASTRAR PRODUTOS
                print("Digite o nome do produto:")
                nome = input()
                print("Digite a marca do produto:")
                marca = input()
                print("Digite o preco de custo:")
                preco_c = float(input())
                print("Digite o preco de venda:")
                preco_v = float(input())
                print("Digite a quantidade de produtos:")
                qntd = int(input())
                teste.cadastrarProduto(nome, marca, preco_c, preco_v, qntd)
                pass
            if(m == 2):
                #EXIBIR PRODUTOS
                print(teste.visualizarProdutos(teste.lista))
                pass
            if(m == 3):
                #ALTERAR PRODUTOS
                print(teste.visualizarProdutos(teste.lista))
                print("Digite o ID do item que desejas alterar:")
                id = int(input())
                indice = teste.buscarItem(id)
                if (indice != None):
                    print(teste.exibirProduto(teste.lista[indice]))
                    print("O que voce deseja alterar?\n1-Nome\n2-Marca\n3-Preco de custo\n4-Preco de venda\n5-Quantidade\n6-Sair\n")
                    n = int(input())
                    if(n == 1):
                        print("Digite o nome:")
                        dado = input()
                        print(teste.alterarProduto(id, n, dado))
                        pass
                    if(n == 2):
                        print("Digite a marca:")
                        dado = input()
                        print(teste.alterarProduto(id, n, dado))
                        pass
                    if(n == 3):
                        print("Digite o preco de custo:")
                        dado = float(input())
                        print(teste.alterarProduto(id, n, dado))
                        pass
                    if(n == 4):
                        print("Digite o preco de venda:")
                        dado = float(input())
                        print(teste.alterarProduto(id, n, dado))
                        pass
                    if(n == 5):
                        print("Digite a quantidade:")
                        dado = int(input())
                        print(teste.alterarProduto(id, n, dado))
                        pass
                else:
                    print("Item buscado para alteracao nao existe!\n")
                pass

            if(m == 4):
                #EXCLUIR PRODUTOS
                print(teste.visualizarProdutos(teste.lista))
                print(teste.excluirProduto(2))
                pass
            if(m == 5):
                break
        pass
    if(n == 2):
        #REALIZAR TRANSACAO DE ENTRADA

        pass
    if(n == 3):
        #REALIZAR TRANSACAO DE SAIDA
        print(teste.visualizarProdutos(teste.lista))
        print("Qual item desejas fazer retirada?\nObs.:Buscar pelo ID")
        item = int(input())        
        print("Quantidade que desejas fazer retirada?")
        qntd = int(input())        
        
        print(teste.transacaoSaida(item, qntd))

        pass
    if(n == 4):
        #EXIBIR HISTORICO DE ENTRADAS

        pass
    if(n == 5):
        #EXIBIR HISTORICO DE SAIDAS
        print(teste.historico_saida)
        pass
    if(n == 6):        
        break







