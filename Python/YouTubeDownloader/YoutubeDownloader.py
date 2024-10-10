from pytube import YouTube
import certifi
import ssl

# Ensure the SSL context uses certifi's CA bundle
ssl._create_default_https_context = ssl._create_unverified_context

def download_youtube_video(url):
    try:
        yt = YouTube(url)
        # stream = yt.streams.get_highest_resolution()
        # print(f"Downloading '{yt.title}'...")
        # stream.download()
        # print("Download completed!")

        # Get all video streams
        streams = yt.streams.filter(progressive=True, file_extension='mp4')
        
        # Sort streams by resolution in descending order and get the highest resolution
        highest_resolution_stream = streams.order_by('resolution').desc().first()
        
        print(f"Downloading '{yt.title}' in {highest_resolution_stream.resolution} resolution...")
        
        # Download the video to the current working directory
        highest_resolution_stream.download()
        
        print("Download completed!")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    url = input("Enter the YouTube video URL: ")
    download_youtube_video(url)
