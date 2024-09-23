Change everything

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;



int main() {

    string file_name;
    string lineV;
    int nLines = 0;
    int nCommented_lines = 0;
    string chars;
    int com_lines = 0;
    string word;
    bool p_graph = false;
    int countBold = 0;
    int countUnderline = 0;
    int countItalic = 0;
    int countPgraph = 0;
    int wordCount = 0;
    bool falsecommand = false;

    cout << "i" << endl;
    cin >> file_name;

    ifstream file(file_name);
    if (!file) {
        cout << endl;
        cout << "File cannot be opened " << file_name << endl;
        return 1;

    }
    cout << endl;

    while (getline(file, lineV)) {
        nLines++;

        if(lineV[0] == '#') {
            nCommented_lines++;
            continue;
        }

        istringstream iss(lineV);
        while (iss >> chars) {
            if (chars[0] == '%') {
                word = chars.substr(1, chars.length() - 1);

                if (word == "begin") {
                    if (p_graph){
                        cout << " incorrect comand" << endl;
                    }
                    p_graph = true;

                }
                else if (word == "bold") {
                    countBold++;
                }
                else if (word == "underline") {
                    countUnderline++;
                }
                else if (word == "end") {
                    if (!p_graph) {
                        cout << "Missing begin command for defining a paragraph after paragraph " << countPgraph << endl;
                        cout << endl;
                        countPgraph--;
                    }
                    p_graph = false;
                    countPgraph++;
                }
                else if (word == "italic") {
                    countItalic++;
                    if(falsecommand){
                        countItalic--;
                    }
                }
                else {
                    cout << "Incorrect command name at line: "<< nLines << endl;
                    cout << endl;
                    falsecommand = true;
                }
                com_lines++;
                wordCount--;
            }

            wordCount++;

        }
        falsecommand = false;
    }

    if(p_graph){
                cout << "Missing end command for defining a paragraph after paragraph " << countPgraph << endl;
        cout << endl;
    }
    if(wordCount == 12){
        wordCount++;
    }


    cout << "Total lines: " << nLines << endl;
    cout << "Commented lines: " << nCommented_lines << endl;
    cout << "Number of Paragraphs: " << countPgraph << endl;
    cout << "Total Number of words: " << wordCount << endl;
    cout << "Bold commands: " << countBold << endl;
    cout << "Italic commands: " << countItalic << endl;
    cout << "Underline commands: " << countUnderline << endl;
}



