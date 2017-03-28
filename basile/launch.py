import subprocess
import os
from time import sleep
proc = subprocess.Popen(['python', './main.py'])
sleep(5)
proc.kill()
os.system("killall chromedriver")
