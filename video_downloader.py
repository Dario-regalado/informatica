from pytube import YouTube

def download_video_yt(url, path=r'C:\Users\Equipo\Downloads\downloaded_videos'):
  try:
    yt = YouTube(url)
    yt.streams.get_highest_resolution().download(output_path=path)
    print("download complete!")
  except Exception as e:
    print("error ", e)

url_youtube = input("give the url: ")
path = input("give the path (default actual path): ")
download_video_yt(url_youtube, path)