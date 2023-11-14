//
// Created by neved on 02/11/2023.
//

#include "UnsortedWordList.h"

#include <iostream>

using namespace std;

#define LOG_DEBUG 0

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
    if (LOG_DEBUG) cout << "IsEmpty() = " << ret << endl;
    return ret;
}

int UnsortedWordList::Length() const {
    int ret;
    if (!first_word_set) {
        ret = 0;
    } else {
        ret = 1;
        Node *current = first;
        while (current->link != nullptr) {
            ret++;
            current = current->link;
        }
    }
    if (LOG_DEBUG) cout << "Length() = " << ret << endl;
    return ret;
}

Node *UnsortedWordList::Front() const {
    if (LOG_DEBUG) cout << "Front()" << endl;
    return first;
}

Node *UnsortedWordList::Back() const {
    if (LOG_DEBUG) cout << "Back()" << endl;
    return last;
}

bool UnsortedWordList::Contains(std::string word) {
    bool ret = false;
    if (!first_word_set) {
        return ret;
    }
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
    if (LOG_DEBUG) cout << "Contains(" << word << ") = " << ret << endl;
    return ret;
}

Node *UnsortedWordList::FindWord(std::string word) {
    if (LOG_DEBUG) cout << "FindWord(" << word << ")" << endl;
    if (first_word_set) {
        Node *current = first;

        if (current->word == word) {
            return current;
        }
        while (current->link != nullptr) {
            current = current->link;
            if (current->word == word) {
                return current;
            }
        }
    }
    return nullptr;
}

string UnsortedWordList::MaxWord() const {
    string ret;
    if (first_word_set) {
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
    } else {
        ret = "undefined";
    }
    if (LOG_DEBUG) cout << "MaxWord() = " << ret << endl;
    return ret;
}

int UnsortedWordList::MaxCount() const {
    int ret;
    if (!first_word_set) {
        ret = 0;
    } else {
        Node *current = first;
        Node *max = first;
        while (current->link != nullptr) {
            current = current->link;
            if (current->count > max->count) {
                max = current;
            }
        }
        ret = max->count;
    }
    if (LOG_DEBUG) cout << "MaxCount() = " << ret << endl;
    return ret;
}

void UnsortedWordList::Print() const {
    cout << "WordList(" << endl;
    cout << "length=" << Length() << endl;
    if (first_word_set) {
        cout << "Word(" << first->word << "," << first->count << ")" << endl;
        Node *current = first;
        while (current->link != nullptr) {
            current = current->link;
            cout << "Word(" << current->word << "," << current->count << ")" << endl;
        }
    }
    cout << ")" << endl;
}

void UnsortedWordList::CountWord(std::string word) {
    if (LOG_DEBUG) cout << "CountWord(" << word << ")" << endl;
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
    if (LOG_DEBUG) cout << "InsertFirst(" << word << ")" << endl;
    if (!first_word_set) {
        first = new Node(word, 1);
        first_word_set = true;
        last = first;
        return;
    }
    if (!Contains(word)) {
        Node *temp = first;
        first = new Node(word, 1);
        first->link = temp;
    } else {
        CountWord(word);
    }
}

void UnsortedWordList::DeleteAll() {
    if (LOG_DEBUG) cout << "DeleteAll()" << endl;
    if (!first_word_set) {
        return;
    }
    Node *current = first;
    while (current->link != nullptr) {
        Node *temp = current;
        current = current->link;
        delete temp;
    }
    delete current;
    first = nullptr;
    last = nullptr;
    first_word_set = false;
}

void UnsortedWordList::DeleteWord(std::string word) {
    if (LOG_DEBUG) cout << "DeleteWord(" << word << ")" << endl;
    if (!Contains(word)) {
        return;
    }
    Node *current = first;
    if (current->word == word) {
        first = current->link;
        delete current;
        return;
    }
    while (current->link != nullptr) {
        if (current->link->word == word) {
            if (current->link == last) {
                last = current;
            }
            Node *temp = current->link;
            current->link = current->link->link;
            delete temp;
            return;
        }
        current = current->link;
    }
}
