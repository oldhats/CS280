#include "RA_2_Submission.h"
#include <iostream>
#include <string>

#include "RA Submissions/RA_2_Submission.h"

int main() {
    RA_2_Submission submission; // Create an instance of the class
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;

    submission.processFile(filename); // Call the member function on the instance

    return 0;
}

