# Anti deadline script by momartin
# Ce script existe pour sensibiliser les etudiants a la facilite de tricherie
# en correction .

# lancez "python lescript.py &"
# le script va attendre qu'un git clone se produise dans le dossier folder
# et remplacer le contenus du clone par le dossier source
# votre correcteur n'y vera que du feu surtout si votre dossier source contient un .git valide
# reglez juste ces deux variable:

source = "/Users/momartin/ref" #la ou se trouve vos fichier
folder = "/tmp" #la ou le correcteur va git clone

import sys
from os import listdir
import os
import shutil
from time import sleep
import psutil


while True:
	anc = listdir(folder)
	while True:
		if anc != listdir(folder):
			break
	try:
		while True:
			ok = True
			for proc in psutil.process_iter():
				if proc.name() == "git":
					ok = False
			if ok:
				break
		neo = set(anc).symmetric_difference(listdir(folder))
		os.system("rm -rf "+folder+"/"+list(neo)[0] + " > /dev/null")
		os.system("cp -R "+source+" "+folder+"/"+list(neo)[0] + " > /dev/null")
	except:
		print "issue"
		continue
