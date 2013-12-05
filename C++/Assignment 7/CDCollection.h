#ifndef CDCOLLECTION_H_INCLUDED
#define CDCOLLECTION_H_INCLUDED

#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

struct CD
{
    string title;
    string bandName;
};

bool openFile(ifstream &inFile, string inFileName);
void readFile(ifstream &inFile, list<CD> &collection);

void sortMenu(list<CD> &collection);
bool sortBandThenTitle(CD &first, CD &second);
bool sortTitleThenBand (CD &first, CD &second);

void searchByBand(list<CD> &collection);
void searchByTitle (list<CD> &collection);
void showAll (list<CD> &collection);

#endif // CDCOLLECTION_H_INCLUDED
