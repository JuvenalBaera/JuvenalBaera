import mysql.connector as mysqlConn
import mysql.connector.errors as err

def connect_database():
    conn = None
    try:
        conn = mysqlConn.connect(
            user = "root",
            password = "",
            host = "localhost",
            database = "gestaoClientes"
        )
    except err.ProgrammingError:
        print("Erro nos dados do servidor")
    except err.InterfaceError:
        print("Servidor descontectado")
    except Exception as e:
        print(e.__class__)
    return conn


def query_ddl(conn:mysqlConn.connect, sql):
    cursor = conn.cursor()
    cursor.execute(sql)