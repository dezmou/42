#!/usr/bin/php
<?php
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
			if (preg_match("#^[Ll]undi$|^[Mm]ardi$|^[Mm]ercredi$|^[Jj]eudi$|^[Vv]endredi$|^[Ss]amedi$|^[Dd]imanche$#", $value) === 0 ){
				omt_error();
			}
		}
		if ($key == 1){
			if (preg_match("#^[0-9]{1,2}$#", $value) == 0 ){
				omt_error();
			}
		}
		if ($key == 2){
			if (preg_match("#^([Jj]anvier|[Ff](e|é)vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o(u|û)t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd](e|é)cembre)$#", $value) === 0 ){
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
	$day =  $sp[1];
	$year = $sp[3];
	$nbrmonth = 1;
	$month_tab = array(
					"#^[Jj]anvier$#",
					"#^[Ff](e|é)vrier$#",
					"#^[Mm]ars$#",
					"#^[Aa]vril$#",
					"#^[Mm]ai$#",
					"#^[Jj]uin$#",
					"#^[Jj]uillet$#",
					"#^[Aa]o(u|û)t$#",
					"#^[Ss]eptembre$#",
					"#^[Oo]ctobre$#",
					"#^[Nn]ovembre$#",
					"#^[Dd](e|é)cembre$#");
	foreach ($month_tab as $key => $value) {
		if (preg_match($value, $sp[2])){
			$nbrmonth += $key;
		}
	}

	$final = $year."-".$nbrmonth."-".$day." ".$sp[4];
	$stamp = strtotime($final);
	print_r($stamp."\n");
}
one_more_time($argv);
?>
