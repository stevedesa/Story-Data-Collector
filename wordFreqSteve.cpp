/** *****************************************************************
* @file
*
* @brief Includes Functions Written By Team Member: Steve Nathan de Sa
*******************************************************************/

#include "wordFreq.h"
#include "thpe12.h"

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @brief This functions prints words into the output data file based on the 
 *  decreasing order of length with which the words appear in the story.
 *
 *  @param[in] fout Output file stream.
 *
 *  @par Example
 *  @verbatim
    if( argc[4] == "-l")
    {
        printLengths(statFile); //Prints out stats by length to statFile.
    }
    @endverbatim
 ************************************************************************/
void wordFreqList::printLengths(ostream& fout)
{
    int i, count;
    bool found = false; //is true when word of length x is found in list
    node* curr = nullptr;
    int max = maxLength();

    for ( i = max; i > 0 ; i-- )
    {
        curr = headptr;
        found = false;

        while ( curr != nullptr )
        {
            if ( int((curr->word).length()) == i )
            {
                found = true;
            }
            curr = curr->next;
        }

        if ( found == true ) //runs only if words of length x exist
        {
            fout << "********************************************************************************" << endl;
            fout << "* length of " << i << endl;
            fout << "********************************************************************************" << endl;

            count = 0;
            curr = headptr;

            while( curr!= nullptr )
            {
                if ( int((curr->word).length()) == i )
                {
                    fout << left << setw(30) << curr->word;
                    count++;

                    if (count == 3)
                    {
                        fout << endl;
                        count = 0;
                    }
                }

                curr = curr->next;
            }
            
            if ( count != 0 )
            {
                fout << endl;
            }

            fout << "\n"; //inserts line space after each length print
        }
    }
}

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @brief This functions prints all words into the output data which start
 *  with a particular first character. Stats are displayed in increasing
 *  order of first character.
 *
 *  @param[in] fout Output file stream.
 *
 *  @par Example
 *  @verbatim
    if( argv == 3 )
    {
        printFirstChar(filefile); //Prints out stats by firstchar to filefile.
    }
    @endverbatim
 ************************************************************************/
void wordFreqList::printFirstChar(ostream& fout)
{
    int i, count;
    bool found = false; //is true when word of char x is found in list

    node* curr = nullptr;

    for ( i = 97; i <= 122; i++ )
    {
        curr = headptr;
        found = false;

        while ( curr != nullptr )
        {
            if ( int(curr->word[0]) == i )
            {
                found = true;
            }

            curr = curr->next;
        }

        if ( found == true ) //runs only if words of char x exist
        {
            fout << "********************************************************************************" << endl;
            fout << "* words starting with " << char(i) << endl;
            fout << "********************************************************************************" << endl;

            count = 0;
            curr = headptr;

            while (curr != nullptr)
            {
                if ( int(curr->word[0]) == i )
                {
                    fout << left << setw(30) << curr->word;
                    count++;

                    if (count == 3)
                    {
                        fout << endl;
                        count = 0;
                    }
                }

                curr = curr->next;
            }

            if ( count != 0 )
            {
                fout << endl;
            }

            fout << "\n"; //inserts line space after each char print
        }
    }
}

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @brief Clears all the nodes in the created linked list.
 *
 *  @par Example
 *  @verbatim
    wordFreqList L;
    L.insert(); //Inserts elements into the linked list.
    L.clear(); //Clears the linked list.
    bool emp = L.empty(); //Will be false as the list has been cleared.
    @endverbatim
 ************************************************************************/
void wordFreqList::clear()
{
    node* curr = headptr;

    while ( curr != nullptr )
    {
        node* unk = curr;
        curr = curr->next;
        delete unk;
    }

    headptr = nullptr;
}

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @brief This functions traverses through the linked list and find the max
 *  length from all the words in the linked list. This is vital for the 
 *  print functions
 * 
 *  @returns the maximum length from all the words in the list.
 *
 *  @par Example
 *  @verbatim
    wordFreqList List;
    int max = List.maxLength(); //gives max length from list words
    @endverbatim
 ************************************************************************/
int wordFreqList::maxLength( )
{
    node* curr = headptr;
    int max = int(curr->word.length());

    while ( curr != nullptr )
    {
        if ( int(curr->word.length()) > max )
        {
            max = int(curr->word.length());
        }
        curr = curr->next;
    }

    return max;
}
