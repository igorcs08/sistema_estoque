from produto import Produto
from datetime import datetime

class Produtos:
    def __init__(self):
        self.lista = []
        self.historico_saida = []
        self.contador = 1
    
    def cadastrarProduto(self, nome, marca, preco_C, preco_V, qtd):
        novo = Produto(nome, marca, preco_C, preco_V, qtd)
        novo.setId(self.contador)
        self.contador+=1
        self.lista.append(novo)
        
    
    def exibirProduto(self, item):        
        return str(item.getId()) + " " + item.getNome() + " " + item.getMarca() + " " + str(item.getPreco_C()) + " " + str(item.getPreco_V()) + " " + str(item.getQtd()) + "\n"
    
    def visualizarProdutos(self, item):
        if item != []:
            dados = ""
            for i in item:
                dados += self.exibirProduto(i)
            return dados
        else:
            return "Nao ha itens a serem exibidos!\n"
    
    def buscarItem(self, id):
        for item in self.lista:
            if (item.getId() == id):
                return self.lista.index(item)
                
    def excluirProduto(self, id):
        indice = self.buscarItem(id)
        
        if indice != None:
            removido = self.lista.pop(indice)
            return "O item " + removido.nome +" foi removido com sucesso!\n"
        else:
            return "Item nao existe na lista!\n"
    
    def alterarProduto(self, id):
        indice = self.buscarItem(id)
        if (indice != None):
            print(self.exibirProduto(self.lista[indice]))
            print("O que voce deseja alterar?\n1-Nome\n2-Marca\n3-Preco de custo\n4-Preco de venda\n5-Quantidade\n6-Sair\n")
            n = int(input())
            if(n == 1):
                print("Digite o nome:")
                self.lista[indice].setNome(input())
                pass
            if(n == 2):
                print("Digite a marca:")
                self.lista[indice].setMarca(input())
                pass
            if(n == 3):
                print("Digite o preco de custo:")
                self.lista[indice].setPreco_C(input())
                pass
            if(n == 4):
                print("Digite o preco de venda:")
                self.lista[indice].setPreco_V(input())
                pass
            if(n == 5):
                print("Digite a quantidade:")
                self.lista[indice].setQtd(input())
                pass
            return "Item alterado com sucesso!\n"
        else:
            return "Item buscado para alteracao nao existe!\n"
        
    
    def transacaoSaida(self):
        print(self.visualizarProdutos(self.lista))
        print("Qual item desejas fazer retirada?\nObs.:Buscar pelo ID")
        item = int(input())
        indice = self.buscarItem(item)
        print("Quantidade que desejas fazer retirada?")
        qntd = int(input())
        qntd_atual = self.lista[indice].getQtd()
        if (qntd_atual >= qntd > 0):
            self.lista[indice].setQtd(qntd_atual-qntd)
            transacao = str(self.lista[indice].getId())+" "+self.lista[indice].getNome()+" "+ self.lista[indice].getMarca() +" "+ str(qntd) +" "+self.data_atual()+"\n"
            self.historico_saida.append(transacao)
            print("Quantidade retirada com sucesso!")
        else:
            print("Nao houve retirada!")
        
    def data_atual(self):
        data_hora = datetime.now()
        data = str(data_hora.day)+"/"+str(data_hora.month)+"/"+str(data_hora.year)
        hora = str(data_hora.hour)+":"+str(data_hora.minute)+":"+str(data_hora.second)
        return data+" "+hora