#include "CDCollection.h"


void searchByBand(list<CD> &collection)
{
    list<CD>::iterator it;
    string strSearch, workingStr = "                                   ";
    size_t strLoc;
    int counter = 0;
    cin.ignore();

    cout << "What is the search term?" << endl;
    getline(cin, strSearch);

    for (int i = 0; i <= strSearch.length(); i++)
    {
        strSearch[i] = tolower(strSearch[i]);
    }

    it = collection.begin();

    while(it != collection.end())
    {
        for (int i = 0; i <= it->bandName.length(); i++)
        {
            workingStr[i] = tolower(it->bandName[i]);
        }
        strLoc = workingStr.find(strSearch);
        if (strLoc != string::npos)
        {
            cout << it->title << " (" << it -> bandName << ")" << endl;
            counter++;
        }
        it++;
        workingStr = "                                   ";
    }
    cout << counter << " records in collection." << endl << endl;
}

void searchByTitle (list<CD> &collection)
{
    list<CD>::iterator it;
    string strSearch, workingStr = "                                   ";
    size_t strLoc;
    int counter = 0;
    cin.ignore();

    cout << "What is the search term?" << endl;
    getline(cin, strSearch);

    for (int i = 0; i <= strSearch.length(); i++)
    {
        strSearch[i] = tolower(strSearch[i]);
    }

    it = collection.begin();

    while(it != collection.end())
    {
        for (int i = 0; i <= it->title.length(); i++)
        {
            workingStr[i] = tolower(it->title[i]);
        }
        strLoc = workingStr.find(strSearch);
        if (strLoc != string::npos)
        {
            cout << it->title << " (" << it -> bandName << ")" << endl;
            counter++;
        }
        it++;
        workingStr = "                                   ";
    }
    cout << counter << " records in collection." << endl << endl;
}

void showAll (list<CD> &collection)
{
    list<CD>::iterator it;

    it = collection.begin();
    while (it != collection.end())
    {
        cout << it->title << " (" << it->bandName << ")" << endl;
        it++;
    }
}
