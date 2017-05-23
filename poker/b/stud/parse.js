const req = require('request');
const jsonfile = require('jsonfile');
var final = [];
var fi = [];
var g_token;
var neo = [];
main();
function log(content){
	console.log(content);
}
function main(){
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
			g_token = body["access_token"];
			parse_api(body["access_token"], 0);
		}
	);
}
function parse_api(token, index){
	req.get({
		url: "https://api.intra.42.fr/v2/campus/1/locations?sort=-end_at&per_page=100&page="+index,
		headers : {
		    'Authorization': 'Bearer '+token,
		},
		json : true,
		},
		function(e, r, body){
			for (var j=0 , len = body.length; j<len; j++){
				if (body[j]["end_at"] == null){
					if (body[j]["host"].search("vp") == -1 && body[j]["host"].search("dump") == -1)
						final.push(body[j]);
				}
				else{
					workon_();
					return;
				}
			}
			parse_api(token, index + 1);
		}
	);
}

function is_deja_vu(ar,user){
	for (var j=0 , len = ar.length; j<len; j++){
		if (ar[j]["user"]["login"] == user["user"]["login"]){
			return user["project"];
		}
	}
	return false;
}
function workon_(){
	neo = [];
	var nouveau = false;
	jsonfile.readFile("users.json", function(err, anc){
		if (typeof anc == 'undefined'){
			jsonfile.writeFile("users.json", final ,null);
			anc = final.slice(0);
			nouveau = true;
		}
		for (var j=0 , len = final.length-1; j<len; j++){
			final[j]["viewed"] = 0;
			if (is_deja_vu(anc,final[j]) != false && nouveau == false){
				final[j]["project"] = is_deja_vu(anc, final[j]);
				final[j]["viewed"] = 1;
			}
			neo.push(final[j]);

		}
		get_projects(0);
	});
}
function get_projects(index){
	if (typeof neo[index] == "undefined"){
		save_it();
		return;
	}
	if(neo[index]["viewed"] == 0){
		req.get({
			url: "https://api.intra.42.fr//v2/users/"+final[index]["user"]["id"]+"/projects_users?per_page=100",
			headers : {'Authorization': 'Bearer '+g_token},
			json: true,
		},function(e,r,body){
			log(e);
			neo[index]["project"] = body;
			neo[index]['viewed'] = 1;
			get_projects(index + 1);
			return ;
		});
	}
	else {
		get_projects(index + 1);
	}
}
function save_it(){
	fi = [];
	var actpro = [];
	jsonfile.writeFile("users.json",neo, function(err){
		for (var j=0 , len = neo.length-1; j<len; j++){
			actpro = [];

			if (typeof neo[j]["project"] != "undefined"){
				for (var c=0 , len = neo[j]["project"].length-1; c<len; c++){
					actpro.push({
						"name" : neo[j]["project"][c]["project"]["name"],
						"status" : neo[j]["project"][c]["status"],
						"grade" : neo[j]["project"][c]["final_mark"]
					});
				}
			}

			fi.push({
				"loc": neo[j]["host"],
				"login": neo[j]["user"]["login"],
				"projects": actpro,
			});
		}
		log("size "+fi.length);
		jsonfile.writeFile("/var/www/html/stud/index.html", fi, null);
	});
}

/*
function is_deja_vu(ar,user){
	for (var j=0 , len = ar.length; j<len; j++){
		if (ar[j]["user"]["login"] == user["login"])
			return true;
	}
	return false;
}

function getProjects(index, anc){
	if (index >= final.length-1){
		write_final();
		return ;
	}
	if (is_deja_vu(anc, final[index]["user"]) == true){
		neo.push(final[index]);
		getProjects(index+1, anc);
		return
	}
	else{
		req.get({
			url: "https://api.intra.42.fr//v2/users/"+final[index]["user"]["id"]+"/projects_users?per_page=100",
			headers : {'Authorization': 'Bearer '+g_token},
			json: true,
		},function(e,r,body){
			final[index]["project"] = body;
			neo.push(final[index]);
			getProjects(index + 1, anc);
		});
	}
}

function workon(){
	neo = [];
	jsonfile.readFile("users.json", function(err, anc){
		getProjects(0, anc);
	});
}
function write_final(){
	jsonfile.writeFile("users.json", null);
}
*/
