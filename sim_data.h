//
// Created by ulyss on 11/09/2020.
//

#ifndef XPOINTS_CALCULATOR_SIM_DATA_H
#define XPOINTS_CALCULATOR_SIM_DATA_H


#include "team.h"

class sim_data
{
    private:
        team _t1;
        team _t2;
        float _xpoints_t1;
        float _xpoints_t2;
        int _wins_t1;
        int _wins_t2;
        int _draws;
        int _nb_simul;
        bool _simulated;
    public:
        sim_data(team t1, team t2, int nb_simul);
        void calculate_data(bool do_logs);
        void print_data();
};


#endif //XPOINTS_CALCULATOR_SIM_DATA_H
