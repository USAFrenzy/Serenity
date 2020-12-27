#include <catch2/catch.hpp>

#include <Serenity/Indicators/IndicatorManager.h>
#include <Serenity/Indicators/DefaultIndicator.h>


// TODO: See If It's Possible To Redirect Failed Tests' Output To A Log File (I Know I Can Log Successful Tests)
/*
    That Way I Could Have A Nifty Little Log File Saying ALl Tests Passed And If There Was A Failed Test,
    Then It Would Log The Failed Test With Similar Output That Catch2 Outputs To The Console Screen
*/
// TODO: Write Some Tests Based On Reference Counters, etc... And Once That's Done, Remove Sandbox Code For This

std::vector<serenity::DefaultBar*> tempIndicators;
serenity::manager::Manager newHandle;


size_t CreateIndicators(int indicatorNumber)
{
	tempIndicators.clear( ); // Make Sure The Vector Is Empty Before Iteration
	for(int i = 0; i < indicatorNumber; i++) {
		tempIndicators.emplace_back(new serenity::DefaultBar( ));
	}
	return tempIndicators.size( );
}

size_t RegisterIndicators( )
{
	newHandle.GetHandle( );
	for(int i = 0; i < tempIndicators.size( ); i++) {
		tempIndicators [i]->RegisterIndicator( );
	}
	return newHandle.GetSize( );
}

size_t UnregisterIndicators( )
{
	for(int i = 0; i < tempIndicators.size( ); i++) {
		tempIndicators [i]->UnregisterIndicator( );
	}
	return newHandle.GetSize( );
}

// Directly Testing That The Size Of The Vector Used To Hold The Created Indicators Matches How Many Indicators
// Were Created In This Test Case (NOT Capacity)
TEST_CASE("For Every Indicator Created, Tests If The Indicator Is Properly Stored In A Vector", "[single-file]")
{
	REQUIRE(CreateIndicators(0) == 0); // If None Are Created, Vector Shouldn't Have Data In It
	REQUIRE(CreateIndicators(1) == 1);
	REQUIRE(CreateIndicators(2) == 2);
	REQUIRE(CreateIndicators(3) == 3);
	REQUIRE(CreateIndicators(4) == 4);
	REQUIRE(CreateIndicators(5) == 5);
	REQUIRE(CreateIndicators(50) == 50);
}

// When Registered, The Manager Object Should Be Identical To The Vector Holding The Created Indicator
// Objects In This Test Case As All Indicators Are Registered To The Manager Via A For Loop Here
TEST_CASE("Register All Indicators Stored In The Vector", "[single-file]")
{
	REQUIRE(RegisterIndicators( ) == tempIndicators.size( ));
}

// When Unregistered, The Manager Object Should Be Empty Given That This Test Case Evaluates A For Loop
// Unregistering All Indicators In The Vector Holding The Created Indicator Objects
TEST_CASE("Unregister All Indicators That Were Stored In The Vector", "[single-file]")
{
	REQUIRE(UnregisterIndicators( ) == 0);
}
