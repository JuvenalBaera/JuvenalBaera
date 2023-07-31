from faker import Faker
import random

import database.endereco as endereco
import database.cliente as cliente
import database.contacto as contacto
import database.produto as produto
import database.pedido as pedido
import database.pagamento as pagamento
import database.database as database

conn = database.connect_database()

