#include "chess.h"

int place_piece_4(E,int piecex, int piecey)
{
	FOR_HEIGHT
		FOR_WIDTH
		{
			if (y == piecey-1)
				if (x == piecex+2 || x == piecex-2)
					if (CA.bandit == 1 )
						return (0);
			if (y == piecey+1)
				if (x == piecex+2 || x == piecex-2)
					if (CA.bandit == 1 )
						return (0);
			if (x == piecex-1)
				if (y == piecey+2 || y == piecey-2)
					if (CA.bandit == 1 )
						return (0);
			if (x == piecex+1)
				if (y == piecey+2 || y == piecey-2)
					if (CA.bandit == 1 )
						return (0);
		}
	FOR_HEIGHT
		FOR_WIDTH
		{
			if (y == piecey-1)
				if (x == piecex+2 || x == piecex-2)
					CA.field = 4;
			if (y == piecey+1)
				if (x == piecex+2 || x == piecex-2)
					CA.field = 4;
			if (x == piecex-1)
				if (y == piecey+2 || y == piecey-2)
					CA.field = 4;
			if (x == piecex+1)
				if (y == piecey+2 || y == piecey-2)
					CA.field = 4;
		}
	CASE[piecey][piecex].cover = 4;
	CASE[piecey][piecex].field = 1;
	PL[NP].x = piecex;
	PL[NP].y = piecey;
	return (1);
}
