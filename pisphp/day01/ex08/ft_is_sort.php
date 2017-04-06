#!/usr/bin/php
<?php
	function ft_is_sort($tab){
		$t = $tab;
		sort($t);
		if ($tab === $t){
			return (True);
		}
		return (False);
	}
 ?>
