import struct
import operator
import sys, getopt
import Quartz.CoreGraphics as CG
import pygame
from pygame.locals import *
from Quartz.CoreGraphics import CGEventCreateMouseEvent
from Quartz.CoreGraphics import CGEventPost
from Quartz.CoreGraphics import kCGEventMouseMoved
from Quartz.CoreGraphics import kCGEventLeftMouseDown
from Quartz.CoreGraphics import kCGEventLeftMouseDown
from Quartz.CoreGraphics import kCGEventLeftMouseUp
from Quartz.CoreGraphics import kCGMouseButtonLeft
from Quartz.CoreGraphics import kCGHIDEventTap
import json
from time import sleep
import pyautogui
pygame.init()




fen = pygame.display.set_mode((800,500))

fond = pygame.image.load("fond.png").convert()
ic1 = pygame.image.load("1.png").convert()
ic3 = pygame.image.load("3.png").convert()
ic4 = pygame.image.load("4.png").convert()
ic5 = pygame.image.load("5.png").convert()
ic6 = pygame.image.load("6.png").convert()
ic7 = pygame.image.load("7.png").convert()
front = pygame.image.load("back.png").convert_alpha()
neutral = pygame.image.load("neutral.png").convert()
fen.blit(fond, (0,0))



def mouseEvent(type, posx, posy):
        theEvent = CGEventCreateMouseEvent(
                    None, 
                    type, 
                    (posx,posy), 
                    kCGMouseButtonLeft)
        CGEventPost(kCGHIDEventTap, theEvent)

def mousemove(posx,posy):
        mouseEvent(kCGEventMouseMoved, posx,posy);

def mouseclick(posx,posy):
        mouseEvent(kCGEventMouseMoved, posx,posy);
        mouseEvent(kCGEventLeftMouseDown, posx,posy);
        mouseEvent(kCGEventLeftMouseDown, posx,posy);
        mouseEvent(kCGEventLeftMouseDown, posx,posy);
        sleep(0.1)
        mouseEvent(kCGEventLeftMouseUp, posx,posy);
        mouseEvent(kCGEventLeftMouseUp, posx,posy);
       	mouseEvent(kCGEventLeftMouseUp, posx,posy);


class ScreenPixel(object):

	def capture(self,x, y):
		region = CG.CGRectMake(x, y, 1, 1)
		image = CG.CGWindowListCreateImage(
			region,
			CG.kCGWindowListOptionOnScreenOnly,
			CG.kCGNullWindowID,
			CG.kCGWindowImageDefault)
		prov = CG.CGImageGetDataProvider(image)
		self._data = CG.CGDataProviderCopyData(prov)
		self.width = CG.CGImageGetWidth(image)
		self.height = CG.CGImageGetHeight(image)
 
	def pixel(self, x, y):
		data_format = "BBBB"
		b, g, r, a = struct.unpack_from(data_format, self._data, offset=0)
		return (r, g, b)

