#!/usr/bin/php
<?php
function search_it($ar){
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
				exit(0);
			if ($res[0] == $base){
				print_r($res[1]."\n");
				exit(0);
			}
		}
	}
}
search_it($argv);


 ?>
