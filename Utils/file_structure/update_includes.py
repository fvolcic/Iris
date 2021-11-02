import os
import subprocess

def get_files(base_path):
    return [path for path in os.walk(base_path)]

def get_new_header_path(file):
    dirs = get_files("include")

    for dir in dirs:
        if file in dir[2]:
            return (dir[0]+f"/{file}").replace("include/", "")

def fixup_file(file):
    with open(file, 'r') as f:
        for line in f:
            line=line.replace("\n", "")
            if "#include" in line:

                if "<" in line or "BluetoothSerial.h" in line or "SPIFFS.h" in line:
                    print(line)
                else:
                    if get_new_header_path(line.split('"')[1]) == None:
                        print(line)
                        continue
                    print('#include "'+get_new_header_path(line.split('"')[1])+'"')
            else:
                print(line)

import click

@click.command()
@click.argument("fixup")
def main(fixup):
    fixup_file(fixup)

if __name__ == "__main__":
    main()

