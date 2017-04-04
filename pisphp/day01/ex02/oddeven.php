#!/usr/bin/php
<?php
while (1){
	echo("Entrez un nombre: ");
	$fd = fopen("php://stdin","r");
	$line = fgets($fd);
	if ($line == NULL){
		echo("\n");
		exit(0);
	}
	$line = str_replace("\n","",$line );
	if (!is_numeric($line)){
		echo("'".$line."' n'est pas un chiffre\n");
		continue;
	}
	if ($line % 2 == 0){
		echo("Le chiffre ".$line." est Pair\n");
	}
	else{
		echo("Le chiffre ".$line." est Impair\n");
	}
}
 ?>
