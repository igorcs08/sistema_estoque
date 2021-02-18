class Produto:    
    def __init__(self, nome, marca, preco_C, preco_V, qtd):                        
        self.id = 0
        self.nome = nome
        self.marca= marca
        self.preco_C = preco_C
        self.preco_V = preco_V
        self.qtd = qtd
    
    def getId(self):
        return self.id

    def setId(self, id):
        self.id = id

    def getNome(self):
        return self.nome

    def setNome(self, nome):
        self.nome = nome

    def getMarca(self):
        return self.marca

    def setMarca(self, marca):
        self.marca = marca

    def getPreco_C(self):
        return self.preco_C

    def setPreco_C(self, preco_C):
        self.preco_C = preco_C

    def getPreco_V(self):
        return self.preco_V

    def setPreco_V(self, preco_V):
        self.preco_V = preco_V
    
    def getQtd(self):
        return self.qtd

    def setQtd(self, qtd):
        self.qtd = qtd
