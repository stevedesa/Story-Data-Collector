#include "thpe12.h"
#include "wordFreq.h"
//add code here.

/** ***************************************************************************
 * @author Tammy Nguyen
 *
 * @par Description
 * Initializes headptr to null when an object is created.
 *
 * @par Example
 * @verbatim
   wordFreqList words; // the object "words" is created and headptr is nullptr.
   @endverbatim
 *****************************************************************************/
wordFreqList::wordFreqList( )
{
	headptr = nullptr; // begins with an empty list
}

/** ***************************************************************************
 * @author Tammy Nguyen
 *
 * @par Description
 * Frees up the nodes once.
 *
 * @par Example
 * @verbatim
   wordFreqList words;
   // once the object goes out of scope, it'll free up the nodes
   @endverbatim
 *****************************************************************************/
wordFreqList::~wordFreqList( )
{
	node* temp = nullptr;
	temp = headptr;	// temp will always be the first node
	while (temp != nullptr)
	{
		headptr = temp->next;
		delete temp; // deletes the first node until empty
		temp = headptr;
	}
}

int wordFreqList::maxFrequency( )
{
	int max;
	node* temp = nullptr;
	temp = headptr;
	max = headptr->frequency;
	// sets max to be the frequency of the first node initially

	while (temp != nullptr)
	{
		// if the current node's frequency is greater than current max, new max
		if (temp->frequency > max)
			max = temp->frequency;
		temp = temp->next;
	}

	return max;
}

/** ***************************************************************************
 * @author Tammy Nguyen
 *
 * @par Description
 * Finds if the word is already in the list.
 *
 * @returns a bool. True if it's in the list, false if not
 *
 * @param[in] word - the word it will find
 *
 * @par Example
 * @verbatim
   wordFreqList words;
   words.find("woo"); // list is empty, returns false

   words.insert("nice!"); // list has one item
   words.find("nice!"); // returns true

   @endverbatim
 *****************************************************************************/
bool wordFreqList::find( string word )
{
	int i;
	node* temp = nullptr;

	temp = headptr;
	for (i = 0; temp != nullptr; i++)
	{
		if (temp->word == word)
			return true;
		temp = temp->next;
	}
	return false;
}

string removePunct( string word )
{
	int i, begin, end, newSize;
	begin = 0;
	end = int( word.size( ) ) - 1;

	string newString;
	// """"wack"""" begin = 4, end = 7, newsize = 4
	// "chin." begin = 1, end = 4, newsize = 4

	// finds the beginning position of the new word
	for (i = 0; i < word.size( ) && ispunct( word[i] ); i++)
		begin = i + 1;

	// finds the end position of the new word
	for (i = end; i < word.size( ) && ispunct( word[i] ); i--)
		end = i - 1;

	newSize = (end - begin) + 1;
	newString = word.substr( begin, newSize );

	transform ( newString.begin( ), newString.end( ), newString.begin( ), tolower );
	// makes it all lowercase and returns it
	return newString;
}
