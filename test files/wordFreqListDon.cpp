/** ***************************************************************************
 *  @file
 *  @brief  functions that donald made to be used in the program
 * 
 *  @author Donald Weigel
 *****************************************************************************/
#include "thpe12.h"
#include "wordFreq.h"



/** ***************************************************************************
 *  @author Donald Weigel
 * 
 *  @par Description counts the amount of times the given word shows up in a list
 * 
 *  @param word [in]  the word the function will look for
 * 
 *  @par Example
 *  @verbatim
    wordFreqList list;
	string word = "target";
	list.countFrequency( word );

	//the list's frequency be updated to how many times "target" appears
    @endverbatim 
 *****************************************************************************/
bool wordFreqList::countFrequency ( string word )
{
	node* ptrA = nullptr;

	//starts at beginning of list
	ptrA = headptr;
	//loops through list
	while( ptrA != nullptr )
	{
		//if target found increment frequency
		if( ptrA->word == word )
		{
			ptrA->frequency++;
			return true;
		}

		ptrA = ptrA->next;
	}

	return false;
}



/** ***************************************************************************
 *  @author Donald Weigel
 * 
 *  @par Description removes word from node when found
 * 
 *  @param word [in] word we want removed
 * 
 *  @returns true when word deleted, false when not deleted
 *  @par Example
 *  @verbatim
    wordFreqList list;
	string word = "target"
	list.insert( word );
	list.remove( word );

	//"target" should not be in list anymore.
    @endverbatim 
 *****************************************************************************/
bool wordFreqList::remove ( string word )
{
	node* ptrA = nullptr;
	node* temp;
	ptrA = headptr;

	//doesn't run if empty list
	if( headptr == nullptr )
		return false;

	//loops through list
	while(ptrA != nullptr )
	{
		//check if current pointer is target pointer
		if( ptrA->word == word )
		{
			if(ptrA == headptr )
			{
				//moves headptr over and deletes target
				headptr = headptr->next;
				delete ptrA;
				return true;
			}
		}

		//checks if word ptr after current ptr is target
		if( ptrA->next->word == word )
		{
			//declares target as temp
			temp = ptrA->next;
			//reassigns temp->next
			ptrA->next = temp->next;
			//delete target
			delete temp;
			return true;
		}
		ptrA = ptrA->next;
	}
	return false;
}



/** ***************************************************************************
 *  @author Donald Weigel
 * 
 *  @par Description adds a word to the list
 * 
 *  @param word [in] the word we want added to the list
 * 
 *  @returns true when successfully inserted, false when not successfully inserted.
 *  @par Example
 *  @verbatim
    wordFreqList list;
	string word = "target";
	list.insert( word );

	//"target" should now be inside the list
    @endverbatim 
 *****************************************************************************/
bool wordFreqList::insert( string word )
{
	node* ptrA = nullptr;
	node* ptrB = nullptr;
	node* Group = new( nothrow ) node;
	Group->frequency = 1;
	string temp;

	//check if built, return false if not build
	if( Group == nullptr )
		return false;

	//item is inserted here
	Group->next = nullptr;
	Group->word = word;

	//empty list check
	ptrA = headptr;
	if( ptrA == nullptr )
	{
		headptr = Group;
		return true;
	}

	ptrB = headptr;

	//traverses list and sorts as necessary
	while( ptrA != nullptr && word > ptrA->word )
	{
		ptrB = ptrA;
		ptrA = ptrA->next;
	}

	if(ptrA == headptr )
	{
		headptr = Group;
		Group->next = ptrA;
		return true;
	}

	ptrB->next = Group;
	Group->next = ptrA;

	
	return true;
}



/** ***************************************************************************
 *  @author Donald Weigel
 * 
 *  @par Description prints out the objects in a linked list
 * 
 * 
 *  @par Example
 *  @verbatim
    wordFreqList list;
	list.insert( "printme" );
	list.print( );

	//"printme" should now be viewable on the users screen.
    @endverbatim 
 *****************************************************************************/
void wordFreqList::print( )
{
	node* ptrA = nullptr;

	//starts at beginning of list
	ptrA = headptr;
	//loops through list
	while( ptrA != nullptr )
	{
		//prints item
		cout << ptrA->word;

		ptrA = ptrA->next;
		//ends line for easier testing/readability
		cout << endl;
	}
}