//Zachary A. Trudo
//Sources: None.

#include <iostream>     //cin, cout
#include <string>       //strings

using namespace std;

/*
    The following function handles all of the output.
    The initial if statements checks to see if it is
    one of the bills that ends in 'y' - if the bill
    names are changed in 'strBills' - this section
    must be updated to reflect that.
*/
void output(int num, bool numBool, string numTitle, int i)
{
    if ((i == 1 || i == 2 || i == 9) && num > 0)
    {
        if (numBool)
        {
            cout << "and ";
        }

        switch (num)
        {
            case 1:
                cout << "1 " <<  numTitle << "y";
                break;
            default:
                cout << num << " " << numTitle << "ies";
                break;
        }
        if (numBool)
        {
            cout << ".";
        }
        else
        {
            cout << ", ";
        }
    }
    else if (num > 0)
    {
        if (numBool)
        {
            cout << "and ";
        }
        switch (num)
        {
            case 1:
                cout << "1 " <<  numTitle;
                break;
            case 0:
                break;
            default:
                cout << num<< " " << numTitle << "s";
                break;
        }
        if (numBool)
        {
            cout << ".";
        }
        else
        {
            cout << ", ";
        }
    }

}

/*
    This is the main function of the program. I've used
    arrays for the values of the bills so that I can
    just run through 'for loops'.
*/
int main()
{
    double cash;
    int workingCash, numBills[10], i;
    int valBills[10] = {10000, 5000, 2000, 1000, 500, 100, 25, 10, 5, 1};
    bool boolBills[10] = {false};
    string strBills[10] = {"hundred", "fift", "twent", "ten", "five", "one", "quarter", "dime", "nickel", "penn"};

    cout << "Please enter the amount of money you'd like to make change for: " << endl;
    cin >> cash;
    cash *= 100;
    workingCash = cash;

    for (i = 0; i<=9; i++)      //This for loop is the computation loop that computes how many bills are needed.
    {
        numBills[i] = workingCash / valBills[i];
        workingCash -= numBills[i] * valBills[i];
    }

    for (i = 9; i >= 0; i--)    //This loop checks for the last bill and marks it.
    {
        if (numBills[i] > 0)
        {
            boolBills[i] = true;
            break;
        }
    }

    for (i = 0; i <= 9; i++)    //Output loop that calls the output function.
    {
        output(numBills[i], boolBills[i], strBills[i], i);
    }

    return 0;
}
