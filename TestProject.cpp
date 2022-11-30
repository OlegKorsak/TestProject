#include <vector>
#include <iostream>  
#include <fstream>
#include <string>

using namespace std;

const string fileName{ "TextForCheck.txt" };

int main() {

    ifstream fileForCheck;
    fileForCheck.open(fileName, ios::in);

    if (fileForCheck) {

        string temp;

        vector<string> words;

        while (fileForCheck >> temp) {

            bool isWordBeenSeen = false;

            for (unsigned int i = 0; i < words.size(); ++i) {
                if (temp == words[i]) {
                    isWordBeenSeen = true;
                    break;
                }
            }
            if (!isWordBeenSeen) {
                words.push_back(temp);
            }
        }
        cout << "Amount of unique words: " << words.size();
    }
    else {
        cerr << "\nCould not open file '" << fileName << "'\n";
    }
}
