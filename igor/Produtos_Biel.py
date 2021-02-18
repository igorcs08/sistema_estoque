class Produtos:
    def __init__(self,nome, marca, preco_C, preco_V, qtd):
        self.cadastrarProduto(nome, marca, preco_C, preco_V, qtd)
    def cadastrarProduto(self, nome, marca, preco_C, preco_V, qtd):
        arquivo = open("estoque.txt",'w')
        arquivo.write(nome+" "+marca+" "+preco_C+" "+preco_V+" "+qtd)
        arquivo.close()
    def visualizarProdutos(self):
        arquivo = open("estoque.txt",'r')
        dados = ""
        for linha in arquivo:
            conteudo = linha.split()
            dados += "Nome: "+conteudo[0] + " , Marca: " + conteudo[1] + " , Preco_compra: "+ conteudo[2] + " , Preco_venda: " + conteudo[3] + " , Quantidade: " +conteudo[4] + "\n"
        return dados
    def excluirProduto(self, item):
        return None 
    def alterarProduto(self):
        return None
    def gravarArq(self,produto):
        return None

p = Produtos("cuscuz","Flocao","1.00","2.50","500")
print(p.visualizarProdutos())