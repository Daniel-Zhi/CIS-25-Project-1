#include "merkov.h"

using namespace std;

int main(){
    srand(time(0));  //figured out that putting srand(time(0)) in the functions, you still get the same number everytime so I put it here (AI search) But I though the (time 0) is the number of seconds distanted from 1970, why does it matters?

    string words[10000], prefixes[5000], suffixes[5000]; /*after adjustment, this number have the best output. although I don't know why, but big numbers like 100000 in the text will lead you to bad output or even errors*/
    int count = readWordsFromFile("taylor.txt", words, 1000);
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 10000);
    cout << generateText(prefixes, suffixes, chainSize, 2, 1000);

    // string testWords[] = {"the", "cat", "sat", "down"};
    // cout << joinWords(testWords, 0, 2) << std::endl;  
    // cout << joinWords(testWords, 1, 3) << std::endl;

    // string words[1000];
    // int count = readWordsFromFile("test.txt", words, 1000);
    // cout << "Read " << count << " words" << endl;
    // for (int i = 0; i < 10 && i < count; i++) {
    // cout << words[i] << endl;
    // }

    // string prefixes[10000], suffixes[10000];
    // int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 10000);
    // for (int i = 0; i < 25 && i < chainSize; i++) {
    //     cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    // }

    // for (int i = 0; i < 10; i++) {
    // std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "Hi") << std::endl;
    // }

    // for (int i = 0; i < 5; i++) {
    // std::cout << getRandomPrefix(prefixes, chainSize) << std::endl;
    // }

    // std::string output = generateText(prefixes, suffixes, chainSize, 1, 20);
    // std::cout << output << std::endl;
}

