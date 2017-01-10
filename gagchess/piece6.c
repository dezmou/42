#include "chess.h"

int place_piece_6(E,int piecex, int piecey)
{
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			if (y == piecey)
			{
				if (CA.bandit == 1 )
					return (0);
			}
			if(x == piecex)
			{
				if (CA.bandit == 1 )
					return (0);
			}
		}
	}
	FOR_HEIGHT
	{
		FOR_WIDTH
		{
			if (y == piecey)
			{
				CA.field = 6;
			}
			if (x == piecex)
			{
				CA.field = 6;
			}
		}
	}
	CASE[piecey][piecex].cover = 6;
	CASE[piecey][piecex].field = 1;
	PL[NP].x = piecex;
	PL[NP].y = piecey;
	return (1);
}