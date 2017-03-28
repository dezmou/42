import json
from bot import Bot

def get_json_file(fi):
	with open(fi, "r") as f:
		return json.loads(f.read())

def set_json_file(fi):
	pass

links = get_json_file("links.json")["types"]
pls = get_json_file("players.json")
act = pls["players"][0]

bot = Bot(act["mail"], act["mdp"])
bot.skill = act['skill']
bot.connect()
bot.go_to_type(act["offer"])
rendu = bot.get_rendu(act['skill'])
if rendu == -1:
	print "Plus de training disponible pour cette offre"
	bot.driver.quit()
	exit()#set json file
bot.get_to_practice(act["offer"], rendu)
bot.practice(act["offer"])
bot.driver.quit()
