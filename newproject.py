# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    newproject.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 18:30:24 by momartin          #+#    #+#              #
#    Updated: 2017/01/12 18:30:26 by momartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Simple python script for creating new project.
#		It juste copy all the file in the "base" folder and replace all #projet#
#		string in the file content and filenames.

#		By momartin 	incredibledez@gmail.com


import errno
import shutil
import sys
import os

change = "#projet#"

def assign(src,name):
	fil = open(src, "r")
	text = fil.read()
	fil.close()
	text = text.replace(change, name)
	text = text.replace(change.upper(), name.upper())
	if change in src:
		neosrc = src.replace(change, name)
		fil = open(neosrc, "w")
		fil.write(text)
		fil.close()
		os.remove(src)
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


nom = raw_input("Enter name of new project: ")
if nom == "":
	print "nom invalide"
	exit()
copy("base", nom)
for root, directories, filenames in os.walk('./'+nom+'/'):
	for filename in filenames:
		fi = os.path.join(root, filename)
		assign(fi,nom)
