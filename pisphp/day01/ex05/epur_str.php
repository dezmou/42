#!/usr/bin/php
<?php
if (isset($argv[1])){
	print_r(preg_replace("# +#", " ", trim($argv[1], " ")));
}
 ?>
