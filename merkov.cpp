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
    string temp[chainSize];
    int matchcount = 0/*the program is saying segementation fault and figured that I forgot to initialize the matchcount. Such improfessional mistake!!!(AI search)*/,tempcount = 0,pick;
    for(int i = 0; i < chainSize; i++){
        if (currentPrefix == prefixes[i]){
            matchcount++;
            temp[tempcount] = suffixes[i];
            tempcount++;
        }
    }
    if (matchcount == 0){
        return "";
    }
    pick = rand() % matchcount;
    return temp[pick];
}

string getRandomPrefix(const string prefixes[], int chainSize){
    int index = rand() % chainSize;
    return prefixes[index];
}

string generateText(const string prefixes[], const string suffixes[], int chainSize, int order/*I didn't even use it*/, int numWords){
    string textary[chainSize], currentPrefix, text;
    int count = 0;
    textary[count] = getRandomPrefix(prefixes, chainSize);/*(AI Search) reminded that there shouldn't be a {} here. Ai is scary*/
    text = textary[0];
    currentPrefix = textary[count];
    for(int i = 0;i < numWords && i < chainSize; i++){
        if(currentPrefix == prefixes[i])/*if currentPrefix mets the first element in prefixes[] that have the same value*/{
            for(int j = 0;j < numWords && j < chainSize; j++){
                if(j == numWords-1){
                    break;
                }/*(AI Search) reminded that there might be a out-of-bound here*/
                if((suffixes[j] == getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix)/*get the ransuffix of currentprefix, because in my version, the text is created from the suffixes, only needs suffix to be rand*/ && (currentPrefix == prefixes[j])) && j < chainSize){
                    currentPrefix = prefixes[j + 1]/*since from how we stored prefix, I noticed that the prefix[x + 1] is expressing the "drop the first word and add the new word" procedure in the text book, I hope I figured out a new way*/;
                    count++;
                    textary[count] = suffixes[j];
                }
            }
        }
    }
    for(int k = 1 ; k < count ; k++){
        text = text + " " + textary[k];/*notice that there are some weird spaces in my*/
    }
    return text;
}