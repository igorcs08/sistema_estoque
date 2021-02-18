from produtos import Produtos
teste = Produtos()

teste.cadastrarProduto('sabao', 'omo', 9.3, 10.5, 50)
teste.cadastrarProduto('arroz', 'tio_joao', 3.3, 4.5, 100)
teste.cadastrarProduto('feijao', 'gostozzo', 6.4, 9.5, 30)
teste.cadastrarProduto('farinha_de_trigo', 'dona_benta', 5.5, 6.8, 25)


print(teste.visualizarProdutos(teste.lista))
print(teste.excluirProduto(2))
print(teste.visualizarProdutos(teste.lista))
print(teste.alterarProduto(3))
print(teste.visualizarProdutos(teste.lista))
teste.transacaoSaida()
print(teste.visualizarProdutos(teste.lista))
print(teste.historico_saida)
