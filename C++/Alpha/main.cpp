#include <iostream>

using namespace std;

int main()
{
    int alpha = 9, beta = 1;
    alpha = beta++;
    cout << alpha << beta;

    cout << "Hello world!" << endl;
    return 0;
}
