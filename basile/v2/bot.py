from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from time import sleep, time
import random
#from threading import Thread
import json
import os
#from multiprocessing import Process

def get_json_file(fi):
	with open(fi, "r") as f:
		return json.loads(f.read())

maxdelay = 1

class Bot:
	driver = ""
	mail = ""
	passwd = ""
	over = 0
	starttime = 0
	chien = 0
	skill = 80
	def __init__(self, mail, passwd):
		self.starttime = time()
		#self.driver = webdriver.Chrome()
		self.driver = webdriver.PhantomJS("/phantomjs", service_args=['--ignore-ssl-errors=true', '--ssl-protocol=any'])
		self.driver.set_window_size(1124, 850)
		self.mail = mail
		self.passwd = passwd
		self.over = 0
	def wait_and_get(self, xpath):
		i = 0
		while True:
			try:
				return self.driver.find_element_by_xpath(xpath)
				break
			except:
				sleep(0.4)
				pass
			i += 1
			if i > 70:
				self.driver.quit()
				exit()
				i = 0
	def get(self, xpath):
		return self.driver.find_element_by_xpath(xpath)

	def connect(self):
		self.chien = 1
		self.over = 1
		self.driver.get('https://global-exam.com/fr')
		self.wait_and_get('//*[@id="frontend-app"]/header/nav[2]/div/ul[3]/li[1]/a').click()
		self.wait_and_get('//*[@id="email"]').send_keys(self.mail)
		self.get('//*[@id="password"]').send_keys(self.passwd)
		self.get('//*[@id="frontend-app"]/section/div/div/div/div/div/form/div[5]/button').click()
		self.wait_and_get('//*[@id="Listening"]/article[1]/div/div[2]/div[2]/div/ul/li[3]/a')

	def ignore_warning(self):
		while True:
			sleep(0.5)
			try:
				self.get('//*[@id="frontend-app"]/div[6]/div[7]/button').click()
				break
			except:
				try:
					self.get('//*[@id="frontend-app"]/div[2]/section[2]/div/div/div/div/button')
					break
				except:
					pass

	def go_to_type(self,nbr):
		self.driver.get('https://global-exam.com/fr')
		sel = Select(self.wait_and_get('//*[@id="exercises"]'))
		sel.select_by_index(nbr-1)

	def get_rendu(self, skill):#always after a go_to_type
		self.wait_and_get('//*[@id="Listening"]/article[1]/div/div[1]/div[5]/span')
		for i in range(100):
			try:
				res = self.get('//*[@id="Listening"]/article['+str(i+1)+']/div/div[1]/div[5]/span').text
				res = res.replace("%", "")
				if "-" in res:
					return i+1
				elif int(res) <= skill:
					return i+1
			except:
				return -1
				break
	def get_to_practice(self, nbrtype ,nbr):
		nbr = 12
		links = get_json_file("links.json")["types"]
		li = links[nbrtype-1][nbr-1]
		self.driver.get(li)

	def deploy(self, nbr, type):
		nbr_reps = 4
		if type == 1 or type == 3 or type == 4:
			nbr_rep = 4
		if type == 2:
			nbr_rep = 3
		reps = []
		for i in range(1, nbr+1):
			print i
			self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div[1]/div/label').click()
			letter =  self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div['+str(nbr_rep+3)+']').text[21]
			reps.append(letter)
			self.driver.execute_script("window.scrollTo(0, "+str(i * 300)+");")
			sleep(0.4)
		return reps

	def coche(self, nbrdeploy, rep):
		self.driver.execute_script("window.scrollTo(0, 0);")
		for i in range(1, nbrdeploy+1):
			sleep(random.randint(1, maxdelay))
			r = random.randint(0, 100)
			if r > 100-int(self.skill):
				self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div['+str(int(rep[i-1])+2)+']/label/input').send_keys(Keys.SPACE)
			else:
				self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div['+str(random.randint(3,6))+']/label/input').send_keys(Keys.SPACE)
			print "coche"
			self.driver.execute_script("window.scrollTo(0, "+str(i * 300)+");")

	def practice(self, type):
		if type == 1:
			nbrdeploy = 10
			maxdelay = 1
		if type == 2:
			maxdelay = 1
			nbrdeploy = 5
		if type == 3 or type == 4:
			maxdelay = 1
			nbrdeploy = 3
		self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[2]/div/div/div/div/button').click()
		if type == 3 or type == 4:
			for i in range(9):
				reps = self.deploy(nbrdeploy, type)
				for j, re in enumerate(reps):
					reps[j] = reps[j].replace('A', '1').replace('B', '2').replace('C', '3').replace('D', '4')
				self.coche(nbrdeploy,  reps)
				self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[3]/div/div/div/div/a').click()
				sleep(1)
				self.driver.execute_script("window.scrollTo(0, 0);")

		else:
			reps = self.deploy(nbrdeploy, type)
			for j, re in enumerate(reps):
				reps[j] = reps[j].replace('A', '1').replace('B', '2').replace('C', '3').replace('D', '4')
			self.coche(nbrdeploy,  reps)
		sleep(1000)

	def is_legit(self):
		self.driver.get('https://global-exam.com/fr')
		self.wait_and_get('//*[@id="frontend-app"]/header/nav[2]/div/ul[3]/li[1]/a').click()
		self.wait_and_get('//*[@id="email"]').send_keys(self.mail)
		self.get('//*[@id="password"]').send_keys(self.passwd)
		self.get('//*[@id="frontend-app"]/section/div/div/div/div/div/form/div[5]/button').click()
		for i in range(100)
			try:
				self.get('//*[@id="Listening"]/article[1]/div/div[2]/div[2]/div/ul/li[3]/a')
				return True
			except:
				pass
			try:
				self.get('//*[@id="email"]')
				return False
			except:
				pass
			sleep(0.4)
		return False
