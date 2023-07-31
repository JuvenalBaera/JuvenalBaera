from faker import Faker
import random
fake = Faker()


quantidade_pedido = 0
data_pedido = ""
preco_total = 0.0
estado = ["CONCLUÍDO", "EM ANDAMENTO", "PENDENTE", "CANCELADO"]


########### PEDIDOS ###########
data_pedido = fake.date_time()
