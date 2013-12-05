#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fText("Text.txt");
    char cFinal;
    string sFinal;
    string sAll;
    int count = 0;
    char cLetter;
    while (fText.good())
    {
        cLetter = fText.get();
        if (!isupper(cLetter) && count == 0)
        {
            count++;
        }
        else if (isupper(cLetter) && (count== 1 || count == 2 || count == 3 || count == 5 || count == 6 || count == 7))
        {
            count++;

        }
        else if (islower(cLetter) && (count == 4))
        {
            count++;
            cFinal = cLetter;
        }
        else if (!isupper(cLetter) && count == 8)
        {
            count = 0;
            sFinal = cFinal;
            sAll.append(sFinal);
            sAll.append(" ");

        }
        else
        {
            count = 0;
        }
    }
    cout << sAll << endl;
}
