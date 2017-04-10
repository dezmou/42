#!/usr/bin/php
<?php

function photo($ar){
	if (sizeof($ar) != 2)
		exit(0);
	try{
		$content = file_get_contents($ar[1]);
	}
	catch(Exception $e){
		exit(0);
	}
	$zouze = array();
	preg_match_all("#<img(.*?)>#s", $content, $zouze);
	$dir_name = preg_replace("#https?://#", "", $ar[1]);
	mkdir($dir_name);
	foreach ($zouze[1] as $key => $value) {
		preg_match("#src=\"(.*?)\"#s", $value, $cassoulet);
		if (!preg_match("#https?://#", $cassoulet[1]))
			$cassoulet[1] = $ar[1]."/".$cassoulet[1];
		$tmp = explode("/", $cassoulet[1]);
		$img_name = $tmp[sizeof($tmp)-1];
		copy($cassoulet[1], "./".$dir_name."/".$img_name);
	}
}
photo($argv);
?>
