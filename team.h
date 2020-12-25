//
// Created by ulyss on 11/09/2020.
//

#ifndef XPOINTS_CALCULATOR_TEAM_H
#define XPOINTS_CALCULATOR_TEAM_H

#include <vector>
#include <string>

class team
{
    private:
        std::string _name;
        std::vector<float> _chances;

        static bool simulate_chance (float chance);

    public:
        team (std::string name, std::vector<float> chances);
        int simulate_chances ();

        void set_chances (std::vector<float> chances);
        std::string get_name ();
        float get_xgoals();
};


#endif //XPOINTS_CALCULATOR_TEAM_H
