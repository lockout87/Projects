#include "CDCollection.h"

using namespace std;


int main()
{
    list<CD> collection;
    string inFileName;
    ifstream inFile;
    char select;

    cout << "What is the name of the file?" << endl;
    cin >> inFileName;


    if (openFile(inFile, inFileName))
    {
        readFile(inFile, collection);
    }
    else
    {
        cout << "Unable to load file, terminating program." << endl;
        return 1;
    }

    sortMenu(collection);
    cin.ignore();

    while (select != 'q')
    {
        cout << "Please enter B for (B)and search, (T)itle search, (L)ist all records, "
            << "(R)eturn to sort menu, or Q to quit." << endl;
        cin >> select;
        select = tolower(select);
        if (select == 'b')
        {
            searchByBand(collection);
        }
        else if (select == 't')
        {
            searchByTitle(collection);
        }
        else if (select == 'l')
        {
            showAll(collection);
        }
        else if (select == 'r')
        {
            sortMenu(collection);
        }
    }

    cout << "Thank you for using the super awesome CD Collection Thingy!" << endl;
    return 0;
}

