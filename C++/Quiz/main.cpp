#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ()
{
    srand(time(0));
    int num;


    for (int i =0; i<50; i++)
    {num = rand() % 50; cout << num << endl;}



    return 0;
}
