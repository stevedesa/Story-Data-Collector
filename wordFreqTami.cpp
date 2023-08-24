/** ***************************************************************************
 * @file
 * 
 * @brief Constructor and destructor, also includes maxFrequency
 * and find functions.
 *****************************************************************************/
#include "wordFreq.h"

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



/** ***************************************************************************
 * @author Tammy Nguyen
 *
 * @par Description
 * Finds the max frequency within a list.
 *
 * @returns An integer which will be the max frequency
 *
 * @par Example
 * @verbatim
   int result;
   wordFreqList list;
   list.insert("woop woop");

   result = list.maxFrequency(); // result will be 1

   list.insert("woop woop");
   result = list.maxFrequency(); // result will be 2

   list.insert("eeek");
   result = list.maxFrequency(); // result will still be 2
   
   @endverbatim
 *****************************************************************************/
int wordFreqList::maxFrequency( )
{
	int max;
	node *temp = nullptr;
	temp = headptr;
	max = headptr->frequency; 
	// sets max to be the frequency of the first node initially

	while (temp != nullptr)
	{
		// if the current node's frequency is greater than current max, new max
		if (temp->frequency > max)
			max = temp->frequency;
		temp = temp->next; // move temp down
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

	temp = headptr; //starts looking at the first node
	for (i = 0; temp != nullptr; i++)
	{
		//traverses through the list to find the word
		if (temp->word == word)
			return true;
		// if it found it, return true
		// if not, keep traversing through the list
		temp = temp->next;
	}
	// reached the end of the list, didn't find the word. return false
	return false;
}



/** ***************************************************************************
 * @author Tammy Nguyen
 *
 * @par Description
 * Finds if a certain count is already in the list.
 *
 * @returns a bool. True if it's in the list, false if not
 *
 * @param[in] count - the count it will find
 *
 * @par Example
 * @verbatim
   wordFreqList words;
   words.find(5); // list is empty, returns false

   words.insert("nice!"); // list has one item
   words.findFrequency(1); // returns true

   @endverbatim
 *****************************************************************************/
bool wordFreqList::findFrequency ( int count )
{
	int i;
	node *temp = nullptr;
	
	temp = headptr; //starts at the first node
	for (i = 0; temp != nullptr; i++)
	{
		//traverses through the list to find the frequency
		if (temp->frequency == count)
			return true;
		//if it found it, return true
		//if not, keep traversing through the list
		temp = temp->next;
	}
	//reached the end of the list and didn't find it, return false
	return false;
}
