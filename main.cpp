#include "merkov.h"

using namespace std;

int main(){
    // string words[1000], prefixes[10000], suffixes[10000];
    // int count = readwordsFromFile("taylor.txt", words, 1000);
    // int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);
    // cout << generateText(prefixes, suffixes, chainSize, 1, count);
    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << std::endl;  // Should print: the cat
    cout << joinWords(testWords, 1, 3) << std::endl;

}

