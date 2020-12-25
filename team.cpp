//
// Created by ulyss on 11/09/2020.
//

#include "team.h"

#include <utility>
#include <random>

team::team (std::string name, std::vector<float> chances):
    _name (std::move (name)),
    _chances (std::move (chances))
{ }

bool team::simulate_chance (float chance)
{
    std::random_device rd;
    std::mt19937 mt {rd()};

    std::uniform_real_distribution<double> uniform_rand {0., 1.};
    return uniform_rand (mt) < chance;
}

int team::simulate_chances ()
{
    int goals = 0;
    for (float chance : this->_chances)
        if (simulate_chance(chance))
            ++goals;
    return goals;
}

void team::set_chances(std::vector<float> chances)
{
    this->_chances = std::move(chances);
}

std::string team::get_name()
{
    return this->_name;
}

float team::get_xgoals() {
    float xgoals = 0;
    for (float f : _chances)
    {
        xgoals += f;
    }

    return xgoals;
}
