//
// Created by ulyss on 11/09/2020.
//

#include "game.h"

#include <utility>
#include <fstream>

game::game (team t1, team t2):
    _t1(std::move (t1)),
    _t2(std::move (t2))
{ }

int game::simulate(bool do_logs)
{
    int g1 = _t1.simulate_chances();
    int g2 = _t2.simulate_chances();

    int winner = g1 > g2 ? 1 : (g1 == g2 ? 0 : -1);

    if(do_logs) write_logs(g1, g2, winner);

    return winner;
}

void game::write_logs(int g1, int g2, int winner)
{
    std::ofstream logs;

    logs.open("logs.txt", std::fstream::out | std::fstream::app);

    logs << _t1.get_name() << " scored " << g1 << " goals." << std::endl;
    logs << _t2.get_name() << " scored " << g2 << " goals." << std::endl;

    if (winner == 1)
    {
        logs << _t1.get_name() << " won this game." << std::endl;
    }
    else if (winner == -1)
    {
        logs << _t2.get_name() << " won this game." << std::endl;
    }
    else
    {
        logs << "The game ended in a draw." << std::endl;
    }

    logs << std::endl;
    logs.close();
}