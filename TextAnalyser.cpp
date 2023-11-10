//
// Created by neved on 02/11/2023.
//

#include "TextAnalyser.h"
#include <iostream>
#include <fstream>

using namespace std;

void TextAnalyser::ReadFile(string filename) {
    cout << "TextAnalyser::ReadFile, filename='" << filename << "'." << endl;
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "unable to open file with filename='" << filename << "'." << endl;
        return;
    }
    string word;
    // TODO if necessary add code here
    while (file >> word) {
        // TODO replace with code that handles each word
        cout << "word:" << word << endl;
    }
    // TODO if necessary add code here
}
