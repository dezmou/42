#include "load.h"

int getHandNbrs()
{
    return e->actnbr;
}

int getHand(int nbr)
{
    return e->games[nbr]->nbrplayers;
}
