#include "CDCollection.h"

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
