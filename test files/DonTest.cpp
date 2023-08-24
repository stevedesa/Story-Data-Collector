#include "..\\catch.hpp"
#include "thpe12.h"
#include "wordFreq.h"


TEST_CASE( "Remove Function" )
{
	SECTION( "One item in list" )
	{
		wordFreqList list;
		list.insert( "target" );
		string word = "target";
		list.remove( word );
		list.print( );
	}
	
	SECTION( "Multiple items in list" )
	{
		wordFreqList list;
		list.insert( "first" );
		list.insert( "second" );
		list.insert( "third" );

		list.remove( "first" );
		list.remove( "second" );
		list.remove( "third" );

		list.print();
	} 
}



TEST_CASE( "insert" )
{
	SECTION( "Inserting one item" )
	{
		wordFreqList list;
		list.insert( "target" );
		list.print( );
	}

	SECTION( "inserting multiple items" )
	{
		wordFreqList list;
		list.insert( "first" );
		list.insert( "second" );
		list.insert( "third" );

		list.print( );
	}
}
