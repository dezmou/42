import pyscreenshot as ImageGrab


class Tracker:
	table_pos = ""
	cards = ""

	def __init__(self):
		self.get_table_pos()
		self.get_all_cards_pos()
	def find_color(self, r,g,b):
	    image = ImageGrab.grab()
	    for x in range(1, 2000):
	        for y in range(1,1000):
	            px = image.getpixel((x, y))
	            if px[0] == r and px[1] == g and px[2] == b:
	                return(x,y)

	def get_table_pos(self):
		self.table_pos = self.find_color(40, 120, 64)

	def get_all_cards_pos(self):
		chien = raw_input("continue")
		image = ImageGrab.grab(bbox=(self.table_pos[0], self.table_pos[1], 700, 600))		
		actx = 119
		acty = 319
		corner = (182, 209, 190)
		self.cards = []
		for y in range(4):
			zouze = []
			if y == 3:
				corner = (161, 196, 171)
			for x in range(13):
				px = image.getpixel((actx,acty))
				actx += 32
				if  px == corner:
					zouze.append(True)
				else:
					zouze.append(False)
			actx = 119
			acty += 37
			self.cards.append(zouze)

	def printit(self):
		final = ""
		for y in range(4):
			for x in range(13):
				if self.cards[y][x]:
					final += "X "
				else:
					final += "O "
			final += "\n"
		print final
tr = Tracker()
tr.printit()
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