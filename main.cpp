#include <iostream>

#include "Node.h"
#include "TextAnalyser.h"
#include "UnsortedWordList.h"

int main() {
    TextAnalyser textAnalyser;
    textAnalyser.ReadFile("hitchhiker.txt");
    textAnalyser.ReadFile("rings.txt");
    textAnalyser.Intersection();
    textAnalyser.listC.Print();
    textAnalyser.Union();
    textAnalyser.listC.Print();
}
