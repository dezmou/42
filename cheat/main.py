import sys
from os import listdir
import os
import shutil
from time import sleep
import psutil

source = "/source"
folder = "/test"

while True:
	anc = listdir(folder)
	while True:
		print "cherche nouveau dossier"
		if anc != listdir(folder):
			break
	try:
		while True:
			ok = True
			print "dossier trouve"
			for proc in psutil.process_iter():
				if proc.name() == "git":
					ok = False
			if ok:
				break
		print "git finis"
		neo = set(anc).symmetric_difference(listdir(folder))
		for root, dirs, files in os.walk(source):
		   for file in files:
			  path_file = os.path.join(root,file)
			  shutil.copy2(path_file,folder+"/"+list(neo)[0])
		break
	except:
		continue
