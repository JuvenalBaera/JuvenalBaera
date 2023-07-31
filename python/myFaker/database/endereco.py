from faker import Faker
import database
fake = Faker("PT")



def inserir_endereco():
    sql = f"""INSERT INTO enderecos (id_cliente, codigo_postal, rua, cidade, pais)
        VALUES(%s, %s, %s, %s, %s)
    """
    for i in range(1, 6):
        codigo_postal = fake.postcode()
        rua = fake.street_address()
        cidade = fake.city()
        pais = fake.country()
        
        dados = (i, codigo_postal, rua, cidade, pais)

        conn = database.connect_database()
        cursor = conn.cursor()
        cursor.execute(sql, dados)
        conn.commit()

if __name__ == "__main__":
    inserir_endereco()