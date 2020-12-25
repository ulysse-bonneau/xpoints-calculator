#include <iostream>
#include <string>

#include "data.h"

void display_art();
std::string get_string ();
std::vector<float> get_chances ();
int get_nbtries();

int main(int nb_args, char* args[])
{
    display_art();

    bool do_logs = nb_args == 2 && std::string(args[1]) == "logs";

    std::cout << "Please enter the first team's name : " << std::endl << "->";
    std::string t1_name = get_string();
    std::cout << "First team's name (" << t1_name << ") succesfully saved." << std::endl << std::endl;

    std::cout << "Please enter the second team's name : " << std::endl << "->";
    std::string t2_name = get_string();
    std::cout << "Second team's name (" << t2_name << ") succesfully saved." << std::endl << std::endl;

    std::cout << "Please enter the first team's chances (one chance per line). " << std::endl;
    std::cout << "Enter a negative value to stop." << std::endl << "->";
    std::vector<float> t1_chances = get_chances();
    std::cout << "All chances have been successfully saved." << std::endl << std::endl;

    std::cout << "Please enter the second team's chances (one chance per line). " << std::endl;
    std::cout << "Enter a negative value to stop." << std::endl << "->";
    std::vector<float> t2_chances = get_chances();
    std::cout << "All chances have been successfully saved." << std::endl << std::endl;

    team t1 = team(t1_name, t1_chances);
    team t2 = team(t2_name, t2_chances);

    std::cout << "How many simulations do you want to be done (min : 1) ?" << std::endl << "->";
    int nb_tries = get_nbtries();
    std::cout << nb_tries << " simulations will be done." << std::endl << std::endl;
    std::cout << "Processing..." << std::endl;

    if(do_logs) std::cout << "Logs are being written in 'logs.txt'." << std::endl;

    data data (t1, t2, nb_tries);
    data.calculate_data(do_logs);
    data.display_data();

    return 0;
}

void display_art()
{
    const std::string ASCII_ART = "        _____        _         _        \n"
                                  "       |  __ \\      (_)       | |       \n"
                                  " __  __| |__) |___   _  _ __  | |_  ___ \n"
                                  " \\ \\/ /|  ___// _ \\ | || '_ \\ | __|/ __|\n"
                                  "  >  < | |   | (_) || || | | || |_ \\__ \\\n"
                                  " /_/\\_\\|_|    \\___/ |_||_| |_| \\__||___/\n"
                                  "                                        \n"
                                  "                                        ";
    std::cout << ASCII_ART << std::endl;
}

std::string get_string ()
{
    std::string str;
    while (!(std::cin >> str))
    {
        std::cin.clear();
        std::cin.ignore(255, '\n');

        std::cout << "An error has occured. Please try again : " << std::endl;
        std::cout << "->";
    }
    return str;
}

std::vector<float> get_chances ()
{
    std::vector<float> chances = {};
    float chance {0.};
    while (chance >= 0.)
    {
        while (!(std::cin >> chance) || chance > 1.)
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');

            std::cout << "An error has occured. A chance must be a real number between 0 and 1." << std::endl;
            std::cout << "Please try again : " << std::endl;
            std::cout << "->";
        }
        if (chance >= 0.)
        {
            chances.push_back(chance);
            std::cout << "Chance (" << chance << ") successfully saved." << std::endl;
            std::cout << "->";
        }
    }
    return chances;
}

int get_nbtries()
{
    int nb_tries {0};
    while (!(std::cin >> nb_tries) || nb_tries < 1)
    {
        std::cin.clear();
        std::cin.ignore(255, '\n');

        std::cout << "An error has occured. Please try again : " << std::endl;
        std::cout << "->";
    }
    return nb_tries;
}
