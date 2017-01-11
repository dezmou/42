#ifndef CHESS_H
# define CHESS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define FOR_HEIGHT for (int y = 0; y < HEIGHT; y++)
# define FOR_WIDTH for (int x = 0; x < WIDTH; x++)
# define WIDTH 8
# define HEIGHT 8
# define E t_env *e
# define CASE e->cases
# define PL e->pieces
# define NP e->nbrpiece
# define CA CASE[y][x]
# define GT getchar();
# define PT printit(e);

typedef struct 	s_piece
{
	int x;
	int y;
}				t_piece;

typedef struct 	s_case
{
	char bandit;
	char field;
	char cover;
}				t_case;

typedef struct 	s_en
{
	int 		zouze;
	FILE 		*fp;
	int 		ok;
	long 		nbrtest;
	t_case 		**cases;
	t_piece 	*pieces;
	int 		nbrpiece;
}				t_env;

int 	place_piece_1(E,int piecex, int piecey);
int 	place_piece_2(E,int piecex, int piecey);
int 	place_piece_3(E,int piecex, int piecey);
int 	place_piece_4(E,int piecex, int piecey);
int 	place_piece_5(E,int piecex, int piecey);
int 	place_piece_6(E,int piecex, int piecey);


#endif
