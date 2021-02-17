from produto import Produto

class Produtos:
    def __init__(self):
        self.lista = []        
    
    def cadastrarProduto(self, nome, marca, preco_C, preco_V, qtd):        
        self.lista.append(Produto(nome, marca, preco_C, preco_V, qtd))
    
    def visualizarProdutos(self, item):
        dados = ""
        for i in item:
            dados += i.nome + " " + i.marca + " " + str(i.preco_C) + " " + str(i.preco_V) + " " + str(i.qtd) + "\n"
        return dados
    
    def excluirProduto(self, item):
        return None
    
    def alterarProduto(self):
        return None

