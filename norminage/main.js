//  si erreur:
//  brew install nodejs
// 	npm install walk

var walk = require('walk');
const fs = require("fs");
var files = [];

var walker = walk.walk('.', {followLinks : false});

function sleep(delay) {
    var start = new Date().getTime();
    while (new Date().getTime() < start + delay);
}

function getSize(filename) {
    const stats = fs.statSync(filename)
    const fileSizeInBytes = stats.size
    return fileSizeInBytes
}

walker.on('file' ,function(root, stat, next){
	files.push(root + "/" + stat.name);
	next();
});

walker.on('end', function() {
	var ok;
	files.sort();
	for (var line of files){
		ok = true;
		for(var sp of line.substring(2).split("/"))
			if (sp[0] === "."){
				ok = false;
				break;
			}
		if (ok == false || line.match(/^[^.].*$/))
			continue;
		if ((line.match(/(\.c)$/)) || (line.match(/(\.h)$/))){
				sleep(getSize(line)/45);
				console.log("Norme: "+line);
		}
		else{
			console.log("Norme: "+line);
			console.log("Warning: Not a valid file");
		}
	}
})
