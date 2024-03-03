from flask import Flask, render_template

# Create a Flast Instance
app = Flask(__name__)

# Create a route decorator
@app.route("/")
def index():
    first_name = "Juvenal"
    return render_template("index.html", first_name=first_name)


# localhost:5000/user/JB
@app.route("/user/<name>")
def user(name):
    return render_template("user.html", name=name)



# Custom error page

@app.errorhandler(404)
def pageNotFound(e):
    print(e)
    return render_template("error404.html")


@app.errorhandler(500)
def internalError(e):
    return render_template("internalerror.html")
