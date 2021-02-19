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
    
    def alterarProduto(self, id, opcao, dado):
        
        indice = self.buscarItem(id)
        
        if(opcao == 1):                
            self.lista[indice].setNome(dado)
            pass
        if(opcao == 2):                
            self.lista[indice].setMarca(dado)
            pass
        if(opcao == 3):                
            self.lista[indice].setPreco_C(float(dado))
            pass
        if(opcao == 4):                
            self.lista[indice].setPreco_V(float(dado))
            pass
        if(opcao == 5):                
            self.lista[indice].setQtd(int(dado))
            pass
        return "Item alterado com sucesso!\n"
        
        
    
    def transacaoSaida(self, item, qntd):        
        indice = self.buscarItem(item)
        qntd_atual = self.lista[indice].getQtd()
        if (indice != None):
            if (qntd_atual >= qntd > 0):
                self.lista[indice].setQtd(qntd_atual-qntd)
                transacao = str(self.lista[indice].getId())+" "+self.lista[indice].getNome()+" "+ self.lista[indice].getMarca() +" "+ str(qntd) +" "+self.data_atual()+"\n"
                self.historico_saida.append(transacao)
                return "Quantidade retirada com sucesso!"
            else:
                return "Nao houve retirada!"
        
    def data_atual(self):
        data_hora = datetime.now()
        data = str(data_hora.day)+"/"+str(data_hora.month)+"/"+str(data_hora.year)
        hora = str(data_hora.hour)+":"+str(data_hora.minute)+":"+str(data_hora.second)
        return data+" "+hora