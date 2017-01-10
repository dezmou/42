#include "load.h"


void addaction(int iplayer, int action, int rendu, char *sjetons)
{
    /*
    1 checks
    2 bet
    3 call
    4 raise
    5 fold
    */

    AGAME->nbractions += 1;

    AGAME->actions[AGAME->nbractions] = malloc(sizeof(t_action));
    AGAME->actions[AGAME->nbractions]->iplayer = (char)iplayer;
    AGAME->actions[AGAME->nbractions]->action = (char)action;
    AGAME->actions[AGAME->nbractions]->rendu = (char)rendu;
    AGAME->actions[AGAME->nbractions]->jetons = strtof(sjetons,NULL);

}

void addflop(char *flop)
{
    AGAME->board = strdup(flop);
}
void addboard(char *str)
{
    AGAME->board = strcat(AGAME->board, str);
}
void addplayer(char *pseudo, char *sjetons, int pos, int iswinner)
{
    AGAME->nbrplayers += 1;
    AGAME->players[AGAME->nbrplayers] = malloc(sizeof(t_player));
    AGAME->players[AGAME->nbrplayers]->jetons = strtof(sjetons,NULL);
    AGAME->players[AGAME->nbrplayers]->pseudo = atoi(pseudo);
    AGAME->players[AGAME->nbrplayers]->iswinner = (char)iswinner;
}
