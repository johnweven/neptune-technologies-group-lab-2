//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//*                                                                                                       *
//* Program name    : L2-1.cpp                                                                            *
//*                                                                                                       *
//* Written by      : Adam Karsner                                                                        *
//*                                                                                                       *
//* Purpose         : The purpose of this program is to calculate how many boxes will be required to      *
//*                   hold a given number of cookies, as well as the number of containers that will       *
//*                   be required to store the calculated number of boxes.  It will also calculate        *
//*                   the amount of cookies leftover after discarding an unfilled box.  Similarly,        *
//*                   it will also calculate the amount of leftover boxes after discarding an             *
//*                   unfilled container.  After gathering some information from the user, it will        *
//*                   calculate everything and then display the results to the user.                      *
//*                                                                                                       *
//* Inputs          : 1. The number of cookies that a box can hold.                                       *
//*                   2. The number of boxes that a container can hold.                                   *
//*                   3. The total number of cookies.                                                     *
//*                                                                                                       *
//* Outputs         : 1. The number of cookies boxes needed to hold the entered total number of cookies.  *
//*                   2. The number of cookies left over after fully filling as many boxes as possible.   *
//*                   3. The number of containers needed to store the filled cookie boxes.                *
//*                   4. The number of boxes left over after fully filling as many containers as          *
//*                      possible.                                                                        *
//*                                                                                                       *
//* Calls           : No internal or external calls                                                       *
//*                                                                                                       *
//* Structure       : BEGIN                                                                               *
//*                        Monolithic code w/no subprocesses                                              *
//*                   STOP                                                                                *
//*                        End of program                                                                 *
//*                                                                                                       *
//*-------------------------------------------------------------------------------------------------------*
//*                                                                                                       *
//* Collaboration   : Collaboration with the following lab group members:                                 *
//*                          Anele Ncongo                                                                 *
//*                          Elijah Topete                                                                *
//*                          John Weaver                                                                  *
//*                          Sebastian Tiberos Cruz                                                       *
//*                                                                                                       *
//*-------------------------------------------------------------------------------------------------------*
//*                                                                                                       *
//* Change Log:                                                                                           *
//*                                   Revision Info                                                       *
//*       Date:   Author:      Rel.  Ver.  Mod.  Purpose:                                                 *
//*  03/03/2024   akarsner     001   001   000   First release.                                           *
//*                                                                                                       *
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare constants.
    const int DEFAULT_BOX_CAPACITY = 24,
        DEFAULT_CONTAINER_CAPACITY = 75;

    // Declare variables.
    int cookiesPerBox,
        boxesPerContainer,
        totalCookies,
        reqdBoxes,
        leftoverCookies,
        reqdContainers,
        leftoverBoxes;

    // Display the source author and program information.
    cout << "Adam Karsner    " << "L2-1    " << "L2-1.exe" << endl << endl;

    // Prompt the user to enter the number cookies that a box can store, and offer the option
    // to select the default amount by just pressing 'Enter' instead.
    cout << "Enter the number of cookies per box or press" << endl;
    cout << "'Enter' to use the default of " << DEFAULT_BOX_CAPACITY << " per box.: ";

    // If the character entered on the input buffer is 'Enter' (newline), then set the amount
    // of cookies that a box can hold to the default and tell that to the user.
    if (cin.peek() == '\n')
    {
        cookiesPerBox = DEFAULT_BOX_CAPACITY;
        cout << endl << "Default cookies per box will be used." << endl;
    }
    // Otherwise...
    else
    {
        // As long as the user enters invalid input, keep asking them to either enter valid input, press
        // 'Enter' to select the default amount of cookies per box, or offer the option to enter 'Q'
        // to exit the program.
        while (!(cin >> cookiesPerBox) || cookiesPerBox <=0 )
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl;
            cout << "Invalid input.  Please enter a positive integer" << endl;
            cout << "or just press 'Enter' to use the default. To exit" << endl;
            cout << "the program, enter 'Q': ";
            // If the user presses 'Enter' while in this input validation loop, then set the amount
            // of cookies that a box can hold to the default and tell that to the user.  Then break
            // out of the loop and continue to execute the rest of the program.
            if (cin.peek() == '\n')
            { 
                cin.ignore(1, '\n');
                cookiesPerBox = DEFAULT_BOX_CAPACITY;
                cout << endl << "Default cookies per box will be used." << endl;
                break;
            }
            // Otherwise, if the user enters 'Q' while in this input validation loop, then inform the
            // user that the program is exiting, then exit the program.
            else if (cin.peek() == 'Q')
            {
                cout << endl << "Exiting the program...";
                return 4;
            }
        }
    }
    
    // Clear the input buffer.
    cin.ignore(100, '\n');

    cout << endl;

    // Prompt the user to enter the number boxes that a container can store, and offer the option
    // to select the default amount by just pressing 'Enter' instead.
    cout << "Enter the number of boxes per container or press" << endl;
    cout << "'Enter' to use the default of " << DEFAULT_CONTAINER_CAPACITY << " boxes per container.: ";

    // If the character entered on the input buffer is 'Enter' (newline), then set the amount
    // of boxes that a container can hold to the default and tell that to the user.
    if (cin.peek() == '\n')
    {
        boxesPerContainer = DEFAULT_CONTAINER_CAPACITY;
        cout << endl << "Default boxes per container will be used." << endl;
    }
    // Otherwise...
    else
    {
        // As long as the user enters invalid input, keep asking them to either enter valid input, press
        // 'Enter' to select the default amount of boxes per container, or offer the option to enter 'Q'
        // to exit the program.
        while (!(cin >> boxesPerContainer) || boxesPerContainer <= 0)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl;
            cout << "Invalid input.  Please enter a positive integer" << endl;
            cout << "or just press 'Enter' to use the default. To exit" << endl;
            cout << "the program, enter 'Q': ";
            // If the user presses 'Enter' while in this input validation loop, then set the amount
            // of boxes that a container can hold to the default and tell that to the user.  Then break
            // out of the loop and continue to execute the rest of the program.
            if (cin.peek() == '\n')
            {
                cin.ignore(1, '\n');
                boxesPerContainer = DEFAULT_CONTAINER_CAPACITY;
                cout << endl << "Default boxes per container will be used." << endl;
                break;
            }
            // Otherwise, if the user enters 'Q' while in this input validation loop, then inform the
            // user that the program is exiting, then exit the program.
            else if (cin.peek() == 'Q')
            {
                cout << endl << "Exiting the program...";
                return 4;
            }
        }
    }

    // Clear the input buffer.
    cin.ignore(100, '\n');
    
    cout << endl;

    // Prompt the user to enter the total number of cookies.
    cout << "Enter the total number of cookies: ";

    // Keep asking the user to enter a positive integer if the user just presses 'Enter' instead of
    // entering something, or if the input is not a valid positive integer.  However, offer the option 
    // quit by entering 'Q'.
    while (cin.peek() == '\n' || !(cin >> totalCookies) || totalCookies <= 0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << endl;
        cout << "Invalid input.  Please enter a positive integer." << endl;
        cout << "To quit, enter 'Q': ";
        // If the user enters 'Q' while in this input validation loop, then inform the user that the
        // program is exiting and exit the program.
        if (cin.peek() == 'Q')
        {
            cout << endl << "Exiting the program...";
            return 4;
        }
    }

    // Now we calculate some how many boxes are required to hold the total number of cookies entered,
    // as well as the number of containers that will be required to hold those boxes.
    // If a box cannot be fully filled, we will discard the unfilled box and calculate the number of
    // leftover cookies. Similarly, if a container cannot be fully filled, we will discard the unfilled
    // container and calculate the number of leftover boxes.
    reqdBoxes = totalCookies / cookiesPerBox;
    leftoverCookies = totalCookies % cookiesPerBox;
    reqdContainers = reqdBoxes / boxesPerContainer;
    leftoverBoxes = reqdBoxes % boxesPerContainer;

    cout << endl;

    // Now we will output the results of our earlier calculations to the user in nicely formatted output.
    cout << setw(60) << right << "The number of cookie boxes needed to hold cookies: " << left << reqdBoxes << endl;
    cout << setw(60) << right << "Leftover cookies: " << left << leftoverCookies << endl;
    cout << setw(60) << right << "The number of containers needed to store the cookie boxes: " << left << reqdContainers << endl;
    cout << setw(60) << right << "Leftover boxes: " << left << leftoverBoxes << endl;
    
    // Now that we've reached the end of the program, tell the user to press 'Enter' to exit the program and
    // then exit the program when the user does so.
    char q;
    cout << "\nPress Enter to exit.";
    cin.ignore(2, '\n');
    cin.get(q);
    return 0;
}