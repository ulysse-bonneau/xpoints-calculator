//
// Created by ulyss on 11/09/2020.
//

#include "sim_data.h"
#include "game.h"
#include "iostream"
#include "fstream"

#include <utility>

sim_data::sim_data(team t1, team t2, int nb_tries):
    _t1(std::move(t1)),
    _t2(std::move(t2)),
    _nb_tries(nb_tries)
{
    _xpoints_t1 = 0;
    _xpoints_t2 = 0;
    _wins_t1 = 0;
    _wins_t2 = 0;
    _draws = 0;
    _simulated = false;
}

void init_logs()
{
    std::ofstream logs;
    logs.open("logs.txt", std::fstream::out | std::fstream::trunc);
    logs << "###LOGS###" << std::endl << std::endl;
    logs.close();
}

void write_logs(int i)
{
    std::ofstream logs;
    logs.open("logs.txt", std::fstream::out | std::fstream::app);
    logs << "Simulating game #" << i << "." << std::endl;
    logs.close();
}

void sim_data::calculate_data(bool do_logs)
{
    game g (_t1 , _t2);

    if(do_logs) init_logs();
    for (int i {0}; i < _nb_tries; ++i)
    {
        if(do_logs) write_logs(i + 1);

        int result = g.simulate(do_logs);
        if (result == 1)
        {
            ++_wins_t1;
        }
        else if (result == -1)
        {
            ++_wins_t2;
        }
        else
        {
            ++_draws;
        }
    }

    _xpoints_t1 = (float) (_wins_t1 * 3 + _draws) / (float) _nb_tries;
    _xpoints_t2 = (float) (_wins_t2 * 3 + _draws) / (float) _nb_tries;
    _simulated = true;
}

void sim_data::print_data()
{
    if (!_simulated)
    {
        std::cout << "sim_data should have been simulated before trying to display it." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << _nb_tries << " games have been simulated." << std::endl;

    std::cout << _t1.get_name() << " won " << _wins_t1 << " games." << std::endl;
    std::cout << _t2.get_name() << " won " << _wins_t2 << " games." << std::endl;
    std::cout << _draws << " games ended in a draw." << std::endl;

    std::cout << _t1.get_name() << " should have won " << _xpoints_t1 << " points." << std::endl;
    std::cout << _t2.get_name() << " should have won " << _xpoints_t2 << " points." << std::endl;
    std::cout << _t1.get_name() << " should have scored " << _t1.get_xgoals() << " goals." << std::endl;
    std::cout << _t2.get_name() << " should have scored " << _t2.get_xgoals() << " goals." << std::endl;
}
