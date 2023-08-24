/** *****************************************************************
* @file
*
* @brief Contains the printFrequency function.
*******************************************************************/
#include "wordFreq.h"

/** **********************************************************************
 *  @author Parker Robinson
 *
 *  @par Description
 * Outputs words based on frequency in input file in decending order.
 *
 *  @param[in] fout Output file location
 *
 *  @par Example
 *  @verbatim
    if( argc[4] == "-f")
    {
        printFrequency(statFile);
    }
    @endverbatim
 ************************************************************************/
void wordFreqList::printFrequency(ofstream& fout)
{
    node* temp = nullptr;
    temp = headptr;
    int i = 0; //for mod3 for endl
    int count = 0; //for comparing and forloop 

    for (count = maxFrequency(); count > 0; count--) //while not at end of list
    { //while frequency of word == count of freq of word
        if (findFrequency(count) == true)
        { //output header
            fout << "*********************************************************"
                << "***********************" << endl;
            fout << "* Frequency " << count << endl;
            fout << "*********************************************************"
                << "***********************" << endl;

            i = 0;//setting i to 0 for specific count

            while (temp != nullptr) //while not at end
            {
                if (temp->frequency == count) //if freq==count
                {
                    fout << left << setw(30) << temp->word; //output word
                    i++; //increment i for words per line

                    if (i % 3 == 0) //mod for loop for endl
                    {
                        fout << endl;
                    }
                }
                temp = temp->next; //move temp down
            }
            if (i % 3 != 0) //formatting for look
            {
                fout << endl; 
            }
            fout << endl;//formatting for look
        }
        temp = headptr; //temp back to front
    }
    fout << endl; //outout newline before length if option is -fl
}