#include "CDCollection.h"

void sortMenu(list<CD> &collection)
{
    char select;
    bool endLoop = false;
    while (!endLoop)
    {
        cout << "Would you like to sort by (B)and or (T)itle, or leave the data (R)aw?" << endl;
        cin >> select;
        select = tolower(select);
        if (select == 'b')
        {
            collection.sort(sortBandThenTitle);
            endLoop = true;
        }
        else if (select == 't')
        {
            collection.sort(sortTitleThenBand);
            endLoop = true;
        }
        else if (select == 'r')
        {
            endLoop = true;
        }
    }
}

bool sortBandThenTitle(CD &first, CD &second)
{
    if (first.bandName != second.bandName)
    {
        return first.bandName < second.bandName;
    }
    else
    {
        return first.title < second.title;
    }
}

bool sortTitleThenBand (CD &first, CD &second)
{
    if (first.title != second.title)
    {
        return first.title < second.title;
    }
    else
    {
        return first.bandName < second.bandName;
    }
}

