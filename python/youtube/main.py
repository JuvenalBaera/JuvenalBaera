import os
from pytube import YouTube
from moviepy.editor import AudioFileClip
import threading


def download_yt(url_file:str):
    try:
        yt = YouTube(url=url_file)
        audio_stream = yt.streams.filter(only_audio=True).first()

        # path to download
        download_path = "./download"

        audio_mp4 = audio_stream.download(output_path=download_path)

        clip = AudioFileClip(audio_mp4)
        audio_mp3 = audio_mp4.replace(".mp4", ".mp3")
        clip.write_audiofile(audio_mp3)
        
        if os.path.exists(audio_mp4):
            os.remove(audio_mp4)
    except Exception as ex:
        print(ex.__class__)


yt_urls = [
    "https://youtu.be/WTJSt4wP2ME?si=cYUjJULRE263METG",
    "https://youtu.be/PsO6ZnUZI0g?si=60WfFOuIQXscyecg",
    "https://youtu.be/KV2ssT8lzj8?si=SILRR2rjyWx4wOGL",
    "https://youtu.be/i3YmwBLEFmo?si=J-pdresSA7kUItgd",
    "https://youtu.be/VxTMKRciWIs?si=QP7dy0DkNepb9M8q",
    "https://youtu.be/XIw1xDorB_w?si=qPm1GKUS9Um7FMEu",
    "https://youtu.be/0w-QKzYnVpY?si=yl4Tp5Wu6V6955cQ",
    "https://youtu.be/gZjDaVYT010?si=W5LSE9ho1i4eHQ2z",
    "https://youtu.be/omZCg-oFK2Y?si=mxKZ82yGudMh7Oj6",
    "https://youtu.be/2CSZKpQ0J5s?si=sIY-cy0mJMfqzCxQ",
    "https://youtu.be/c4Yz9o5UtN8?si=ekdoLieV-Wwa1Wdb",
    "https://youtu.be/25aDpUpoj4k?si=AWYrtiP15tvVMjWS",
    "https://youtu.be/tnrAmSV9Ulw?si=QJWAxEZkR82c_4LH"
]


for yt_url in yt_urls:
    my_thread = threading.Thread(target=download_yt, args=(yt_url,))
    my_thread.start()
    download_yt(yt_url)
