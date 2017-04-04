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
	sort($neo);
	return ($neo);
}
 ?>
