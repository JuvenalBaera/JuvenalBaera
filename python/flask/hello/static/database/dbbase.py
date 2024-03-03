import sqlite3

def conectionDb(dbname:str):
    conn = sqlite3.connect(dbname)
    return conn


def getCursor(conn:sqlite3.Connection):
    return conn.cursor()


def executeQuery(conn:sqlite3.Connection, query:str):
    cursor = getCursor(conn)
    cursor.execute(query)
    conn.commit()


def getDataDb(conn:sqlite3.Connection, query:str):
    cursor = getCursor(conn)
    cursor.execute(query)
    return cursor.fetchall()


def closeConection(conn:sqlite3.Connection):
    conn.close()


if __name__ == "__main__":
    pass