#!/usr/bin/php
<?php
function another_world($ar){

	if (!isset($ar[1]))
		exit(0);
	$ar[1] = trim($ar[1]);
	$ar[1] = preg_replace('/\s+/', ' ',$ar[1]);
	print_r($ar[1]."\n");

}

function omt_error(){
	print_r("Wrong Format\n");
	exit(0);
}

function one_more_time($ar){
	date_default_timezone_set('Europe/Paris');
	if (!isset($ar[1]))
		exit(0);
	$sp = explode(" ", $ar[1]);
	if (sizeof($sp) != 5)
		omt_error();
	foreach ($sp as $key => $value) {
		if ($key == 0){
			if (preg_match("#^[Ll]undi$|^[Mm]ardi$|^[Mm]ercredi$|^[Jj]eudi$|^[Vv]endredi$|^[Ss]amedi$|^[Dd]imanche$#", $value) == 0 ){
				omt_error();
			}
		}
		if ($key == 1){
			if (preg_match("#^[0-9]{1,2}$#", $value) == 0 ){
				omt_error();
			}
		}
		if ($key == 2){
			if (preg_match("#^[Jj]anvier$|^[Ff][eé]vrier$|^[Mm]ars$|^[Aa]vril$|^[Mm]ai$|^[Jj]uin$|^[Jj]uillet$|^[Aa]o[uû]t$|^[Ss]eptembre$|^[Oo]ctobre$|^[Nn]ovembre$|^[Dd][eé]cembre$#", $value) == 0 ){
				omt_error();
			}
		}
		if ($key == 3){
			if (preg_match("#^[0-9]{4}$#", $value) == 0){
				omt_error();
			}
		}
		if ($key == 4){
			$ti = explode(":", $value);
			if (sizeof($ti) != 3)
				omt_error();
			foreach ($ti as $key => $va) {
				if (preg_match("#^[0-9]{2}$#", $va) == 0){
					omt_error();
				}
			}
		}
	}
	$day =  "16";
	$year = $sp[3];
	$nbrmonth = 1;
	$month_tab = array(
					"#^[Jj]anvier$#",
					"#^[Ff][eé]vrier$#",
					"#^[Mm]ars$#",
					"#^[Aa]vril$#",
					"#^[Mm]ai$#",
					"#^[Jj]uin$#",
					"#^[Jj]uillet$#",
					"#^[Aa]o[uû]t$#",
					"#^[Ss]eptembre$#",
					"#^[Oo]ctobre$#",
					"#^[Nn]ovembre$#",
					"#^[Dd][eé]cembre$#");
	foreach ($month_tab as $key => $value) {
		if (preg_match($value, $sp[2])){
			$nbrmonth += $key;
		}
	}

	$final = $year."-".$nbrmonth."-".$day." ".$sp[4];
	$stamp = strtotime($final);
	print_r($stamp);
}

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

	print_r($neo."\n");
}

function who(){//JE NE PENSE PAS QUE CEST BON MEME SI CA MARCHE PEUT ETRE FAUT 	IL REGARDER LE FICHIER /var/run/utmpx
	$chien = array();
	exec("who",$chien);
	foreach ($chien as $key => $value) {
		print_r($value."\n");
	}
}


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
	mkdir($dir_name);//SI LE FICHIER EXISTE CA PEUT FOUTRE LA POISSE
	foreach ($zouze[1] as $key => $value) {
		preg_match("#src=\"(.*?)\"#s", $value, $cassoulet);
		if (!preg_match("#https?://#", $cassoulet[1]))
			$cassoulet[1] = $ar[1]."/".$cassoulet[1];
		$tmp = explode("/", $cassoulet[1]);
		$img_name = $tmp[sizeof($tmp)-1];
		print_r($cassoulet[1]."\n");
		copy($cassoulet[1], "./".$dir_name."/".$img_name);
	}
}

who();
//photo($argv);
//who();
//loupe($argv);
//one_more_time($argv);





 ?>
