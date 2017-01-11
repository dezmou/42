
import pygame
from pygame.locals import *
from time import sleep
pygame.init()
fenetre = pygame.display.set_mode((470, 473))

fond = pygame.image.load("fond.jpg").convert()

fenetre.blit(fond, (0,0))

pion1 = pygame.image.load("pion1.gif").convert()
pion2 = pygame.image.load("pion2.gif").convert()
pion3 = pygame.image.load("pion3.gif").convert()
pion4 = pygame.image.load("pion4.gif").convert()
pion5 = pygame.image.load("pion5.gif").convert()
view = pygame.image.load("view.gif").convert()
notview = pygame.image.load("notview.gif").convert()

pygame.display.flip()
continuer = 1


def addpion(nbr,x,y):
	if nbr == 1:
		fenetre.blit(pion1,(x*60+4,y*60+1))
	if nbr == 2:
		fenetre.blit(pion2,(x*60+4,y*60+1))
	if nbr == 3:
		fenetre.blit(pion3,(x*60+4,y*60+1))
	if nbr == 4:
		fenetre.blit(pion4,(x*60+4,y*60+1))
	if nbr == 5:
		fenetre.blit(pion5,(x*60+4,y*60+1))
	if nbr == 6:
		fenetre.blit(pion2,(x*60+4,y*60+1))
	if nbr == 7:
		fenetre.blit(view,(x*60,y*60))
	if nbr == 8:
			fenetre.blit(notview,(x*60,y*60))

def vide():
	fenetre.blit(fond, (0,0))
	#pygame.display.flip()


vide();


fil = open("final.txt", "r");
i = 0
vide()
raw_input("end")
temps = 0.1
for map in fil.read().split("+\n"):
	map = map.replace(" ", "")
	print map
	y = 0
	for line in map.split('\n'):
		x = 0
		for char in line:
			if char != "#" and char != "." and char != "*":
				addpion(int(char),x,y)
			if char == "*":
				addpion(7, x, y)
			if char == ".":
				addpion(8, x, y)
			x += 1
		y += 1
	pygame.display.flip()
	i += 1;
	print i
	if i != 2377:
		vide()
	if (temps < 0):
		temps = 0.001
	sleep(temps)
	raw_input("next")
	temps -= 0.0005

while True:
	pass

fil.close()
