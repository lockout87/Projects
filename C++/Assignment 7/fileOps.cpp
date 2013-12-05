#include "CDCollection.h"

bool openFile(ifstream &inFile, string inFileName)
{
    inFile.open(inFileName.c_str());

    if (inFile.is_open())
    {
        return true;
    }

    return false;
}

void readFile(ifstream &inFile, list<CD> &collection)
{
    string titleLine, artistLine;
    CD myCollection;
    while (!inFile.eof())
    {
        getline(inFile, titleLine);
        getline(inFile, artistLine);
        myCollection.title = titleLine;
        myCollection.bandName = artistLine;
        collection.push_back(myCollection);
    }
    cout << collection.size() << " records successfully loaded." << endl << endl;
}
