#!/usr/bin/php
<?php
	if ($argc != 2){
		exit(0);
	}
	if ($argv[1] == "mais pourquoi cette demo ?"){
		print_r("Tout simplement pour qu'en feuilletant le sujet\non ne s'apercoive pas de la nature de l'exo\n");
	}
	if ($argv[1] == "mais pourquoi cette chanson ?"){
		print_r("Parce que Kwame a des enfants\n");
	}
	if ($argv[1] == "vraiment ?"){
		if (file_exists("stamp")){
			print_r("Oui il a vraiment des enfants\n");
			exit(0);
		}
		print_r("Nan c'est parce que c'est le premier avril\n");
		file_put_contents("stamp", "pantagruel");
	}
 ?>
