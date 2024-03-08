from flask import Flask, render_template, request, send_file
from flask_wtf import FlaskForm
from wtforms import SubmitField, URLField, SelectField
from wtforms.validators import DataRequired
from download import download_audio, download_video

app = Flask(__name__)

app.config["SECRET_KEY"] = "12345"

# Entry form 
class URLFORM(FlaskForm):
    url = URLField("Youtube Url", validators=[DataRequired()], render_kw={"autocomplete":"off"})
    select = SelectField("Select audio or video", choices=[("audio", "audio"), ("video", "video")] ,validators=[DataRequired()])
    submit = SubmitField("Download")


@app.route("/", methods=["GET", "POST"])
def audio():
    url = None
    form = URLFORM()

    # Validate
    if form.validate_on_submit():
        url = form.url.data
        if request.form["select"] == "audio":
            file_path = download_audio(url)
        else:
            file_path = download_video(url)
        if file_path is not None:
            form.url.data = ''
            return send_file(file_path, as_attachment=True)
    return render_template("index.html", form=form)
