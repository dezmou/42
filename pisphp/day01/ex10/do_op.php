#!/usr/bin/php
<?php
	if ($argc != 4){
		print_r("Incorrect Parameters\n");
		exit(0);
	}
	$argv[1] = preg_replace("# #", "", $argv[1]);
	$argv[2] = preg_replace("# #", "", $argv[2]);
	$argv[3] = preg_replace("# #", "", $argv[3]);
	$argv[1] = preg_replace("#	#", "", $argv[1]);
	$argv[2] = preg_replace("#	#", "", $argv[2]);
	$argv[3] = preg_replace("#	#", "", $argv[3]);
	if ($argv[2] == "+")
		print_r($argv[1]+$argv[3]."\n");
	if ($argv[2] == "-")
		print_r($argv[1]-$argv[3]."\n");
	if ($argv[2] == "*")
		print_r($argv[1]*$argv[3]."\n");
	if ($argv[2] == "/"){
		if ($argv[3] == 0){
			print_r("NON");
			exit(0);
		}
		print_r($argv[1]/$argv[3]."\n");
	}
	if ($argv[2] == "%"){
		if ($argv[3] == 0){
			print_r("NON");
			exit(0);
		}
		print_r($argv[1]%$argv[3]."\n");

	}
?>
