//
// Created by neved on 02/11/2023.
//

#include "TextAnalyser.h"
#include <iostream>
#include <fstream>

using namespace std;

void TextAnalyser::ReadFile(string filename) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        return;
    }
    string word;
    while (file >> word) {
        if (readIntoA) {
            listA.CountWord(word);
        } else {
            listB.CountWord(word);
        }
    }
}
