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
	test001();
	test002();
}
// Member function to run test001
bool Tests::test001() {
	int iLength;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "60000000190210703800000EC00000164593560001791662000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "6000000019";
	// -1 = TPDU
	iLength = decoder.getFieldLength(-1);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	std::wcout << "Expected: " << expected_output <<std::endl;
	std::wcout << "Obtained: " << output <<std::endl;

	return output == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test002
bool Tests::test002() {
	int iLength;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "0210703800000EC00000164593560001791662000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "0210";
	// 0 = MsgType
	iLength = decoder.getFieldLength(0);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	std::wcout << "Expected: " << expected_output <<std::endl;
	std::wcout << "Obtained: " << output <<std::endl;

	return output == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test003
bool Tests::test003() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "703800000EC00000164593560001791662000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "70 38 00 00 0E C0 00 00";
	// 1 = BitMap
	iLength = decoder.getFieldLength(1);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(1);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test004
bool Tests::test004() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "164593560001791662000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "4593560001791662";
	// 2 = PAN
	iLength = decoder.getFieldLength(2);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(2);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}



