#include <iostream>
#include <string>

#include "sim_data.h"

using namespace std;

void display_art();
vector<float> get_chances ();
int get_nbtries();


int main(int nb_args, char* args[])
{
    display_art();

    bool do_logs = nb_args == 2 && string(args[1]) == "logs";

    cout << "Please enter the first team's name : " << endl << "->";
    string t1_name;
    getline(cin, t1_name);
    cout << "First team's name (" << t1_name << ") succesfully saved." << endl << endl;

    cout << "Please enter the second team's name : " << endl << "->";
    string t2_name;
    getline(cin, t2_name);
    cout << "Second team's name (" << t2_name << ") succesfully saved." << endl << endl;

    cout << "Please enter the first team's chances (separated by a line or a space). " << endl;
    cout << "Enter a negative value to stop." << endl << "->";
    vector<float> t1_chances = get_chances();
    cout << "All chances have been successfully saved." << endl << endl;

    cout << "Please enter the second team's chances (separated by a line or a space). " << endl;
    cout << "Enter a negative value to stop." << endl << "->";
    vector<float> t2_chances = get_chances();
    cout << "All chances have been successfully saved." << endl << endl;

    team t1 = team(t1_name, t1_chances);
    team t2 = team(t2_name, t2_chances);

    cout << "How many simulations do you want to be done (min : 1) ?" << endl << "->";
    int nb_tries = get_nbtries();
    cout << nb_tries << " simulations will be done." << endl << endl;
    cout << "Processing..." << endl;

    if(do_logs) cout << "Logs are being written in 'logs.txt'." << endl;

    sim_data data (t1, t2, nb_tries);
    data.calculate_data(do_logs);
    data.print_data();

    return 0;
}

void display_art()
{
    const string ASCII_ART = "        _____        _         _        \n"
                                  "       |  __ \\      (_)       | |       \n"
                                  " __  __| |__) |___   _  _ __  | |_  ___ \n"
                                  " \\ \\/ /|  ___// _ \\ | || '_ \\ | __|/ __|\n"
                                  "  >  < | |   | (_) || || | | || |_ \\__ \\\n"
                                  " /_/\\_\\|_|    \\___/ |_||_| |_| \\__||___/\n"
                                  "                                        \n"
                                  "                                        ";
    cout << ASCII_ART << endl;
}

vector<float> get_chances ()
{
    vector<float> chances = {};
    float chance {0.};
    while (chance >= 0.)
    {
        while (!(cin >> chance) || chance > 1.)
        {
            if(cin.eof())
            {
                throw runtime_error("Input stream has been closed.");
            }
            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please input a real number." << endl;
            }
            else
            {
                cout << "A chance must be between 0 and 1." << endl;
            }
            cout << "Please try again : " << endl << "->";
        }
        if (chance >= 0.)
        {
            chances.push_back(chance);
            cout << "Chance (" << chance << ") successfully saved." << endl;
            cout << "->";
        }
    }
    return chances;
}

int get_nbtries()
{
    int nb_tries {0};
    while (!(cin >> nb_tries) || nb_tries < 1)
    {
        if(cin.eof())
        {
            throw runtime_error("Input stream has been closed.");
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please input an integer." << endl;
        }
        cout << "Please try again : " << endl << "->";
    }
    return nb_tries;
}
