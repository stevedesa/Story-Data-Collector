#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe12.h"
#include "wordFreq.h"

//write test cases here
TEST_CASE( " 'Chin.' " )
{
	string result;
	string word = "'Chin.'";

	result = removePunct(word);
	REQUIRE(result == "chin" );
}

TEST_CASE( "...Chicago-based!!!" )
{
	string result;
	string word = "...Chicago-Based!!!";

	result = removePunct(word);
	REQUIRE(result == "chicago-based");
}

TEST_CASE( "ex-wife???!?" )
{
	string result;
	string word = "ex-wife???!?";

	result = removePunct(word);
	REQUIRE(result == "ex-wife");
}
