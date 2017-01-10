#include "chess.h"

void empty(E)
{
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			CASE[y][x].cover = 0;
			CASE[y][x].field = 0;
			CA.bandit = 0;
		}
	}
	CASE[3][1].cover = 1;
	CASE[3][4].cover = 1;
	CASE[4][1].cover = 1;
	CASE[4][4].cover = 1;
	CASE[7][4].cover = 1;
	CASE[7][6].cover = 1;
	CASE[7][7].cover = 1;

	CASE[3][1].bandit = 1;
	CASE[3][4].bandit = 1;
	CASE[4][1].bandit = 1;
	CASE[4][4].bandit = 1;
	CASE[7][4].bandit = 1;
	CASE[7][6].bandit = 1;
	CASE[7][7].bandit = 1;
}

void 	init_cases(E)
{
	PL = (t_piece*)malloc(sizeof(t_piece) * 5);
	CASE = (t_case**)malloc(sizeof(t_case*)*HEIGHT);
	FOR_HEIGHT
	{
		CASE[y] = (t_case*)malloc(sizeof(t_case)*WIDTH);
		FOR_WIDTH
		{
			CASE[y][x].cover = 0;
			CASE[y][x].field = 0;
			CA.bandit = 0;
		}
	}
	empty(e);
	e->nbrpiece = 0;


}



t_env *init_env(void)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	e->nbrtest = 0;
	e->ok = 0;
	init_cases(e);
	return (e);
}
void printit(E)
{
	printf("\n\n");
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			if (CA.bandit != 0)
			{
				printf(" # ");
				continue;
			}
			if (CA.cover != 0)
			{

				printf(" %d ", CA.cover);
				continue;
			}
			if (CA.field != 0 )
			{
				printf(" * ");
				continue;
			}
			else
			{
				printf(" . ");
			}
		}
		printf("\n");
	}
}

int place(E, int x, int y, int nbr)
{
	if (nbr == 0)
		return (place_piece_3(e, x, y));
	if (nbr == 4)
		return (place_piece_2(e, x, y));
	if (nbr == 5)
		return (place_piece_5(e, x, y));
	if (nbr == 3)
		return (place_piece_4(e, x, y));
	if (nbr == 2)
		return (place_piece_6(e, x, y));
	if (nbr == 1)
		return (place_piece_1(e, x, y));
	return (0);

}

int isfull(E)
{
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			if (CA.bandit != 0)
				continue;
			if (CA.cover != 0)
				continue;
			if (CA.field != 0 )
				continue;
			return (0);
		}
	}
	return (1);
}

void remap(E)
{
	int tmp;
	tmp = NP;
	NP = 0;
	for (int i = 0; i <= tmp; i++)
	{
		place(e, PL[i].x, PL[i].y, NP);
		NP++;
	}
	NP--;

}

int 	place_all(E)
{
	//PT
	if (NP == 6)
	{
		//PT
		//GT
		
		if (isfull(e))
		{
			printf("FINI! with %ld tests \n", e->nbrtest);
			printit(e);
			exit(0);
		}
		
		empty(e);
		NP--;
		remap(e);
		NP++;
		return 1;
	}
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			if (CA.cover == 0)
			{
				e->nbrtest += 1;
				if (place(e, x, y, NP))
				{
					NP++;
					place_all(e);
					NP--;
					empty(e);
					NP--;
					remap(e);
					NP++;
					if (e->nbrtest % 1000 == 0)
					{
						printf("nbr test: %ld", e->nbrtest);
						PT
					}
					//PT
					//GT
				}
			}
		}
	}
}


int main(void)
{
	t_env *e;
	e = init_env();
	//printit(e);
	place_all(e);


	return (0);
}
