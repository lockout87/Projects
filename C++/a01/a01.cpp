//Sources: None.

#include <iostream> //Required for cout and cin
#include <string> //Required for string variables.
using namespace std; //gets rid of the need to use std::


int main(){
    string name, hometown, favFastFood, favWord;
    int age;            // The variables that will be used to hold the users answers..

    cout << "What is your name?";                                   // The questions and answers.
    cin >> name;
    cout << "What is your hometown?";
    cin >> hometown;
    cout << "What is your favorite fast food place?";
    cin >> favFastFood;
    cout << "How old are you?";
    cin >> age;
    cout << "What is your favorite word?";
    cin >> favWord;
    cout << endl << endl;

    cout <<  "Today in " << hometown << " four people have been attacked by a one eyed purple people eater." << endl;       // This section prints out the adlib.
    cout << name << ", " << age << ", was on scene at a local " << favFastFood << "." << endl;
    cout << name << " faught off the one eyed purple people eater with a spork, all the while screaming "<< favWord << "." << endl;

    return 0;
}
