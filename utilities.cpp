/** *****************************************************************
* @file
*
* @brief Contains functions that don't deal will the list. Usage, argument
*       checking, I/O and remove punctuation.
*******************************************************************/
#include "thpe12.h"
#include "wordFreq.h"

/** **********************************************************************
 *  @author Parker Robinson
 *  @par Description
 * Outputs usage statement providing info fields and exits program.
 *
 *  @par Example
 *  @verbatim
    if(argc != 4 || argc != 5) //incorrect number of arguments given
    {
        usage();
    }
    @endverbatim
 ************************************************************************/
void usage() //usage statement
{
    cout << "thpe12.exe inputFile.txt wordFileOutput.txt wordStatFile.txt ";
    cout << "[outputOption]"
        << "\n\n    inputFile.txt         Input file to read words from"
        << "\n    wordFileOutput.txt    Output file for the number of"
        << " words in increasing order"

        << "\n    wordStatFile          Output file for frequency or length"
        << " of words"
        << "\n\n" << "Output Type      Output Description"
        << "\n    -l           Outputs a list of the length of the words from"
        << " input file"
        << "\n    -f           Outputs the frequency of each word from input"
        << " file"
        << "\n    -lf          Outputs the length of words followed by the "
        << "frequency of the words"
        << "\n    -fl          Outputs the frequency of each word followed by"
        << " the length of the words\n";
}


/** **********************************************************************
 *  @author Parker Robinson
 *
 *  @par Description
 * Checks the number of command line arguments from user.
 *
 *  @returns True if correct number is specified. False if incorrect.
 *
 *  @param[in] argc Number of arguments
 *
 *  @par Example
 *  @verbatim
    argc = 4;

    bool value;
    value = checkArg(argc, argv);

    value == true;

    @endverbatim
 ************************************************************************/
bool checkArg(int argc)
{
    if (argc != 4 && argc != 5) //if arg is not 4 or 5
    {
        return false; //return false
    }
    else
    {
        return true; //return true
    }
}


/** **********************************************************************
 *  @author Parker Robinson
 *
 *  @par Description
 * Checks the desired output file type. Exits program upon incorrect type
 *       and outputs usage.
 *
 *  @param[in] argv number of arguments
 *
 *  @par Example
 *  @verbatim
    checkType(argc, argv);
    @endverbatim
 ************************************************************************/
void checkOpt(char** argv)
{
    string output;
    output = argv[4]; //assign option to string

    //checking is tring has a correct input value
    if (output != "-l" && output != "-f" && output != "-lf" && output != "-fl")
    {
        cout << "Invalid output option." << endl; //output invalid option
        usage(); //output usage and exit
        exit(0);
    }
}


/** **********************************************************************
 *  @author Parker Robinson
 *
 *  @par Description
 * Opens input file to read from
 *
 *  @returns True if file opened, false if file didn't open
 *
 *  @param[in] file file for input
 *  @param[in] fileName name of file to open
 *
 *  @par Example
 *  @verbatim
 *
    ofstream fout;
    bool isTrue = openInput(file, "doesNotexit.txt");

    REQUIRE(isTrue == false);

    @endverbatim
 ************************************************************************/
bool openInput(ifstream& file, string fileName)
{
    file.open(fileName); //open input file

    if (file.is_open() == true) //if file is open, return true
    {
        return true;
    }
    else //if file isnt open, output usage and return false
    {
        usage();
        return false;
    }
    return false;
}

/** **********************************************************************
 *  @author Parker Robinson
 *
 *  @par Description
 *  Opens output files to write to.
 *
 *  @returns True if file opened, false if file didn't open
 *
 *  @param[out] file file for output
 *  @param[in] fileName name of file for output
 *
 *  @par Example
 *  @verbatim
 *
    ofstream fout;
    bool isTrue = openOut(fout, "notValidOuput.txt");

    REQUIRE(isTrue == false);

    @endverbatim
 ************************************************************************/
bool openOutput(ofstream& file, string fileName)
{
    file.open(fileName); //open output file

    if (file.is_open() == true) //if file opened, return true
    {
        return true;
    }
    else //if file didnt open, output usage and return false
    {
        usage();
        return false;
    }
    return false;
}

/** **********************************************************************
 *  @author Tammy Nguyen
 *
 *  @par Removes punctuation from the start and makes it lower case.
 *
 *  @returns A string that is all lower case and has no punctuation.
 *
 *  @param[in] word - the word that needs to be prepped
 *
 *  @par Example
 *  @verbatim
 *  string word = "'ex-wife'";
 *  string result;
 *  
 *  result = removePunct(word); // result is now ex-wife
 *  
 *  word = "Chin.";
 *  result = removePunct(word); // result is now chin
 * 
 *  word = "Chicago-based??";
 *  result = removePunct(word); // result is now Chicago-based
    @endverbatim
 ************************************************************************/
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

    transform (newString.begin(), newString.end(), newString.begin(), tolower);
    // makes it all lowercase and returns it
    return newString;
}

/** **********************************************************************
 *  @author Tammy Nguyen
 *
 *  @par Prints to the word data file and the statistics files
 *
 *  @param[in]      argc - number of arguments
 *  @param[in]      argv - command line arguments
 *  @param[in]      list - the list it will print
 *  @param[in, out] fout - word data file
 *  @param[in, out] stats - statistics file 
 *
 *  @par Example
 *  @verbatim
 *  int argc = 4; // .\thpe12.exe threepigs.txt worddata.txt stats.txt
 *  printToFile(argc, argv, list, fout, stats);
 *  //fout contains the list of words, stats lists the words in ascending
 *  // order by frequency.
 * 
 *  argc = 5; // .\thpe12.exe threepigs.txt worddata.txt stats.txt -l
 *  printToFile(argc, argv, list, fout, stats);
 *  //fout did not change. stats lists the words in ascending order by length.
 * 
 *  argc = 5; // .\thpe12.exe threepigs.txt worddata.txt stats.txt -fl
 *  printToFile(argc, argv, list, fout, stats);
 *  //no change to fout. stats lists the words in ascending order by
 *  //frequency then length.
    @endverbatim
 ************************************************************************/
void printToFile ( int argc, char** argv, wordFreqList &list, ofstream &fout, ofstream &stats )
{
    string outputType;
    
    //always output all of the words to output file, option or not
    list.printFirstChar( fout );

    // no option specified
    if (argc == 4)
        list.printFrequency( stats );
    
    // option specified, check if its valid then print
    if (argc == 5)
    {
        checkOpt(argv);
        outputType = argv[4];

        //output by frequency
        if ( outputType == "-f" )
            list.printFrequency( stats );
        //output by length
        if ( outputType == "-l" )
            list.printLengths( stats );
        //output by frequency then length
        if ( outputType == "-fl" )
        {
            list.printFrequency( stats );
            list.printLengths( stats );
        }
        //output by length then frequency
        if (outputType == "-lf")
        {
             list.printLengths( stats );
             list.printFrequency( stats );
        }
    }
}