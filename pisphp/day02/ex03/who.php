#!/usr/bin/php
<?php
$file = file_get_contents("/var/run/utmpx");
date_default_timezone_set('Europe/Paris');
$save = array();
while ($file != "")
{
	$tmp = unpack("A256login/A4id/A32name/spid/stypee/Itype/Idate/", $file);
	if ($tmp['type'] == 7)
		array_push($save, $tmp);
	$file = substr($file, 628);
}
sort($save);
foreach ($save as $tab)
{
	printf("%-8s %-8s %-2s %s %s \n", $tab["login"], $tab["name"], date("M", $tab["date"]),
	 date("j", $tab["date"]), date("H:i", $tab["date"]));
}

?>
