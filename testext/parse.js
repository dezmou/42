const req = require('request');

req.post({
	url: 'https://api.intra.42.fr/oauth/token',
	form : {
	  		'grant_type': 'client_credentials',
	  		'client_id': '1f49349789eba190d7caf6c3d689fe1b7cab374ab6e523ec746c7e29c18003d7',
	  		'client_secret': '1015bb6d2ab4dcd6822bff6bc5faf1a21a5e0d764dfded1116d1743de97b384c'
			},
			method: 'POST',
			json: true
	},
	function (e, r, body) {
		parse_api(body["access_token"]);
	});

function parse_api(token){
	req.get({
		url: "https://api.intra.42.fr/v2/campus/1/locations",
		headers : {
		    'Authorization': 'Bearer '+token,
		},
		json : true,
		},
		function(e, r, body){
			for (var i=0 , len = body.length; i<len; i++){
				console.log(body[i]);
			}
		}
	);
}


/*
#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json
import requests

class Tig:
	login = ""
	date = ""
	duration = ""
	staff = ""
	reason = ""
	def __init__(self, login, date, duration, staff, reason):
		self.login = login
		self.date = date
		self.duration = duration
		self.staff = staff
		self.reason = reason

def getToken():
	data = {
	  'grant_type': 'client_credentials',
	  'client_id': '1f49349789eba190d7caf6c3d689fe1b7cab374ab6e523ec746c7e29c18003d7',
	  'client_secret': '1015bb6d2ab4dcd6822bff6bc5faf1a21a5e0d764dfded1116d1743de97b384c'
	}
	r =  requests.post('https://api.intra.42.fr/oauth/token', data=data)
	token = json.loads(r.text)['access_token']
	return token
'''
def get_all_tig():
	final = []
	token = getToken()
	headers = {
	    'Authorization': 'Bearer '+token+'',
	}
	for i in range(1000):
		r = requests.get('https://api.intra.42.fr/v2/community_services?sort=created_at&per_page=100&page='+str(i), headers=headers)
		if r.text == "[]":
			break
		print r.text
		print
		lapin = json.loads(r.text)
		for fardeau in lapin:
			g = requests.get('https://api.intra.42.fr/v2/closes/'+str(fardeau['close']['id']), headers=headers)
			zouze = json.loads(g.text)
			reason = zouze['reason']
			login = zouze['user']['login']
			staff = zouze['closer']['login']
			duration = 0
			date = zouze['created_at']
			for j in range(0, 100):
				try:
					duration += int(zouze['community_services'][j]['duration'])
				except:
					break
			duration /= 3600
			final.append(Tig(login, date, duration, staff, reason))

	return final
'''
def get_all_tig():
	final = []
	token = getToken()
	headers = {
	    'Authorization': 'Bearer '+token+'',
	}
	final = []
	total = 0
	for i in range(18,1000):
		r = requests.get('https://api.intra.42.fr/v2/closes?sort=created_at&per_page=100&page='+str(i), headers=headers)
		if r.text == "[]":
			break
		closes = json.loads(r.text)
		for close in closes:
			if len(close['community_services']) == 0:
				continue
			try:
				reason = close['reason']
				login = close['user']['login']
				closer = close['closer']['login']
				date = close['created_at']
				duration = 0
			except:
				continue
			for j in range(0, 100):
				try:
					duration += int(close['community_services'][j]['duration'])
				except:
					break
			duration /= 3600
			total += 1
			print str(total) + "/ 1872"
			final.append(Tig(login, date, duration, closer, reason))
	return final


tigs = get_all_tig()

final = ""
for tig in tigs:
	final += tig.date + " | "+ tig.login + " | " + tig.reason + " | " + str(tig.duration) + " | " + tig.staff + '\n'

fil = open("lapin.txt", "w")
fil.write(final.encode('utf8'))
fil.close()
*/
