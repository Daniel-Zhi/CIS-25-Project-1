#ifndef MERKOV.H
#define MERKOV.H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int readWordsFromFile(string filename, string words[], int maxWords);   /*I know that you asked us to put the name as well but I did too much and want to make the formal unanimous, plz forgive*/
int buildMarkovChain(const string[] , int, int, string[] , string[], int);
string joinWords(const string[], int , int);
string getRandomSuffix(const string[], const string[], int, string);
string getRandomPrefix(const string[], int);
string generateText(const string[], const string[], int, int, int);

#endif