class Tracker:
	table_pos = ""
	cards = ""
	t = ""
	ref_cards_r = ""
	ref_cards_b = ""
	lost_cards = []
	op_cards = []
	refused_op_cards = []
	new = ""
	def __init__(self):
		self.loads_cards()
		self.t = ScreenPixel()
		self.get_table_pos()
		self.play()
		pass
	def click_card(self,x,y):
		
		x += -1
		y += -1
		x = x * 32 + 123
		y = y * 37 + 322
		mouseclick(688, 37)
		sleep(0.2)
		mouseclick(x + self.table_pos[0], y + self.table_pos[1])
		sleep(0.2)

	def take_or_not(self):
		#res = raw_input("take ? [y-n] $>")
		while True:
			ev = pygame.event.wait()
			if ev.type == 6:
				if ev.button == 2:
					res = "y"
					break
				if ev.button == 3:
					res = "n"
					break
		pos = pyautogui.position()
		if res == "y":
			mouseclick(688, 37)
			sleep(0.2)
			mouseclick(self.table_pos[0] +54, self.table_pos[1] + 185)
			sleep(0.2)
			#mouseclick(2312, 30)
			pyautogui.click(x=pos[0], y=pos[1])
			return True
		else:
			mouseclick(688, 37)
			sleep(0.2)
			mouseclick(self.table_pos[0] + 647, self.table_pos[1] + 216)
			sleep(0.2)
			#mouseclick(2312, 30)
			pyautogui.click(x=pos[0], y=pos[1])
			return False

	def action(self):
		#move = raw_input("your move [x y] $>")
		#move = move.replace("j", "11").replace("q", "12").replace("k", "13").replace("t", "10")
		#move = move.replace("J", "11").replace("Q", "12").replace("K", "13").replace("T", "10")
		#move = move.split(" ")
		while True:
			ev = pygame.event.wait()
			if ev.type == 6:
				if ev.button == 1:
					x = ev.pos[0]
					y = ev.pos[1]
					break		
		
		x = x / 60 + 1
		y = y / 125 + 1
		pos = pyautogui.position()
		self.click_card(x, y)
		pyautogui.click(x=pos[0], y=pos[1])
		return [str(x), str(y)]

	def get_which_new_cards(self, anc):
		for y in range(4):
			for x in range(13):
				if self.cards[y][x] == 1 or self.cards[y][x] == 6:
					if anc[y][x] != self.cards[y][x]:
						self.new = [x,y]
						return

	def play(self):
		while True:
			self.get_all_cards_pos()
			actc =  self.get_card()
			self.cards[actc[1]][actc[0]-1] = 3
			self.printit()
			self.maj_gui()
			if not self.take_or_not():
				self.lost_cards.append(actc)
			else:
				self.refused_op_cards.append(actc)
			anc = self.cards
			self.get_all_cards_pos()
			self.get_which_new_cards(anc)
			self.cards[ self.new[1] ][ self.new[0] ] = 7
			self.printit()
			self.maj_gui()
			self.cards[ self.new[1] ][ self.new[0] ] = 1
			move = self.action()
			self.cards[int(move[1]) - 1][int(move[0]) - 1] = 4
			self.printit()
			self.maj_gui()
			move[1] = str(int(move[1])-1)
			res = self.op_loop()
			if res:
				self.op_cards.append(move)
			else:
				self.lost_cards.append(move)

	def loads_cards(self):
		self.ref_cards_r = []
		for i in range(1, 14):
			with open("cards/"+str(i)+"r", "r") as f:
				self.ref_cards_r.append(json.loads(f.read()))
		self.ref_cards_b = []
		for i in range(1, 14):
			with open("cards/"+str(i)+"b", "r") as f:
				self.ref_cards_b.append(json.loads(f.read()))

	def find_color(self, r,g,b):
		for y in range(153, 160):
			for  x in range(19, 36):
				px = self.get_pixel(x, y)
				if px == (40, 120, 64):
					print "ok"
					return (x,y)
	
	def get_pixel(self,x,y):
		self.t.capture(x, y)
		return self.t.pixel(x, y)

	def get_table_pos(self):
		self.table_pos = self.find_color(40, 120, 64)
		print "Ready"
	
	def get_all_cards_pos(self):
		actx = 119
		acty = 319
		corner = (182, 209, 190)
		self.cards = []
		for y in range(4):
			zouze = []
			if y == 3:
				corner = (161, 196, 171)
			for x in range(13):
				px = self.get_pixel(actx + self.table_pos[0], acty + self.table_pos[1])
				actx += 32
				if  px == corner:
					zouze.append(1)
				else:
					zouze.append(2)
			actx = 119
			acty += 37
			self.cards.append(zouze)
		for ca in self.op_cards:
			self.cards[int(ca[1])][int(ca[0])-1] = 5
		for ca in self.refused_op_cards:
			self.cards[int(ca[1])][int(ca[0])-1] = 6
		for ca in self.lost_cards:
			self.cards[int(ca[1])][int(ca[0])-1] = 4


	def maj_gui(self):
		fen.blit(fond, (0,0))	
		for y in range(4):
			for x in range(13):
				if self.cards[y][x] == 1:
					fen.blit(ic1, (x * 60 , y * 125 ))
				elif self.cards[y][x] == 6:
					fen.blit(ic4, (x * 60 , y * 125 ))
				elif self.cards[y][x] == 3:
					fen.blit(ic3, (x * 60 , y * 125 ))
				elif self.cards[y][x] == 4:
					fen.blit(ic6, (x * 60 , y * 125 ))
				elif self.cards[y][x] == 5:
					fen.blit(ic5, (x * 60 , y * 125 ))
				elif self.cards[y][x] == 7:
					fen.blit(ic7, (x * 60 , y * 125 ))
		fen.blit(front,(0,0))
		for y in range(4):
			for x in range(13):
				if self.cards[y][x] == 2:
					fen.blit(neutral, (x * 60, y * 125))
		pygame.display.flip()

	def printit(self):
		final = '\033[0m'
		final += "   1 2 3 4 5 6 7 8 9 T J Q K\n"
		final += "   -------------------------\n"
		for y in range(4):
			final += '\033[0m'
			final += str(y + 1) + "| "
			for x in range(13):
				if self.cards[y][x] == 1:
					final += '\033[92m'
					final += "X "	
				if self.cards[y][x] == 6:
					final += '\033[92m'
					final += "0 "	
				elif self.cards[y][x] == 2:
					final += '\033[94m'
					final += ". "
				elif self.cards[y][x] == 3:
					final += '\033[95m'
					final += "# "
				elif self.cards[y][x] == 4:
					final += '\033[0m'
					final += "0 "
				elif self.cards[y][x] == 5:
					final += '\033[91m'
					final += "$ "
				elif self.cards[y][x] == 7:
					final += '\033[95m'
					final += "X "	
			final += "\n"
		print final

	def get_symbole(self):
		px = self.get_pixel(61 + self.table_pos[0], 214 + self.table_pos[1])
		if px == (209, 40, 24):#red
			px = self.get_pixel(76 + self.table_pos[0], 204 + self.table_pos[1])
			if px == (209, 40, 24):
				return 0
			return 2
		elif px == (17, 17, 17):
			px = self.get_pixel(68 + self.table_pos[0], 200 + self.table_pos[1])
			if px == (17, 17, 17):
				return 1
			return 3

	def get_card_print(self):
		arr = []
		y = 174
		for iy in range(12):
			x = 25
			for ix in range(10):
				arr.append(list(self.get_pixel(x + self.table_pos[0], y + self.table_pos[1])))
				x += 2
			y += 2
		return arr

	def op_loop(self):
		took = False
		symb = self.get_symbole()
		pr = self.get_card_print()
		while self.get_pixel(260 + self.table_pos[0], 47 + self.table_pos[1]) != (255, 255, 255):
			pass
		symb2 = self.get_symbole()
		if symb2 != symb:
			took = True
		if not took:
			pr2 = self.get_card_print()
			if pr != pr2:
				took = True
		while self.get_pixel(357 + self.table_pos[0], 136 + self.table_pos[1]) == (255, 255, 255):
			pass
		return took

	def get_card(self):
		symb = self.get_symbole()
		ar = self.get_card_print()
		if symb == 0 or symb == 2:
			i = 1
			for c in self.ref_cards_r:
				if ar == c:
					return [i, symb]
				i += 1
		else:
			i = 1
			for c in self.ref_cards_b:
				if ar == c:
					return [i, symb]
				i += 1

	def save_chien(self, name):
		ar = self.get_card_print()
		with open("cards/"+name, "w") as f:
			f.write(json.dumps(ar))

tr = Tracker()
