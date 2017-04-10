import sys
from os import listdir
import os
import shutil

source = "/Users/momartin/ref"
folder = "/tmp"

anc = listdir(folder)
while True:
	if anc != listdir(folder):
		break
neo = set(anc).symmetric_difference(listdir(folder))
for root, dirs, files in os.walk(source):
   for file in files:
	  path_file = os.path.join(root,file)
	  shutil.copy2(path_file,folder+"/"+list(neo)[0])
