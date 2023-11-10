//
// Created by neved on 02/11/2023.
//

#ifndef ASSIGNMENT3_NODE_H
#define ASSIGNMENT3_NODE_H

#include <string>

using namespace std;

class Node {
public:
    Node(string newWord); // constructor with word
    Node(string newWord, int newCount); // constructor with word and count
    string word;
    int count = 0; // counts of occurrences for <word>
    Node *link = nullptr; // pointer to the next Node in the list
};

#endif //ASSIGNMENT3_NODE_H
