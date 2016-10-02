//
//  Header.h
//  Assignment 1
//
//  Created by Axel Garcia on 9/9/16.
//  Copyright © 2016 Axel Garcia. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void RecursivePermute(string prefix, string suffix, string arr[]);
void RecurseLoop(int i, unsigned long max, string prefix, string suffix, string arr[]);
void fileIn(string inLocation, string arr[]);
void inLoop(int initial, int max, string arr[], ifstream &file);
void matchLoop(int i, int max, string arr[], string prefix);
void match(string prefix, string arr[]);
#endif /* Header_h */
