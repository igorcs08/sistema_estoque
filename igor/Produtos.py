import Produto as p

class Produtos:
    def __init__(self):
        self.lista = []        
    
    def cadastrarProduto(self, nome, marca, preco_C, preco_V, qtd):        
        self.lista.append(p(nome, marca, preco_C, preco_V, qtd))
    
    def visualizarProdutos(self, item):
        dados = ""
        for i in item:
            dados += item.nome + " " + item.marca + " " + item.preco_C + " " + item.preco_V + " " + item.qtd + "\n"
        return dados
    
    def excluirProduto(self):
        return None
    
    def alterarProduto(self):
        return None

