#!/usr/bin/php
<?php
function ssplit($str){
	$ar = explode(" ", $str);
	$neo = array();
	foreach ($ar as $key => $value) {
		if ($value != ""){
			array_push($neo, $value);
		}
	}
	return ($neo);
}
function rostring($ar){
	if (!isset($ar[1]))
		return ;
	$final = ssplit($ar[1]);
	if (sizeof($final) > 1){
		$final[sizeof($final)] = $final[0];
		unset($final[0]);
	}
	foreach($final as $key => $value){
		print_r($value);
		if ($key != sizeof($final))
			print_r(" ");
	}
	print_r("\n");
}
rostring($argv);
 ?>
