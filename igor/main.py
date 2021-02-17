from produtos import Produtos
teste = Produtos()

teste.cadastrarProduto('sabao', 'omo', 9.3, 10.5, 50)

print(teste.visualizarProdutos(teste.lista))