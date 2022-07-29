import base64
import os
import json
filebasename="kagamine_len"
result={}
# 需要ffmpeg库
# 转换未mp3格式主要为了压缩大小，以免文件过大
order=[0,1,10,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,4,5,6,7,8,9]
for i in order:
    cmd = f"ffmpeg -i {filebasename}_{str(i+1).rjust(2,'0')}.wav {str(i)}.mp3"
    os.system(cmd)
    with open(f'{str(i)}.mp3', 'rb') as file_obj:
        mp3_data = file_obj.read()
        base64_data = base64.b64encode(mp3_data).decode("utf-8")
        result[f'{str(i)}.mp3']=f"data:audio/mp3;base64,{base64_data}"
open(f"{filebasename}.json", "w").write(json.dumps(result))