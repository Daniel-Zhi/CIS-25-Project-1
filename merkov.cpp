#include "merkov.h"



int readWordsFromFile(string filename, string words[], int maxWords){
    ifstream infile;
    int counter = 0;
    infile.open(filename);
    for(; counter < maxWords && infile >> words[counter] ; counter++){
    }
    return counter;
}

string joinWords(const string words[], int startIndex, int count){
    // string jointWords = words[startIndex];
    // if(count > 1){
    // jointWords = jointWords + " " + words[startIndex + count - 1];
    string jointWords = words[startIndex];
    for(int i = 1; i <= count - 1; i++){
        jointWords = jointWords + " " + words[startIndex + i];
    }
    return jointWords;
}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], int maxChainSize){
    int count = 0;
    for(int i = 0 ; i < numWords - order && i < maxChainSize; i++){
        prefixes[count/* usually i but it is required for count*/] = joinWords(words, i, order);
        suffixes[count/* usually i but it is required for count*/] = words[i + order];
        count++;
    }
    return count;
}

string getRandomSuffix(const string prefixes[], const string suffixes[],int chainSize, string currentPrefix){
    srand(time(0));
    string temp[chainSize];
    int matchcount,tempcount=0,pick;
    for(int i = 0; i < chainSize; i++){
        if (currentPrefix == prefixes[i]){
            matchcount++;
            temp[tempcount++] = suffixes[i];
        }
    }
    if (matchcount == 0){
        return "";
    }
    pick = rand() % matchcount;
    return temp[pick];
}

string getRandomPrefix(const string prefixes[], int chainSize){
    srand(time(0));
    int index = rand() % chainSize;
    return prefixes[index];
}

string generateText(const string prefixes[], const string suffixes[], int chainSize, int order, int numWords){
    string textary[chainSize], currentPrefix, text;
    int count = 0;
    textary[count] = {getRandomPrefix(prefixes, chainSize)};
    currentPrefix = textary[count];
    for(int i = 0;i < numWords && i < chainSize; i++){
        if(currentPrefix == prefixes[i]){
            for(int j = 0;j < numWords && j < chainSize; j++){
                if((suffixes[j] == getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix) && (currentPrefix == prefixes[j])) && j < chainSize){
                    currentPrefix = prefixes[j + 1];
                    count++;
                    textary[count] = suffixes[j];
                }
            }
        }
    }
    for(int k=0;k < numWords && k < chainSize; k++){
        text = text + " " + text[k];
    }
    return text;
}