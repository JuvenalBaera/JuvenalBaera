from flask import Flask, render_template, request
from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import DataRequired, EqualTo, Length

app = Flask(__name__)

app.config["SECRET_KEY"] = "secret_key_1234"

# Forms
class LoginForm(FlaskForm):
    username = StringField("Username",   validators=[DataRequired()], render_kw={"class": "form-label form-check-label"})
    password = PasswordField("Password", validators=[DataRequired()], render_kw={"class": "form-control form-check-label"})
    submit   = SubmitField("Login",      render_kw={"class": "btn btn-primary"})


@app.route("/", methods=["GET", "POST"])
def login():
    form = LoginForm(request.form)
    if request.method == "POST" and form.validate_on_submit():
        user = {
            "name" : form.username.data,
            "password" : form.password.data
        }
        return render_template("html/home.html", user=user)
    return render_template("html/login.html", form=form)

