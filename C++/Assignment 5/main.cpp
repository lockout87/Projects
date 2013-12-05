//Zachary A Trudo
//Assignment 5
//Sources: None
// If I did this project again - I would opt to use functions,
// I feel that the code here is rather sloppy looking.

#include <iostream>    //cin, cout
#include <fstream>      //ifstream, .eof()
#include <string>         //strings
#include <iomanip>     //setprecision()

using namespace std;


int main()
{
    ifstream inputFile;
    double milesToDest, flightHours, gallonsBurned,
           fuelRemaining, airplaneSpeed, gallonsCarried, gallonsPerHour;
    string destination, inputFileName;
    char yesNo;
    bool stillGoing = true;
    int flightTHours, flightTMins;
    cout << fixed <<  setprecision(2);

    while (stillGoing)      // Loop running throguh entire file.
    {
        /*
            Takes input for filename, and checks and makes sure it opens.
        */
        cout << "What is the name of the file: " << endl;
        cin >> inputFileName;
        inputFile.open(inputFileName.c_str());
        if (!inputFile.is_open())
        {
            cout << "File did not open";
            break;
        }

        /*
            This section takes input for the various plane variables.
        */
        cout << "What is the speed of your airplane." << endl;
        cin >> airplaneSpeed;
        cout << "How much fuel is the airplane carrying." << endl;
        cin >> gallonsCarried;
        cout << "How much fuled does your airplane burn per hour?" << endl;
        cin >> gallonsPerHour;
        cout << "The total time the airplane can fly is " << gallonsCarried / gallonsPerHour <<
            " hours, and can fly " << gallonsCarried / gallonsPerHour * airplaneSpeed << " miles." << endl;
        cout << setfill('-') << setw(50) << " " << endl;
        cout << setfill(' ') << setw(15) <<  left << "Name" << setw(10) << "Distance" <<  setw(15) << "Flight Hours" <<
            setw(17) << "Gallons Burned" << setw(15) << "Fuel Remaining" <<  endl;


       while (true)            // Loop runs through each  variable  in the and gives the appropriate output.
        {
            inputFile >> destination >> milesToDest;

            /*
                This section checks to see if the end of the file has been reached -
                if it has it breaks out of the loop.
                I found that doing it this way was more reliable than using
                while (inputFile.eof()).
            */
            if (inputFile.eof())
            {
                break;
            }

            flightHours = milesToDest / airplaneSpeed;

            flightTHours = flightHours;
            flightTMins = (flightHours - flightTHours) * 60;
            gallonsBurned = flightHours * gallonsPerHour;
            fuelRemaining = gallonsCarried - gallonsBurned;
            cout << left << setw(15) << destination << right << setw(8) << milesToDest << setw(9) << flightTHours << setw(1) << "h" << setw(3) << flightTMins << setw(1) << "m" <<
                setw(17) << gallonsBurned << setw(15) << fuelRemaining << endl;
            if (fuelRemaining < 0)
            {
                cout << right << setfill('*') <<  setw(18) << " " << setw(27) << "Insufficient Fuel to reach " <<  destination << " " <<  setw(18) << " " << setfill(' ') << endl;
            }
        }

        /*
            This section simply asks if the user wants to do another calculation.
            If not - the 'stillGoing' flag is set to false and the program ends.
        */
        cout << "Do you want to do another calculation? (y/n)";
        cin >> yesNo;
        if (yesNo == 'n' || yesNo == 'N')
        {
            stillGoing = false;
        }

        /*
            I've opted to have the user select the input file each time they run
            the program - as such, I close out the inputFile rather than clearing it.
        */
        inputFile.close();
    }

    return 0;
}
