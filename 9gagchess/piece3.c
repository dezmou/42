#include "chess.h"

int place_piece_3(E,int piecex, int piecey)
{
	FOR_HEIGHT
		FOR_WIDTH
			if (piecey == y || piecey + 1 == y || piecey - 1 == y)
				if (piecex == x || piecex + 1 == x || piecex - 1 == x)
					if (CA.bandit == 1 )
						return (0);
	FOR_HEIGHT
		FOR_WIDTH
			if (piecey == y || piecey + 1 == y || piecey - 1 == y)
				if (piecex == x || piecex + 1 == x || piecex - 1 == x)
					CA.field = 3;
	CASE[piecey][piecex].cover = 3;
	CASE[piecey][piecex].field = 1;
	PL[NP].x = piecex;
	PL[NP].y = piecey;
	return (1);
}
//94 027 508
