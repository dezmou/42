import struct
import operator
import sys, getopt
import Quartz.CoreGraphics as CG
from Quartz.CoreGraphics import CGEventCreateMouseEvent
from Quartz.CoreGraphics import CGEventPost
from Quartz.CoreGraphics import kCGEventMouseMoved
from Quartz.CoreGraphics import kCGEventLeftMouseDown
from Quartz.CoreGraphics import kCGEventLeftMouseDown
from Quartz.CoreGraphics import kCGEventLeftMouseUp
from Quartz.CoreGraphics import kCGMouseButtonLeft
from Quartz.CoreGraphics import kCGHIDEventTap
import json


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
        #mouseEvent(kCGEventMouseMoved, posx,posy);
        mouseEvent(kCGEventLeftMouseDown, posx,posy);
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
	def __init__(self):
		self.loads_cards()
		self.t = ScreenPixel()
		self.get_table_pos()
		self.play()
	

	def play(self):
		self.get_all_cards_pos()
		print self.get_card()
		self.printit()

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
		for y in range(151, 400):
			for  x in range(121, 400):
				px = self.get_pixel(x, y)
				if px == (40, 120, 64):
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

	def printit(self):
		final = ""
		for y in range(4):
			for x in range(13):
				if self.cards[y][x] == 1:
					final += "X "	
				else:
					final += ". "
			final += "\n"
		print final

	def get_symbole(self):
		px = self.get_pixel(61 + self.table_pos[0], 214 + self.table_pos[1])
		if px == (209, 40, 24):#red
			px = self.get_pixel(76 + self.table_pos[0], 204 + self.table_pos[1])
			if px == (209, 40, 24):
				return "coeur"
			return "carreau"
		elif px == (17, 17, 17):
			px = self.get_pixel(68 + self.table_pos[0], 200 + self.table_pos[1])
			if px == (17, 17, 17):
				return "trefle"
			return "pique"


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
		pr2 = self.get_card_print()
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
		if symb == "coeur" or symb == "carreau":
			i = 1
			for c in self.ref_cards_r:
				if ar == c:
					return (i, symb)
				i += 1
		else:
			i = 1
			for c in self.ref_cards_b:
				if ar == c:
					return (i, symb)
				i += 1

	def save_chien(self, name):
		ar = self.get_card_print()
		with open("cards/"+name, "w") as f:
			f.write(json.dumps(ar))

tr = Tracker()




'''



 xstart 119
 ystart 319 

ecart y 37 
ecart x 32

247 279

corner carte du bas 161 196 171

119
393
----
183
319
----
209
393
----
247
319
----
279
356
----
279
393
----
337
319
----
369
356
----
369
393
----
375
319
----
375
356
----
375
393
----
391
129
----
391
136
----
465
319
----
465
356
----
465
393
----
503
319
----
593
319

'''
#green back 287840 40 120 64
#carde corner 182 209 190