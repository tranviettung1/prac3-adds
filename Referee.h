#ifndef REFEREE
#define REFEREE

#include "Player.h"

class Referee {
    public:
        Referee();
        char refGame(Player* player1, Player* player2);
};

#endif