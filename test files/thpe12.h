#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

#ifndef __THPE12__H
#define __THPE12__H
void usage( );
bool checkArg ( int argc );
void checkOpt ( char** argv );
bool openInput ( ifstream& file, string fileName );
bool openOutput ( ofstream& file, string fileName );
string removePunct( string word ); // tami  word prep, removes all punctuation from a word
#endif