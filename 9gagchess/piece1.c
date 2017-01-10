#include "chess.h"

int place_piece_1(E,int piecex, int piecey)
{
	FOR_HEIGHT
		FOR_WIDTH
			if (y == piecey)
				if (CA.bandit == 1)
					return (0);
	FOR_HEIGHT
		FOR_WIDTH
			if (y == piecey)
				CA.field = 1;
	CASE[piecey][piecex].cover = 1;
	CASE[piecey][piecex].field = 1;
	PL[NP].x = piecex;
	PL[NP].y = piecey;
	return (1);
}
