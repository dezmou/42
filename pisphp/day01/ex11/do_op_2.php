#!/usr/bin/php
<?php

function do_op($ac, $ar){
	if ($ac != 2){
		print_r("Incorrect Parameters\n");
		exit(0);
	}
	$symbs = ["*", "/", "-", "+", "%"];

	$i = -1;
	$text = $ar[1];
	$numered = False;
	$space = False;
	$symbed = False;
	$symb = "";
	while (isset($text[++$i])){
		$c = $text[$i];
		if (!is_numeric($c) and !in_array($c,$symbs) and $c != " "){
			print_r("Syntax Error\n");
			exit(0);
		}
		if (is_numeric($c) and $spaced == True and $numered == True){
			print_r("Syntax Error\n");
			exit(0);
		}
		if (in_array($c, $symbs) and $symbed){
			print_r("Syntax Error\n");
			exit(0);
		}
		if (in_array($c, $symbs)){
			$spaced = False;
			$numered = False;
			$symbed = True;
			$symb = $c;
		}
		if ($c == " "){
			$spaced = True;
		}
		if (is_numeric($c)){
			$numered = True;
			$spaced = False;
		}
	}
	$fi = explode($symb, $text);
	if ($symb == "+")
		print_r($fi[0] + $fi[1]);
	if ($symb == "/")
		print_r($fi[0] / $fi[1]);
	if ($symb == "*")
		print_r($fi[0] * $fi[1]);
	if ($symb == "-")
		print_r($fi[0] - $fi[1]);
	if ($symb == "%")
		print_r($fi[0] % $fi[1]);
	print_r("\n");
}

do_op($argc, $argv);

?>
