#include "func.h"
#define VALUE '5'



int main(void)
{
	char joie[] = "55555544444444eeeeeeeeegggggggggg)))))))))))";
	int i;
	MKDRAW
	LINE("bonjour")
	MKGRAPH
	while (joie[i])
	{
		ADDGRAPH((int)joie[i]);
		i++;
	}
	ENDGRAPH
	return(0);
}