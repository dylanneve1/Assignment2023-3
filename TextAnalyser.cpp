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
    readIntoA = !readIntoA;
}

void TextAnalyser::Intersection() {
    if (!listC.IsEmpty()) {
        listC.DeleteAll();
    }
    Node *current = listA.Front();
    if(listB.Contains(current->word)) {
        Node *contained = listB.FindWord(current->word);
        int combined_count = current->count + contained->count;
        for (int i = 1; i <= combined_count; i++) {
            listC.CountWord(current->word);
        }
    }
    while (current->link != nullptr) {
        current = current->link;
        if(listB.Contains(current->word)) {
            Node *contained = listB.FindWord(current->word);
            int combined_count = current->count + contained->count;
            for (int i = 1; i <= combined_count; i++) {
                listC.CountWord(current->word);
            }
        }
    }
}

void TextAnalyser::Union() {
    if(!listC.IsEmpty()) {
        listC.DeleteAll();
    }
    Node *current = listA.Front();
    for (int i = 1; i <= current->count; i++) {
        listC.CountWord(current->word);
    }
    while (current->link != nullptr) {
        current = current->link;
        for (int i = 1; i <= current->count; i++) {
            listC.CountWord(current->word);
        }
    }
    current = listB.Front();
    for (int i = 1; i <= current->count; i++) {
        listC.CountWord(current->word);
    }
    while (current->link != nullptr) {
        current = current->link;
        for (int i = 1; i <= current->count; i++) {
            listC.CountWord(current->word);
        }
    }
}
