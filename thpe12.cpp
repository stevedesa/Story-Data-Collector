/** *****************************************************************
* @file
*
* @brief Contains main function for input and output using functions written
 *      to complete program.
*******************************************************************/
#include "thpe12.h"
#include "wordFreq.h"


/** **********************************************************************
 *  @author Steve da Sa, Tammy Nguyen, Parker Robinson, Donald Weigel
 *
 *  @par Description
 *  Main function. Utilizes functions written to complete program 
 *  assignment.
 *
 *  @param[in] argc Number of command line arguments from user.
 *  @param[in] argv String values of command line arguments
 * 
 * @returns Returns a 0 upon correct runtime, returns error message and usage
 *          statement upon error in files or command line arguments.
 *
 *  @par Example
 *  @verbatim
    thpe12.exe inputFile.txt wordFileOutput.txt wordStatFile.txt [outputOption]
    @endverbatim
 ************************************************************************/
int main ( int argc, char** argv )
{
    string inputFile, dataFile, statFile; //file names
    string outputType; // this is for the 2 letters 'f' and 'l'
    string word, newWord; //strings for input and removePunct words
    wordFreqList list; //lis

    ifstream readFile; //input file
    ofstream wordFile, freqLengFile; //output files

    if (checkArg ( argc ) == true ) //check command line args
    {
        inputFile = argv[1]; //file to read from
        dataFile = argv[2]; //output in increasing order no matter what
        statFile = argv[3]; //based on l/f, default is output by frequency

        if ( openInput ( readFile, inputFile ) == true ) //open input file
        {
            while ( readFile >> word ) //while it is reading in data
            {
                newWord = removePunct ( word ); //remove punctuation + lowercase

                //if the newWord string isn't empty and it doesn't find a duplicate word
                if ( !newWord.empty() && !list.countFrequency ( newWord ))
                {
                    if (!list.insert( newWord ))
                    {
                        cout << "Unable to allocate memory"; //memory error
                        return 0;
                    }
                }
            }
            if ( openOutput ( wordFile, dataFile ) == true && 
                openOutput ( freqLengFile, statFile ) == true ) //open output files
            {
                printToFile ( argc, argv, list, wordFile, freqLengFile ); //print
            }
            else //files not opening
            {
                usage(); //output usage if output files dont open
            }
        }
    }
    else //if args fail, output usage and exit
    {
        usage();
    }
    return 0;
}
