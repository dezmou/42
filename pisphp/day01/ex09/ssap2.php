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
	usort($ar, function($a, $b){
		$a = strtolower($a);
		$b = strtolower($b);
		$i = 0;
		while ($a[$i] && $b[$i]){
			if(ctype_alpha($a) && ctype_alpha($b))
				return (strcmp($a, $b));
			else if (ctype_digit($a) && ctype_digit($b))
				return (strcmp($a, $b));
			else if (!ctype_alnum($a) && !ctype_alnum($b))
				return (strcmp($a, $b));
			if(ctype_alpha($a) && !ctype_alpha($b))
				return (-1);
			if(!ctype_alpha($a) && ctype_alpha($b))
				return (1);
			if (ctype_digit($a) && !ctype_digit($b))
				return (-1);
			if (!ctype_digit($a) && ctype_digit($b))
				return (1);
			if (ctype_alnum($a) && !ctype_alnum($b))
				return (-1);
			if (!ctype_alnum($a) && ctype_alnum($b))
				return (1);
			$i++;
		}

		return 0;
	});
	foreach ($ar as $key => $value) {
		print_r($value."\n");
	};
 ?>
