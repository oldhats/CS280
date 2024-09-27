//
// Created by Marquise on 9/26/2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <regex>

using namespace std;



int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "NO SPECIFIED INPUT FILE NAME." << endl;
        return 1;
    }

    string fileName = argv[1];
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "CANNOT OPEN THE FILE " << fileName << endl;
        return 1;
    }

    if (inputFile) {
        inputFile.seekg(0, ios::end);
        int length = inputFile.tellg();

        if (length <= 0) {
            cerr << "File is empty." << endl;
            return 1;
        }
        inputFile.seekg(0, ios::beg);  // reset to the beginning after checking size
    }

    int lineCount = 0;
    int wordCount = 0;
    int decimalLitCount = 0;
    int hexadecimalLitCount = 0;
    int octalLitCount = 0;
    int binaryLitCount = 0;

    string line;
    while (getline(inputFile, line)) {
        lineCount++;

        istringstream lineStream(line);
        string word;

        while (lineStream >> word) {
            wordCount++;

            if (!isdigit(word[0])) {
                continue;
            }


            //
            if (regex_match(word, regex("[1-9]+"))) { // checking prefix

                if (regex_match(word, regex("[0-9]*"))) { // check for decimal literal
                    decimalLitCount++;
                }

                else {
                    cerr << "Incorrect Decimal Literal " << word << "at Line: " << lineCount << endl;
                }

            } else if (regex_match(word, regex("0"))) {
                // checking prefix

                if (regex_match(word, regex("[0-7]*"))) { // check for octal Literal
                    octalLitCount++;
                }

                else {
                    cerr << "Incorrect Octal Literal " << word << "at Line: " << lineCount << endl;
                }
            } else if (regex_match(word, regex("0[x|X]+"))) {

                if (regex_match(word, regex("0[x|X][0-9a-fA-F]+"))) { // check for hex literal
                    hexadecimalLitCount++;
                }

                else {
                    cerr << "Incorrect Hex Literal " << word << "at Line: " << lineCount << endl;
                }

            } else if (regex_match(word, regex("0[b|B]+"))) {

                if (regex_match(word, regex("0[bB][0-1]+"))) { // check for binary literal
                            binaryLitCount++;
                        }
                else {
                            cerr << "Incorrect Binary Literal " << word << "at Line: " << lineCount << endl;
                        }
                    }
                }




        inputFile.close();

        // Output the counts
        cout << "Total Number Of Lines: " << lineCount << endl;
        cout << "Number of Words: " << wordCount << endl;
        cout << "Number of Decimal Literals: " << decimalLitCount << endl;
        cout << "Number of Hexadecimal Literals: " << hexadecimalLitCount << endl;
        cout << "Number of Octal Literals: " << octalLitCount << endl;
        cout << "Number of Binary Literals: " << binaryLitCount << endl;

        return 0;
    }
}

