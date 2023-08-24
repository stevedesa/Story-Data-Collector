/** *****************************************************************
* @file
*
* @brief Contains function prototypes for our list and print to file 
*		function.
*******************************************************************/
/** **************************************************************************
 * @mainpage Take Home Programming Exam 2 - Word Frequency Singly Linked Lists
 *
 * @section course_section Course Information
 *
 * @author Steve de Sa, Tammy Nguyen, Parker Robinson, Donald Weigel
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC215 - M002 - Programming Techniques
 *
 * @par Location:
 *         Classroom Building CB327
 *
 * @date Due April 3rd, 2023
 *
 * @section program_section Program Information
 *
 * @details
 * The purpose of this program is the get the use familiar with singly linked
 * lists. This program will count how often a word appears in a document.
 * To do this, our team will design a class that utilizes linked lists to store
 * a word and count how often the word is found within the document. A word may
 * only be inserted into this list once and if it is found more than once, then
 * a frequency counter will be incremented for that word. 
 * 
 * After inserting the words from the document, there will be a specific output
 * required based on the user input. Any functions related to the the class 
 * list will be stored in the public section. Only the data will be stored
 * in the private section. Any other functions written will be outside of the
 * class list.
 * 
 * For start up, there will be 4 or 5 command line arguments provided.
 * The first being the program executable itself. The second will be the
 * document file to read the words from. The third will be the data file were
 * a list of words based on the first character will be outputted to. The 
 * fourth will be a file where frequency of words and lenght of words will be 
 * outputted to. The fifth argument is optional. If specified, it will output
 * based on the order of the string. If not specified, the program will output
 * the frequency of the words be default. -f will be for the frequency and -l
 * will be for the length. -lf will output the length and then the frequency.
 * -fl will output the frequency and then the length. If there is anything that
 * isnt allowed or a file that isn't a valid option, then the usage statment
 * provided a correct example will be outputted to the console screen.
 *
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
thpe12.exe inputFile.txt wordFileOutput.txt wordStatFile.txt [outputOption]

	inputFile.txt         Input file to read words from
	wordFileOutput.txt    Output file for the number of words in increasing order
	wordStatFile          Output file for frequency or length of words

Output Type      Output Description
	-l           Outputs a list of the length of the words from input file
	-f           Outputs the frequency of each word from input file
	-lf          Outputs the length of words followed by the frequency of the words
	-fl          Outputs the frequency of each word followed by the length of the words
   @endverbatim
 *
 *
 *@par Modifications and Development Timeline:
* This is a link to gitlab's commit as an example. To view <a target="_blank"
* href="https://gitlab.cse.sdsmt.edu/csc215/spring2023/team22/-/tree/master">click here.</a>
 *****************************************************************************/
#include "thpe12.h"

using namespace std;

#ifndef __WORDFREQ_H
#define __WORDFREQ_H

/**
* @brief Class that inserts, counts, and prints words from a document.
*		 Public has functions that work on the data from file.
*		 Private is where the data from file is stored.
*/
class wordFreqList
{
public:
	//parker
	void printFrequency ( ofstream& fout ); /**< Prints out the words that occur
											n number of times in input file in
											descending order. */

	//don
	void print(); /**< Prints out the list, using for testing. */
	bool remove ( string word ); /**< Removes word from the class list. */
	bool countFrequency ( string word ); /**< Counts the number of times a word
											occurs in the input file. */
	bool insert ( string word ); /**< Inserts current word being read in from
										input file into the list. */

	//steve
	int maxLength(); /**< Finds the max length of a word within the list. */
	void printLengths ( ostream& fout ); /**< Prints out the length of words that
											occur in the input file in
											descending order. */
	void printFirstChar ( ostream& fout ); /**< Prints out a list of words read in
											 from the input file in
											 alphabetical order. */
	void clear(); /**< Clears every node in the list. */

	//tami
	wordFreqList(); /**< Initializes a list. */
	~wordFreqList();/**< Deletes the list when function goes out of scope. */
	int maxFrequency(); /**< Finds the max occurence of words from the input
							 file. */
	bool find ( string word ) ; /**</ Finds the word in the list. */
	bool findFrequency ( int count ); /**< Finds the frequency of a node in the list. */

private:
	/**
	* @brief Holds data for items in the list.
	*/
	struct node 
	{
		string word; /**< A certain word that has been read in from input
							file. */
		int frequency; /**< The occurences of a certain word withing the input
							file. */
		node* next; /**< Next node within the list */
	};
	node* headptr; /**< First node in the list. */
};

void printToFile ( int argc, char **argv, wordFreqList &wordList, ofstream &fout, ofstream &stats );
#endif
