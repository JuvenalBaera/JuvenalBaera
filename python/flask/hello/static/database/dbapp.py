import static.database.dbbase as db
# import dbbase as db # local test
import pprint

DBNAME = "players.db"


def createTablePlayer():
    conn = db.conectionDb(DBNAME)
    query = """
        CREATE TABLE IF NOT EXISTS players(
            id INTEGER NOT NULL,
            name TEXT NOT NULL,
            email TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            sport TEXT,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            last_modified DATETIME DEFAULT CURRENT_TIMESTAMP,
            PRIMARY KEY(id)
        ) 
    """
    db.executeQuery(conn, query)
    db.closeConection(conn)


def getAllPlayers():
    conn = db.conectionDb(DBNAME)
    query = "SELECT * FROM players"
    res = db.getDataDb(conn, query)
    db.closeConection(conn)
    return res 


def getPlayeraByEmail(email:str):
    conn = db.conectionDb(DBNAME)
    cursor = db.getCursor(conn)

    query = f"SELECT * FROM players WHERE email = '{email}'"
    cursor.execute(query)
    res = cursor.fetchone()
    db.closeConection(conn)
    return res


def updatePlayerByEmail(email:str, player:dict):
    conn = db.conectionDb(DBNAME)
    cursor = db.getCursor(conn)

    query = f"UPDATE players SET name=?, email=?, password=?, sport=?, last_modified=CURRENT_TIMESTAMP WHERE email LIKE '{email}'"
    cursor.execute(query, (player["name"], player["email"], player["password"] ,player["sport"]))
    conn.commit()
    db.closeConection(conn)


# def updatePlayerByEmail(email:str, player:dict, query):
#     conn = db.conectionDb(DBNAME)
#     cursor = db.getCursor(conn)

#     #"UPDATE players SET name=?, email=?, sport=?

#     query += f", last_modified=CURRENT_TIMESTAMP WHERE email = '{email}'"
#     cursor.execute(query, (player["name"], player["email"], player["sport"]))
#     conn.commit()
#     db.closeConection(conn)



def insertPlayer(player:dict):
    conn = db.conectionDb(DBNAME)
    query = f"INSERT INTO players (name, email, password, sport) VALUES (?, ?, ?, ?)"
    conn.cursor().execute(query, (player["name"], player["email"], player["password"], player["sport"]))
    conn.commit()
    db.closeConection(conn)



if __name__ == "__main__":
    createTablePlayer()
    players = [
        {
        "name"      : "Juvenal Baera",
        "email"     : "jutembeba@emeal.nttdata.com",
        "password"  : "1234",
        "sport"     : "Futsal"
        },
        {
        "name"  : "Charles Pita",
        "email" : "c.pita@gmail.com",
        "password"  : "1234",
        "sport" : "Basketball"
        },
        {
        "name"  : "Josué Mazembe",
        "email" : "josue.mazembe@hotmail.com",
        "password"  : "1234",
        "sport" : "Football"
        }
    ]

    for player in players:
        insertPlayer(player)

    # updatePlayerByEmail("jutembeba@emeal.nttdata.com", player)
    r = getAllPlayers()
    
    # r = getPlayeraByEmail("jutembeba@emeal.nttdata.com")
    pprint.pprint(r)
    pass