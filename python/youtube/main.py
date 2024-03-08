import os
import eyed3
import requests
from pytube import YouTube, exceptions as pt_ex
from urllib import error
from moviepy.editor import AudioFileClip
from datetime import datetime


def download_yt(url_file:str):
    yt = None
    try:
        yt = YouTube(url=url_file)
    except error.URLError:
         print("You're not connected to internet")
    except pt_ex.RegexMatchError:
        print(f"Url not found: {url_file}")
    except PermissionError:
        print(f"Permission denied: {audio_stream.title}")
    except Exception as ex:
        print(ex.__class__)
    else:
        audio_stream = yt.streams.filter(only_audio=True).first()
        audio_mp4 = audio_stream.download(output_path="./download")
        
        #print(audio_stream.get_file_path())
        

        clip = AudioFileClip(audio_mp4)
        audio_mp3 = audio_mp4.replace(".mp4", ".mp3")
        clip.write_audiofile(audio_mp3)

        print("Audio path " + audio_mp4)
        print("Audio path " + audio_mp3)

        # cover photo
        cover_url = yt.thumbnail_url
        cover_path = os.path.join(os.path.dirname(audio_mp4), f"cover{datetime.now().microsecond}.jpg")
        
        try:
            # get the file
            with open(cover_path, "wb") as cover_file:
                cover_file.write(requests.get(cover_url).content)
        except Exception as ex:
            print(ex.__class__)
        else:
            audio = eyed3.load(audio_mp3)
            if audio.tag is None:
                audio.initTag()
            audio.tag.images.set(3, open(cover_path, "rb").read(), "image/jpeg")
            audio.tag.save()
        finally:
            if os.path.exists(audio_mp4):
                os.remove(audio_mp4)
            if os.path.exists(cover_path):
                os.remove(cover_path)



yt_urls = [
    "https://youtu.be/WTJSt4wP2ME?si=cYUjJULRE263METG",
    # "https://youtu.be/PsO6ZnUZI0g?si=60WfFOuIQXscyecg",
    # "https://youtu.be/KV2ssT8lzj8?si=SILRR2rjyWx4wOGL",
    # "https://youtu.be/i3YmwBLEFmo?si=J-pdresSA7kUItgd",
    # "https://youtu.be/VxTMKRciWIs?si=QP7dy0DkNepb9M8q",
    # "https://youtu.be/XIw1xDorB_w?si=qPm1GKUS9Um7FMEu",
    # "https://youtu.be/0w-QKzYnVpY?si=yl4Tp5Wu6V6955cQ",
    # "https://youtu.be/gZjDaVYT010?si=W5LSE9ho1i4eHQ2z",
    # "https://youtu.be/omZCg-oFK2Y?si=mxKZ82yGudMh7Oj6",
    # "https://youtu.be/2CSZKpQ0J5s?si=sIY-cy0mJMfqzCxQ",
    # "https://youtu.be/c4Yz9o5UtN8?si=ekdoLieV-Wwa1Wdb",
    # "https://youtu.be/25aDpUpoj4k?si=AWYrtiP15tvVMjWS",
    # "https://youtu.be/tnrAmSV9Ulw?si=QJWAxEZkR82c_4LH",
    # "https://youtu.be/FVeZcM6tBQU?si=96owH8cdPdW9dKqx",
    # "https://youtu.be/fPO76Jlnz6c?si=9PvTf46PQBVqeudO",
    # "https://youtu.be/skn7T_XPQnY?si=2S95V9blZ1OGnpnv",
    # "https://youtu.be/MwpMEbgC7DA?si=HGW39WzA4CPcGStG",
    # "https://youtu.be/1G4isv_Fylg?si=--3BhBqvUkRNaIcT",
    # "https://youtu.be/RBumgq5yVrA?si=LG6CM4ugssmziVD6",
    # "https://youtu.be/LHCob76kigA?si=0bSCJmASIdsyJyYi",
    # "https://youtu.be/ryr75N0nki0?si=142LB3bY-y9F-dMI",
    # "https://youtu.be/2fngvQS_PmQ?si=TXuiUk2XS5N421BH",
    # "https://youtu.be/n4RjJKxsamQ?si=UzwfajP2awpN1VL0"
]

#download_yt("https://youtu.be/ryr75N0nki0?si=142LB3bY-y9F-dMI")

for yt_url in yt_urls:
    # my_thread = threading.Thread(target=download_yt, args=(yt_url,))
    # my_thread.start()
    # # my_thread.join()
    download_yt(yt_url)
