//
// Created by Marquise on 9/7/2024.
//

// Name: Welcome Message
// Description: Welcomes a student to CS280


#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
    string firstName;
    cout << "Please enter your first name >>" << endl;
    cin >> firstName;
    string lastName;
    cout << "Please enter your last name >>" << endl;
    cin >> lastName;
    int sectionNumber;
    cout << "Please enter your CS 280 section number >>" << endl;
    cin >> sectionNumber;

    cout << "Welcome " << firstName << " to CS 280 section " << sectionNumber << endl;




    return 0;
}
