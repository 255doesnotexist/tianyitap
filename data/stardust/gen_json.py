import base64
import os

json = "{"
for i in range(0, 32):
    cmd = "ffmpeg -i " + str(i) +"_MixDown.wav " + str(i) + ".mp3"
    os.system(cmd)
    with open(str(i) + ".mp3", 'rb') as fileObj:
        mp3_data = fileObj.read()
        base64_data = base64.b64encode(mp3_data).decode("utf-8")
        json += "\"" + str(i) + ".mp3\":\"data:audio/mp3;base64," + base64_data + "\""
        if i != 31:
            json += ","

json += "}"
open("stardust.json", "w").write(json)