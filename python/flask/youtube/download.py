import os
import eyed3
import requests
from pytube import YouTube, exceptions as pt_ex
from urllib import error
from moviepy.editor import AudioFileClip
from datetime import datetime


def download_audio(url_file:str):
    yt = None
    audio_mp3 = None
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
        
        clip = AudioFileClip(audio_mp4)
        audio_mp3 = audio_mp4.replace(".mp4", ".mp3")
        clip.write_audiofile(audio_mp3)

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
    return audio_mp3


def download_video(url_file:str):
    yt = None
    video = None
    try:
        yt = YouTube(url=url_file)
    except error.URLError:
         print("You're not connected to internet")
    except pt_ex.RegexMatchError:
        print(f"Url not found: {url_file}")
    except PermissionError:
        print(f"Permission denied")
    except pt_ex.AgeRestrictedError:
        print("Age restricted")
    except Exception as ex:
        print(ex.__class__)
    else:
        video_strem = yt.streams.get_highest_resolution()
        video = video_strem.download(output_path="./download")
    return video
