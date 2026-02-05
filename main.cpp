#include "merkov.h"

using namespace std;

int main(){
    srand(time(0));  //figured out that putting srand(time(0)) in the functions, you still get the same number everytime so I put it here (AI search) But I though the (time 0) is the number of seconds distanted from 1970, why does it matters?
    string filename;
    int order, numberWords;
    string words[2000], prefixes[1000], suffixes[1000]; /*after adjustment, this number have the best output. although I don't know why, but big numbers like 100000 in the text will lead you to bad output or even errors*/
    cout << "Insert the text file's name(Example: text.txt): ";
    cin >> filename;
     int count = readWordsFromFile(filename, words, 1000);
    while(count == 0){
        cout << "Invaild Filename! Please enter again!: ";
        cin >> filename;
        count = readWordsFromFile(filename, words, 1000);
    }
    cout << "Insert the order of the Markov Chain(1, 2,or 3): ";
    cin >> order;
       while(order != 1 && order != 2 && order != 3){
        cout << "Invaild order! Please enter again!: ";
        cin >> order;
    }
    cout << "Insert the number of words of your generated text: ";
    cin >> numberWords;
   
    int chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, numberWords);
    if(chainSize == 0){
        cout << "Insufficent data! Try again!";
        return 0;
    }
    cout << "-------------------Generating text---------------\n" << generateText(prefixes, suffixes, chainSize, order, 1000);

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

