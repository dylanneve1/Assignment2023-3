//
// Created by neved on 02/11/2023.
//

#include "UnsortedWordList.h"

#include <iostream>

using namespace std;

UnsortedWordList::UnsortedWordList() {
}

UnsortedWordList::~UnsortedWordList() {
}

bool UnsortedWordList::IsEmpty() const {
    bool ret;
    if (!first_word_set) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

int UnsortedWordList::Length() const {
    if (!first_word_set) {
        return 0;
    }
    int ret = 1;
    Node *current = first;
    while (current->link != nullptr) {
        ret++;
        current = current->link;
    }
    return ret;
}

Node *UnsortedWordList::Front() const {
    Node *ret;
    ret = first;
    return ret;
}

Node *UnsortedWordList::Back() const {
    Node *ret;
    ret = last;
    return ret;
}

bool UnsortedWordList::Contains(std::string word) {
    bool ret = false;
    // check if the list contains <word>
    Node *current = first;
    if (current->word == word) {
        ret = true;
    }
    while (current->link != nullptr) {
        current = current->link;
        if (current->word == word) {
            ret = true;
            break;
        }
    }
    return ret;
}

Node *UnsortedWordList::FindWord(std::string word) {
    Node *ret;
    Node *current = first;
    if (current->word == word) {
        ret = current;
    }
    while (current->link != nullptr) {
        current = current->link;
        if (current->word == word) {
            ret = current;
            break;
        }
    }
    return ret;
}

string UnsortedWordList::MaxWord() const {
    string ret;
    Node *current = first;
    Node *max = first;
    bool double_count = false;

    while (current->link != nullptr) {
        current = current->link;
        if (current->count > max->count) {
            max = current;
            double_count = false;
        } else if (current->count == max->count) {
            double_count = true;
        }
    }
    if (double_count) {
        ret = "undefined";
    } else {
        ret = max->word;
    }
    return ret;
}

int UnsortedWordList::MaxCount() const {
    int ret;
    Node *current = first;
    Node *max = first;
    while (current->link != nullptr) {
        current = current->link;
        if (current->count > max->count) {
            max = current;
        }
    }
    ret = max->count;
    return ret;
}

void UnsortedWordList::Print() const {
    cout << "WordList(" << endl;
    cout << "length=" << Length() << endl;
    cout << "Word(" << first->word << "," << first->count << ")" << endl;
    Node *current = first;
    while (current->link != nullptr) {
        current = current->link;
        cout << "Word(" << current->word << "," << current->count << ")" << endl;
    }
    cout << ")" << endl;
}

void UnsortedWordList::CountWord(std::string word) {
    if (!first_word_set) {
        first = new Node(word, 1);
        first_word_set = true;
        last = first;
        return;
    }
    if (!Contains(word)) {
        Node *current = first;
        if (current->link == nullptr) {
            current->link = new Node(word, 1);
            last = current->link;
        } else {
            while (current->link != nullptr) {
                current = current->link;
            }
            current->link = new Node(word, 1);
            last = current->link;
        }
    } else {
        Node *current = FindWord(word);
        current->count++;
    }
}

void UnsortedWordList::InsertFirst(std::string word) {
}

void UnsortedWordList::DeleteAll() {
}

void UnsortedWordList::DeleteWord(std::string word) {
}
