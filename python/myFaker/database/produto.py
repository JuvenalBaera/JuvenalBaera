from faker import Faker
import random
import database
fake = Faker()

########## PRODUTO ##########
id_produto = -1
nome_produto = ""
preco = 0.0
quantidade_produto = 0

PRODUTOS = [
    ["Computador",], [ "Desktop Laptop",],  ["Notebook",], 
    ["Tablet",],     ["Smartphone",],       [ "Roteador",],
    ["Switch",],     ["Impressora",],       ["Scanner",],
    [ "Monitor",],   ["Teclado",],          ["Mouse",],
    ["Pen Drive",],  [ "HHD",],             ["SSD",],
    ["Memória",],    ["RAM",],              ["Placa-mãe",],
    ["CPU",],        ["GPU",], ["Webcam",], ["Monitor"]
]

for i in range(0, len(PRODUTOS)):
    PRODUTOS[i].append(round(random.random() * random.randint(1, 1000), 2))
    PRODUTOS[i].append(random.randint(100, 1000))

def inserir_produto():
    sql = f"""INSERT INTO enderecos (id_cliente, codigo_postal, rua, cidade, pais)
        VALUES(%s, %s, %s, %s, %s)
    """
    conn = database.connect_database()
    cursor = conn.cursor()
    cursor.executemany(sql, PRODUTOS)
    conn.commit()
    # for prod in PRODUTOS:
    #     cursor.execute(sql, prod)
    #     conn.commit()

if __name__ == "__main__":
    inserir_produto()