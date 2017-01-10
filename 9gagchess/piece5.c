#include "chess.h"

int place_piece_5(E,int piecex, int piecey)
{
	FOR_HEIGHT
		FOR_WIDTH
			if (piecey == y || piecey + 1 == y || piecey - 1 == y)
				if (piecex == x || piecex + 1 == x || piecex - 1 == x)
					if (CA.bandit == 1 )
						return (0);

	FOR_HEIGHT
		FOR_WIDTH
		{
			if (y == piecey)
				if (CA.bandit == 1 )
					return (0);
			if(x == piecex)
				if (CA.bandit == 1 )
					return (0);
		}

	FOR_HEIGHT
		FOR_WIDTH
		{
			for (int i = 0; i < 7 ; i++)
			{
				if (y+i == piecey && x+i == piecex)
					if (CA.bandit == 1 )
						return (0);
				if (y-i == piecey && x+i == piecex)
					if (CA.bandit == 1 )
						return (0);
				if (y+i == piecey && x-i == piecex)
					if (CA.bandit == 1 )
						return (0);
				if (y-i == piecey && x-i == piecex)
					if (CA.bandit == 1 )
						return (0);

			}
		}





	FOR_HEIGHT
		FOR_WIDTH
		{
			for (int i = 0; i < 7 ; i++)
			{
				if (y+i == piecey && x+i == piecex)
					CA.field = 5;
				if (y-i == piecey && x+i == piecex)
					CA.field = 5;
				if (y+i == piecey && x-i == piecex)
					CA.field = 5;
				if (y-i == piecey && x-i == piecex)
					CA.field = 5;
			}
		}

	FOR_HEIGHT
		FOR_WIDTH
		{
			if (y == piecey)
				CA.field = 5;
			if (x == piecex)
				CA.field = 5;
		}

	FOR_HEIGHT
		FOR_WIDTH
			if (piecey == y || piecey + 1 == y || piecey - 1 == y)
				if (piecex == x || piecex + 1 == x || piecex - 1 == x)
					CA.field = 5;



	CASE[piecey][piecex].cover = 5;
	PL[NP].x = piecex;
	PL[NP].y = piecey;
	return (1);
}
