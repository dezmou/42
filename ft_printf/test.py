import os
import sys

def doit(lapin):
	lapin = lapin.replace(");", "")
	lapin = lapin.replace(")  ;", "")
	lapin = lapin.replace(") ;", "")
	back = lapin

	fil = open("./ft_printf.h", "r")
	content = fil.read()
	fil.close()
	fil = open("./ft_printf.h", "w")
	neoline = ""
	for line in content.split("\n"):
		if "# define TEST" in line:
			print line
			line = "# define TEST "+lapin
		neoline += line+"\n"
	fil.write(neoline)

	fil.close()
	os.system("make test")
try:
	doit(sys.argv[1])
except:
	while True:
		lapin = raw_input("ft_printf(")
		doit(lapin)
