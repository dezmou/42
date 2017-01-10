#ifndef LOAD_H
# define LOAD_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define NBRHANDS 2050000
# define AGAME e->games[e->actnbr]
# define NBRPL 40000
# define NBRWIN 213
typedef struct  s_action
{
    char action;
    char rendu;
    char iplayer;
    float jetons;

}               t_action;

typedef struct  s_player
{
    int pseudo;
    float jetons;
    char pos;
    char iswinner;
}               t_player;

typedef struct s_game
{
    int nbrplayers;
    int nbractions;
    char button;
    char *board;
    t_action **actions;
    t_player **players;
}             t_game;

typedef struct s_env
{
  t_game **games;

  int actnbr;
  int totalplayers;
  int totalwinners;
  char **pseudos;
  int **winners;
}             t_env;

void init(void);
void newhand(int iaction);


t_env *e;

#endif
