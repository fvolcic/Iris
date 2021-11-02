
import os
import subprocess

def get_files(base_path):
    return [path for path in os.walk(base_path)]

def main():
    for path in get_files("include"):
        for file in path[2]:
            if ".txt" in file:
                continue
            if not ".h" in file:
                continue
            # print(f"running on {path[0]}/{file}" )
            os.system(f"python3 update_includes.py {path[0]}/{file} > tmp.cpp")
            os.system(f"cp tmp.cpp {path[0]}/{file}")
            os.system(f"echo {path[0]}/{file} complete")

if __name__ == "__main__":
    main()