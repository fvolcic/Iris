import os

os.system("rm -r include")
os.system("mkdir include")
os.system("find headers -type f -exec cp {} include \;")
os.system("find headers -type d -exec cp -r {} include \;")
os.system("echo Pre Compilation Steps Complete")