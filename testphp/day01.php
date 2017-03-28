#!/usr/bin/php
<?php

function ft_split($str){
	//zut il y a la fonction explode
	$index = 0;
	$i = 0;
	$len = strlen($str);
	$final = array();

	while ($str[$i] == " ")
		$i++;
	while ($i <= $len){
		if ($str[$i] == " "){
			$index += 1;
			while ($str[$i] == " ")
				$i++;
		}
		if ($i >= $len)
			break ;
		$final[$index] = $final[$index] . $str[$i];
		$i++;
	}
	return ($final);
}

function aff_args($ar){
	foreach ($ar as $key => $value)
		if ($key > 0)
			print_r($value."\n");
}

function epur_str($ar){//are regex allowed ??
	if (!isset($ar[1]))
		return ;
	$ar[1] = trim($ar[1], " ");
	$ar[1] = preg_replace('!\s+!', ' ', $ar[1]);
	print_r($ar[1]);
}

function ssap($ar){
	$final = array();
	foreach ($ar as $key => $value)
		if ($key > 0)
			$final =  array_merge($final, ft_split($value));
	sort($final);
	foreach( $final as $value)
		print_r($value."\n");
}

function rostring($ar){
	if (!isset($ar[1]))
		return ;
	$final = ft_split($ar[1]);
	if (sizeof($final) > 1){
		array_push($final, $final[0]);
		unset($final[0]);
	}
	foreach($final as $key => $value){
		print_r($value);
		if ($key != sizeof($final))
			print_r(" ");
	}
	print_r("\n");
}

function ft_is_sort($in){
	$tmp = $in;

	sort($tmp);
	if ($tmp == $in)
		return (True);
	return (False);
}

function do_op($ac, $ar){//do_op2
	if ($ac != 2){
		print_r("Incorrect Parameters");
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

function search_it($ar){
	if (sizeof($ar) < 3)
		exit(0);
	$base = $ar[1];
	foreach ($ar as $key => $value) { // EST CE QUE IL FAUT BIEN VERIFIER CA ??
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


//printf(ft_split("  bonjour je    suis une     string   "));
//aff_args($argv);
//epur_str($argv);
//ssap($argv);
//rostring($argv);
//print_r(ft_is_sort(["aaa", "bbb", "ccc", "ddd"]));
//do_op($argc,$argv);
//search_it($argv);








 ?>
