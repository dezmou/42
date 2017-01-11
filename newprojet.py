#PYTHON script for creating new C project with basic

import errno
import shutil
import sys
import os

def assign(src,name):
	fil = open(src, "r")
	text = fil.read()
	fil.close()
	text = text.replace("###projet", name)
	text = text.replace("###PROJET", name)
	if "projet.h" in src:
		src = src.replace("projet.h", name+".h")
		fil = open(src, "w")
		fil.write(text)
		fil.close()
		os.remove(name+"/srcs/projet.h")
	else:
		fil = open(src, "w")
		fil.write(text)
		fil.close()

def copy(src, dest):
    try:
        shutil.copytree(src, dest)
    except OSError as e:
        if e.errno == errno.ENOTDIR:
            shutil.copy(src, dest)
        else:
            print('Directory not copied. Error: %s' % e)
try:
	nom = sys.argv[1]
except:
	print "usage: neofile"

copy("base", nom)
assign(nom+"/srcs/projet.h",nom)
assign(nom+"/srcs/main.c",nom)
assign(nom+"/srcs/init.c",nom)
assign(nom+"/Makefile",nom)
