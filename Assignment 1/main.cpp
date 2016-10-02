//Author: Axel Garcia

#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int size = 30000;
string word[size];

int main(){
    string fileName;
    
    cout << "Enter the input filename: " << endl;
    cin >> fileName;
    
    fileIn(fileName, word);                             // /Users/axelgarcia/Downloads/words.txt
    
    bool done1 = false;
    
    while (!done1) {
        string enterLetters;
        cout <<endl;
        cout << "Please enter a string for an anagram (!exit to quit program): " << endl;
        cin >> enterLetters;
    
        bool done = false;
        while (!done) {
            if (enterLetters == "!exit") {
                cout << "Bye." << endl;
                done1 = true;
                done= true;
                }
            else{
                RecursivePermute("", enterLetters, word);
                done = true;
                }
        }
    }
    exit(0);
}


//Recursive function that permutes string
void RecurseLoop(int i, unsigned long max, string prefix, string suffix, string arr[]){
    
    if (i >= max) {
        return;
    }
    string updatedPrefix = prefix + suffix[i];
    string updatedSuffix = suffix.substr(0, i) + suffix.substr(i+1);
    RecursivePermute(updatedPrefix, updatedSuffix, arr);
    RecurseLoop(i+1, suffix.size(), prefix, suffix, arr);

}

void RecursivePermute(string prefix, string suffix, string arr[]){
    if (suffix.size() == 0) {
        match(prefix, arr);
    }
    else {
            RecurseLoop(0, suffix.size(), prefix, suffix, arr);
    }
}
//Recursive for reading in from file.
void inLoop(int initial, int max, string arr[], ifstream &file){
    if (initial >= max) {
        return;
    }
    file >> arr[initial];
    inLoop(initial + 1, max, arr, file);
}

void fileIn(string inLocation, string arr[]){
    ifstream infile(inLocation);
    if (!infile) {
        cerr << "Error, file " << inLocation << " could not be opened." << endl;
        exit(0);
    }
        inLoop(0, 30000, arr, infile);
}
//Recurive function that matches a prefix with a word in the dictionary if it is there.
void matchLoop(int i, int max, string arr[], string prefix){
    if (i > max) {
        return;
    }
    if (prefix == arr[i]) {
        cout << "Match: "<< prefix << endl;
    }
    matchLoop(i+1, max, arr, prefix);
}
void match(string prefix, string arr[]){
    matchLoop(0, 30000, arr, prefix);
}

