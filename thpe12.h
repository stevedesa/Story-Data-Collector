/** *****************************************************************
* @file
*
* @brief Contains function prototypes for functions that aren't related to 
*       the list such as file I/O, argument checking and removing punctiation.
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef __THPE12__H
#define __THPE12__H
void usage();
bool checkArg ( int argc );
void checkOpt ( char** argv );
bool openInput ( ifstream& file, string fileName );
bool openOutput ( ofstream& file, string fileName );
string removePunct( string word ); // tami  word prep, removes all punctuation from a word
#endif
