#!/usr/bin/php
<?php
function ft_split($str){
	$ar = explode(" ", $str);
	$neo = array();
	foreach ($ar as $key => $value) {
		if ($value != ""){
			array_push($neo, $value);
		}
	}
	return ($neo);
}

	$ar = array();
	foreach ($argv as $key => $value) {
		if ($key > 0){
			$zouze = ft_split($value);
			foreach ($zouze as $key => $valuee) {
				array_push($ar, $valuee);
			}
		}
	}
	sort($ar);
	foreach ($ar as $key => $value) {
		print_r($value."\n");
	};
 ?>
