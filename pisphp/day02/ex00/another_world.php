#!/usr/bin/php
<?php
function another_world($ar){

	if (!isset($ar[1]))
		exit(0);
	$ar[1] = trim($ar[1]);
	$ar[1] = preg_replace('/\t+/', ' ',$ar[1]);
	$ar[1] = preg_replace('/ +/', ' ',$ar[1]);
	print_r($ar[1]."\n");

}
another_world($argv);
?>
