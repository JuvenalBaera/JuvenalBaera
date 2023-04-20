import mysql.connector
from database.confidential import conf

def connetion():
    conn = None
    try:
        conn = mysql.connector.connect(
            host = conf.host,
            user = conf.user,
            passwd = conf.password,
            database= conf.db_name
        )
    except mysql.connector.errors.InterfaceError:
        print(f"Error on connecting to {conf.host}")
    except Exception:
        print(f"Something went wrong on database")
    return conn


def query_dml(conn, sql, data):
    if conn != None:
        cursor = conn.cursor()
        cursor.execute(sql, data)
        conn.commit()
        conn.close()


def insert_data(sql, data):
    conn = connetion()
    query_dml(conn, sql, data)


def insert_personal(data):
    sql = """INSERT INTO personal (first_name, last_name, gender, dob)
            VALUES (%s, %s, %s, %s)
    """
    insert_data(sql, data)


def insert_contact(data):
    sql = """INSERT INTO contact (personal_id, email, phone_number)
            VALUES (%s, %s, %s)
    """
    insert_data(sql, data)


def insert_address(data):
    sql = """INSERT INTO address (personal_id, country, city, postal_code, street_number, street_name)
            VALUES (%s, %s, %s, %s, %s, %s)
    """    
    insert_data(sql, data)


def insert_social_info(data):
    sql = """INSERT INTO social_info (personal_id, citizen_card, ssn, fiscal_number)
            VALUES(%s, %s, %s, %s)
    """
    insert_data(sql, data)


def insert_bank(data):
    sql = """INSERT INTO bank (personal_id, credit_type, credit_card, iban, validate)
        VALUES(%s, %s, %s, %s, %s)
    """
    insert_data(sql, data)


def insert_company(data):
    sql = """INSERT INTO company (personal_id, company_name, department, contract_code, hired_date)
        VALUES(%s, %s, %s, %s, %s)
    """
    insert_data(sql, data)


def insert_credential(data):
    sql = """INSERT INTO credential (personal_id, username, password)
        VALUES(%s, %s, %s)
    """
    insert_data(sql, data)
