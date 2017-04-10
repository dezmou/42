#!/usr/bin/php
<?php
function loupe($ar){
	if (sizeof($ar) != 2)
		exit(0);
	$chien = file_get_contents($ar[1]);
	$neo = preg_replace_callback("#<a(.*?)</a>#s", function($matches){
		return preg_replace_callback("#title=\"(.*?)\"#s", function($ma){
			return str_replace("TITLE", "title", strtoupper($ma[0]));
		},$matches[0]);
	},$chien);
	$neo = preg_replace_callback("#<a(.*?)</a>#s", function($matches){
		return preg_replace_callback("#>(.*?)<#s", function($ma){
			return strtoupper($ma[0]);
		},$matches[0]);
	},$neo);

	print_r($neo);
}
loupe($argv);
?>
