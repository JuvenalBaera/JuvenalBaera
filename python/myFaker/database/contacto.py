from faker import Faker
import database
fake = Faker("PT")

########## CONTACTO ##########
def inserir_contacto():
    for i in range(1, 6):
        conn = database.connect_database()

        telefone = fake.phone_number()
        email = fake.email()

        sql = """ INSERT INTO contactos (id_cliente, telefone, email)
            VALUES (%s, %s, %s)
        """
        dados = (i, telefone, email)
        cursor = conn.cursor()
        cursor.execute(sql, dados)
        conn.commit()


if __name__ == "__main__":
    inserir_contacto()
