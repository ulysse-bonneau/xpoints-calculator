/**
 * xPoints Calculator, a tool to calculate xPoints.
 * For more information, contact me at contact@ulyssebouchet.fr
 *
 * @author Ulysse Bouchet
 * @date 2020
 * @see https://github.com/ulysse-bouchet/xpoints-calculator
 */

#include <iostream>
#include <string>

#include "sim_data.h"

using namespace std;

/**
 * Displays the ASCII art representing the software.
 */
void display_art();

/**
 * This method reads the chances inputed by the user.
 * A chance is a real number between 0 and 1.
 *
 * @return a vector containing the chances.
 * @see std::vector
 */
vector<float> get_chances ();

/**
 * This method reads the amount of simulations inputed by the user.
 *
 * @return an integer corresponding to the number of simulations to be done.
 */
int get_nbsimul();


int main(int nb_args, char* args[])
{
    display_art();

    //Logs will be written if "logs" is passed as an argument to the program.
    bool do_logs = nb_args == 2 && string(args[1]) == "logs";

    //Asks an input for the first team's name then print it to confirm it.
    cout << "Please enter the first team's name : " << endl << "->";
    string t1_name;
    getline(cin, t1_name);
    cout << "First team's name (" << t1_name << ") succesfully saved." << endl << endl;

    //Asks an input for the second team's name then print it to confirm it.
    cout << "Please enter the second team's name : " << endl << "->";
    string t2_name;
    getline(cin, t2_name);
    cout << "Second team's name (" << t2_name << ") succesfully saved." << endl << endl;

    //Asks for the chances of the first team.
    cout << "Please enter the first team's chances (separated by a line or a space). " << endl;
    vector<float> t1_chances = get_chances();
    cout << "All chances have been successfully saved." << endl << endl;

    //Asks for the chances of the second team.
    cout << "Please enter the second team's chances (separated by a line or a space). " << endl;
    vector<float> t2_chances = get_chances();
    cout << "All chances have been successfully saved." << endl << endl;

    team t1 = team(t1_name, t1_chances);
    team t2 = team(t2_name, t2_chances);

    //Asks the user for the amount of simulations to be done.
    cout << "How many simulations do you want to be done (min : 1) ?" << endl << "->";
    int nb_simul = get_nbsimul();
    cout << nb_simul << " simulations will be done." << endl << endl;
    cout << "Processing..." << endl;

    if(do_logs) cout << "Logs are being written in 'logs.txt'." << endl;

    //Calculates and prints the data.
    sim_data data (t1, t2, nb_simul);
    data.calculate_data(do_logs);
    data.print_data();

    return 0;
}

/**
 * Displays the ASCII art representing the software.
 */
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
    cout << endl << ASCII_ART << endl;
    cout << "Created by Ulysse Bouchet in 2020." << endl;
    cout << "https://ulyssebouchet.fr/" << endl;
    cout << "https://github.com/ulysse-bouchet/xpoints-calculator/" << endl << endl;
}

/**
 * This method reads the chances inputed by the user.
 * A chance is a real number between 0 and 1.
 *
 * @return a vector containing the chances.
 * @see std::vector
 */
vector<float> get_chances ()
{
    cout << "Enter a negative value to stop." << endl << "->";

    vector<float> chances = {};
    float chance {0.};

    //If the input is a negative value, stop asking for values.
    while (chance >= 0.)
    {
        //Handles invalid inputs and errors.
        while (!(cin >> chance) || chance > 1.)
        {
            //When the input stream has been closed for some reason.
            if(cin.eof())
            {
                throw runtime_error("Input stream has been closed.");
            }
            //When the input is not a real number.
            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please input a real number." << endl;
            }
            //When the value inputed is invalid.
            else
            {
                cout << "A chance must be between 0 and 1." << endl;
            }
            cout << "Please try again : " << endl << "->";
        }
        //If the input is valid and is not a negative number, adds it to the list.
        if (chance >= 0.)
        {
            chances.push_back(chance);
            cout << "Chance (" << chance << ") successfully saved." << endl;
            cout << "->";
        }
    }
    return chances;
}

/**
 * This method reads the amount of simulations inputed by the user.
 *
 * @return an integer corresponding to the number of simulations to be done.
 */
int get_nbsimul()
{
    int nb_tries {0};
    //Handles invalid inputs and errors.
    while (!(cin >> nb_tries) || nb_tries < 1)
    {
        //When the input stream has been closed for some reason.
        if(cin.eof())
        {
            throw runtime_error("Input stream has been closed.");
        }
        //When the input is not an integer.
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please input an integer." << endl;
        }
        //When the value inputed is invalid.
        else
        {
            cout << "The amount of simulations must be >= 1." << endl;
        }
        cout << "Please try again : " << endl << "->";
    }
    return nb_tries;
}
