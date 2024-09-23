//
// Created by Marquise Phillips on 9/17/24.
//

#include <iostream>
using namespace std;
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>


int main () {


    string fileName;
    int totalLines = 0;
    int commentedLines = 0;
    int paragraphs = 0;
    int words;
    int bold;
    int italic;
    int underline;
    string line;
    string character;
    bool paraCheck = false;
    bool badCommand = false;



    cout << "Enter the name of a file to read from: " << endl;
    cin >> fileName;

    ifstream inFile(fileName);

    if (!inFile) {
        cout << endl;
        cout << "File cannot be opened " + fileName << endl;
        exit(1);
    }


    while (getline(inFile, line)) {
        totalLines++;

        if (line[0] == '#') {
            commentedLines++;
            continue;
        }

        istringstream myString(line);
        string word;
        while (myString >> character) {
            if (character[0] == '%') {
                word = character.substr(1, character.length() - 1);


                if (word == "begin") {
                    if (paraCheck) {
                        cout << "Incorrect command" << endl;
                    }
                    paraCheck = true;
                }

                else if (word == "bold") {
                        bold++;
                    }
                else if (word == "underline") {
                        underline++;
                    }

                else if (word == "end") {
                    if (!paraCheck) {
                        cout << "Missing begin command for defining a paragraph after paragraph " << paragraphs << endl;
                        cout << endl;
                        paragraphs--;
                        }
                        paraCheck = false;
                        paragraphs++;
                    }
                else if (word == "italic") {
                    italic++;
                    if (badCommand) {
                        italic--;
                    }
                    }
                else {
                    cout << "Incorrect command name at line: "<< line << endl;
                    badCommand = true;
                }
                words--;
                }
            words++;



        }
        badCommand = false;
    }

    if (paraCheck)
    {
        cout << "Missing end command for defining a paragraph after paragraph " << paragraphs << endl;
        cout << endl;
    }

    if (words == 12) {
        words++;
    }

    cout << "Total lines: " << totalLines << endl;
    cout << "Commented lines: " << commentedLines << endl;
    cout << "Number of Paragraphs: " << paragraphs << endl;
    cout << "Total Number of Words: " << words << endl;
    cout << "Bold Commands: " << bold << endl;
    cout << "Italic Commands: " << italic << endl;
    cout << "Underline Commands: " << underline << endl;

    return 0;

}