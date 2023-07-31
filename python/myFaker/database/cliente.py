from faker import Faker
import random
import database

fake = Faker("PT")


id_cliente = -1
nome_cliente = ""
nascimento_cliente = ""
sexo_cliente = ""


def inserir_cliente():
    sql = f"""INSERT INTO clientes (nome, sobrenome, nascimento, sexo)
        VALUES(%s, %s, %s, %s)
    """
    for _ in range(0, 5):
        if random.choice(["M", "F"]) == "M":
            nome_cliente = fake.first_name_male()
            sexo_cliente = "M"
        else:
            nome_cliente = fake.first_name_female()
            sexo_cliente = "F"

        sobrenome = fake.last_name()
        nascimento = fake.date()

        # print(nome_cliente)
        # print(sobrenome)
        # print(nascimento)
        # print(sexo_cliente)
        # print()

        dados = (nome_cliente, sobrenome, nascimento, sexo_cliente)
        conn = database.connect_database()
        cursor = conn.cursor()
        cursor.execute(sql, dados)
        conn.commit()

if __name__ == "__main__":
    inserir_cliente()