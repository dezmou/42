#!/usr/bin/php
<?php
function search_it($ar){
	$ok  = 0;
	if (sizeof($ar) < 3)
		exit(0);
	$base = $ar[1];
	foreach ($ar as $key => $value) {
		if ($key >= 2){
			$res = explode(":", $value);
			if (sizeof($res) != 2)
				exit(0);
		}
	}
	foreach ($ar as $key => $value) {
		if ($key >= 2){
			$res = explode(":", $value);
			if (sizeof($res) != 2)
				continue;
			if ($res[0] == $base){
				$ok = 1;
				$final = $res[1];
			}
		}
	}
	if ($ok){
		print_r($final."\n");
	}
}
search_it($argv);
 ?>
