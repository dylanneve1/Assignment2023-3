//
// Created by neved on 02/11/2023.
//

#include "Node.h"

// constructor with word
Node::Node(string newWord) {
    word = newWord;
}

// constructor with word and count
Node::Node(string newWord, int newCount) {
    word = newWord;
    count = newCount;
}
