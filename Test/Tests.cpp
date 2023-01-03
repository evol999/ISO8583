//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tests.h"
#include "CDecoder.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


// Constructor for Tests
Tests::Tests() {}

// Member function to run all the tests
void Tests::runTests() {
	// TODO: Add code to run all the tests here
	test001();
}
// Member function to run test001
bool Tests::test001() {
	std::string temp;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "60000000190210703800000EC00000164593560001791662000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "6000000019";
	String output = decoder.getTPDU(input);  // Call the getTPDU method
	std::wcout << "Expected: " << expected_output <<std::endl;
	std::wcout << "Obtained: " << output <<std::endl;

	return output == expected_output;  // Return true if the output is as expected, false otherwise
}
