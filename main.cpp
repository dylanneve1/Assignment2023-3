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
}
