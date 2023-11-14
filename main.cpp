#include <iostream>

#include "Node.h"
#include "TextAnalyser.h"
#include "UnsortedWordList.h"

int main() {
    TextAnalyser textAnalyser;
    UnsortedWordList list;
    textAnalyser.ReadFile("hitchhiker.txt");
    list = textAnalyser.listA;
    list.Print();
    cout << "Does the list contain 'the'? " << list.Contains("the") << endl;
    cout << "Does the list contain 'them'? " << list.Contains("them") << endl;
    Node *a = list.Front();
    Node *b = list.Back();
    cout << "First word is: " << a->word << endl;
    cout << "Last word is: " << b->word << endl;
}
