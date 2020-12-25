//
// Created by ulyss on 11/09/2020.
//

#ifndef XPOINTS_CALCULATOR_GAME_H
#define XPOINTS_CALCULATOR_GAME_H

#include "team.h"

class game
{
    private:
        team _t1;
        team _t2;
        void write_logs(int g1, int g2, int winner);
    public:
        game (team t1, team t2);
        int simulate (bool do_logs);
};


#endif //XPOINTS_CALCULATOR_GAME_H
