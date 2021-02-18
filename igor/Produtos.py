from produto import Produto

class Produtos:
    def __init__(self):
        self.lista = []        
    
    def cadastrarProduto(self, nome, marca, preco_C, preco_V, qtd):        
        self.lista.append(Produto(nome, marca, preco_C, preco_V, qtd))
    
    def exibirProduto(self, item):        
        return item.getNome() + " " + item.getMarca() + " " + str(item.getPreco_C()) + " " + str(item.getPreco_V()) + " " + str(item.getQtd()) + "\n"

    def visualizarProdutos(self, item):
        if self.lista != []:
            dados = ""
            for i in item:
                dados += self.exibirProduto(i)
            return dados
        else:
            return "Nao ha itens a serem exibidos!\n"
    
    def buscarItem(self, nome):        
        for item in self.lista:
            if (item.getNome() == nome):
                return self.lista.index(item)
                
    def excluirProduto(self, nome):
        indice = self.buscarItem(nome)
        
        if indice != None:
            removido = self.lista.pop(indice)
            return "O item " + removido.nome +" foi removido com sucesso!\n"
        else:
            return "Item nao existe na lista!\n"
    
    def alterarProduto(self, nome):
        indice = self.buscarItem(nome)
        if (indice != None):
            print(self.exibirProduto(self.lista[indice]))            

        return None

