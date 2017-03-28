from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep, time
import random
#from threading import Thread
import json
import os
from multiprocessing import Process

maxdelay = 1 #max delay of thinking for each question
timeout = 650 #timeout if problem

def addlog(log):
	with open("log.txt", 'a') as f:
		f.write(log+'\n')

class Bot:
	driver = ""
	mail = ""
	passwd = ""
	over = 0
	starttime = 0
	chien = 0
	def __init__(self, mail, passwd):
		self.starttime = time()
		self.driver = webdriver.Chrome()
		#self.driver = webdriver.PhantomJS("/phantomjs",service_args=['--ignore-ssl-errors=true', '--ssl-protocol=any'])
		#self.driver.set_window_size(1124, 850)
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
				self.driver.refresh()
				print "timeout wait and get"
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
		addlog(self.mail + ' as connected ')

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

	def getProgession(self):
		self.driver.get("https://global-exam.com/")
		self.wait_and_get('//*[@id="frontend-app"]/nav/div/ul/li[5]/a').click()
		return self.wait_and_get('//*[@id="global"]/section/div/article/div/div[4]/p').text

	def practice(self, page):
		if page == 1:
			self.driver.get('https://global-exam.com/fr/toeic/7/trainings')
			nbrarticle = 9
		self.wait_and_get('//*[@id="Listening"]/article[1]/div/div[1]/div[6]/ul/li[2]/a/i')
		nbr = random.randint(1, nbrarticle)
		try:
			self.get('//*[@id="Listening"]/article['+str(nbr)+']/div/div[1]/div[6]/ul/li[2]/a').click()
		except:
			self.get('//*[@id="Listening"]/article['+str(nbr)+']/div/div[1]/div[6]/ul/li/a').click()
		self.ignore_warning()
		self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[2]/div/div/div/div/button').click()
		rep = []
		for i in range(1, 11):
			self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div[1]/div/label').click()
			rep.append(self.wait_and_get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div[7]/ul/li').text)
			self.driver.execute_script("window.scrollTo(0, "+str(i * 300)+");")
			sleep(0.4)
		self.driver.execute_script("window.scrollTo(0, 0);")
		for j, re in enumerate(rep):
			rep[j] = rep[j].replace('A', '1').replace('B', '2').replace('C', '3').replace('D', '4')
		for i in range(1, 11):
			sleep(random.randint(1, maxdelay))
			print rep[i-1]
			r = random.randint(0, 100)
			if r > 15:
				self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div['+str(int(rep[i-1])+2)+']/label/input').send_keys(Keys.SPACE)
			else:
				self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div['+str(i)+']/div[1]/div[2]/div['+str(random.randint(3,6))+']/label/input').send_keys(Keys.SPACE)

			addlog(self.mail + " as checked one case ")
			print "alive"
		sleep(1)
		self.driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
		self.get('//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[3]/div/div/div/div/a').click()
		for i in range(15):
			try:
				self.driver.switch_to_alert()
				alert.accept()
				break
			except:
				sleep(0.3)
		addlog(self.mail + " as valided one practice")
		self.over = 1

def getUsers():
	with open("comptes", 'r') as f:
		return json.loads(f.read())

def setLogTime(login, logtime):
	users = getUsers()
	i = 0
	for user in users:
		if user['login'] == login:
			users[i]['logtime'] = logtime
			print logtime
		i += 1
	with open('comptes', "w") as f:
		f.write(json.dumps(users))

class MainThread:
	users = []
	bots = []
	procs = []
	def __init__(self):
		l = []
		for i in range(100):
			l.append({'finished':0})
		with open("render.txt", "w") as f:
			f.write(json.dumps(l))

	def is_finished(self, idd):
		with open("render.txt", 'r') as f:
			final = json.loads(f.read())
		finalier = final[idd]['finished']
		if finalier == 0:
			return 0
		final[idd]['finished'] = 0
		with open("render.txt", 'w') as f:
			f.write(json.dumps(final))
		return 1

	def launcher(self, idd):
		self.bots[idd].connect()
		self.bots[idd].practice(1)
		logtime = self.bots[idd].getProgession()
		addlog(self.bots[idd].mail+" as practiced , logtime: "+ logtime)
		setLogTime(self.bots[idd].mail, logtime)
		self.bots[idd].driver.quit()
		while True:
			try:
				with open("render.txt", 'r') as f:
					final = json.loads(f.read())
				final[idd]['finished'] = 1
				with open('render.txt', 'w') as f:
					f.write(json.dumps(final))
				break
			except:
				sleep(1)
				pass

	def startit(self):
		self.users = getUsers()
		for user in self.users:
			self.bots.append(Bot(user['login'], user['mdp']))
		g = 0
		for bot in self.bots:
			self.procs.append(Process(target=self.launcher, args=(g, )))
			g += 1
		for proc in self.procs:
			proc.start()
		while True:
			j = 0
			sleep(3)
			for bot in self.bots:
				if time() - bot.starttime > timeout or self.is_finished(j) == 1:
					print "sandwich"
					self.procs[j].terminate()
					try:
						bot.driver.quit()
					except:
						pass
					user = bot.mail
					mdp = bot.passwd
					self.bots[j] = Bot(self.users[j]['login'], self.users[j]['mdp'])
					self.procs[j] = Process(target=self.launcher, args=(j,))
					sleep(5)
					self.procs[j].start()

				j += 1

t = MainThread()
t.startit()

#enBot()




#test = Zoom('basile.beldame@supdeweb-paris.com', 'basile1996')
#test1 = Zoom('basile.beldame@supdeweb-paris.com', 'basile1996')

#test.start()
#test1.start()


#//*[@id="Listening"]/article[3]/div/div[1]/div[6]/ul/li/a
#//*[@id="Listening"]/article[3]/div/div[1]/div[6]/ul/li/a
#//*[@id="Listening"]/article[9]/div/div[1]/div[6]/ul/li/a

#  //*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[1]/div[1]/div[2]/div[3]/label/input

# login button  //*[@id="frontend-app"]/header/nav[2]/div/ul[3]/li[1]/a

#login form   //*[@id="email"]
#login pass 	//*[@id="password"]

#//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[8]/div[1]/div[2]/div[6]/label/input
#//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[1]/div[1]/div[2]/div[3]/label/input
#//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[1]/div[1]/div[2]/div[4]/label/input


#//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[2]/div[1]/div[2]/div[3]/label/input

#//*[@id="frontend-app"]/div[2]/section[3]/div/div/div/div[2]/div/div/div/form/div[5]/div[1]/div[2]/div[3]/label/input
