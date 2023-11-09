# Get Verify code

import requests

url = "https://irs.thsrc.com.tw/IMINT/captImg/kJvFeaAYza.jpg"
path = "圖片1.jpg"
print("Requesting")
res = requests.get(url, stream=True)
print("Success")
if res.status_code == 200:
    print("Getting")
    with open(path, "wb") as file_path:
        for chunck in res:
            file_path.write(chunck)
    print("The Image has been downloaded")
else:
    print("Error!! HTTP Request failed")
