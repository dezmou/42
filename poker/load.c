#include "load.h"

void newhand(int iaction)
{
    e->actnbr += 1;

    AGAME = malloc(sizeof(t_game));
    AGAME->board = malloc(11);
    AGAME->actions = malloc(sizeof(t_action*) * iaction);
    AGAME->players = malloc(sizeof(t_player*) * 6);
    AGAME->nbractions = -1;
    AGAME->nbrplayers = -1;
    AGAME->board[0] = 0;
}

void addpseudo(char *pseudo)
{
    e->totalplayers += 1;
    e->pseudos[e->totalplayers] = strdup(pseudo);
}

void test()
{
    //printf("bazouge\n");
}

void init(void)
{
    e = malloc(sizeof(t_env));
    e->games = malloc(sizeof(t_game*) * NBRHANDS);
    e->pseudos = malloc(sizeof(char *) * NBRPL);
    e->winners = malloc(sizeof(int*) * NBRWIN);
    e->actnbr = -1;
    e->totalplayers = -1;
}

void indexwin(void)
{

}

void showPl()
{
    int total;
    for (int k = 1000; k < 2000; k++)
    {
        total = 0;
        for (int i = 0; i<e->actnbr; i++)
        {
            for (int j = 0; j < e->games[i]->nbrplayers; j++)
            {
                if (k == e->games[i]->players[j]->pseudo)
                {
                    total += 1;
                }
            }
        }
        printf("%s : %d hands\n",e->pseudos[k], total);
    }

}
