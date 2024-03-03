from flask import Flask, render_template, request
import static.database.dbapp as db
import sqlite3

app = Flask(__name__)
DESPORTOS = ["Futebol", "Basquetebol", "Voleibol", "Futsal"]


def insertToDb(player:dict):
    try:
        db.insertPlayer(player)
    except sqlite3.OperationalError:
        print("Player already exist")
    except Exception as ex:
        print(ex.__class__)


def userExist(email):
    res = None
    try:
        res = db.getPlayeraByEmail(email)
    except Exception as ex:
        # print(ex)
        return False
    else:
        if res == None:
            return False
        return True


@app.route("/", methods=["GET", "POST"])
@app.route("/login", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("./html/login.html")
    email = request.form.get("email", None)
    password = request.form.get("password", None)

    if email == None or password == None:
        return render_template("./html/login.html")
    
    if userExist(email) == False:
        return render_template("./html/login.html")
    
        



@app.route("/registo", methods=["GET", "POST"])
def registo():
    if request.method == "GET":
        return render_template("html/registo.html", desportos=DESPORTOS)
    
    name = request.form.get("nome", None)
    email = request.form.get("email", None)
    sport = request.form.get("desporto", None)
    password = request.form.get("password", None)
    password_rep = request.form.get("password_rep", None)

    if name == None or email == None or sport not in DESPORTOS:
        return render_template("html/registo.html", desportos=DESPORTOS)

    if password != password_rep:
        return render_template("html/registo.html", desportos=DESPORTOS, error="Password devem ser mesmas")

    # check if the player is already in database

    if userExist(email):
        return render_template("./html/registo.html", desportos=DESPORTOS, error="Usuário existente")

    player = {
        "name"    : name,
        "email"   : email,
        "password": password,
        "sport"   : sport
    }

    insertToDb(player)
    
    return render_template("./html/home.html", user=name)

