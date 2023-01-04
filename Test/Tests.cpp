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

// Member function generete a String from a vector.
String Tests::vectorToString(const std::vector<int>& fields)
{
    std::stringstream stream;
    for (int field : fields) {
        stream << field << " ";
    }
    std::string str = stream.str();
    return String(str.c_str());
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

// Member function to run test005
bool Tests::test005() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "000000000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "000000";
	// 3 = PAN
	iLength = decoder.getFieldLength(3);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(3);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test006
bool Tests::test006() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "000000080000000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "000000080000";
	// 4 = TxnAmount
	iLength = decoder.getFieldLength(4);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(4);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test007
bool Tests::test007() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "000002104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "000002";
	// 11 = SystemTraceNo
	iLength = decoder.getFieldLength(11);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(11);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test008
bool Tests::test008() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "104302040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "104302";
	// 12 = TxnTime
	iLength = decoder.getFieldLength(12);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(12);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test009
bool Tests::test009() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "040235313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "0402";
	// 13 = TxnDate
	iLength = decoder.getFieldLength(13);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(13);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test010
bool Tests::test010() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "35313531353135313531353153414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "515151515151";
	// 37 = RetRefNo
	iLength = decoder.getFieldLength(37);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(37);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test011
bool Tests::test011() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "53414C4535313030313233343536373831323334353637383930313233";
	String expected_output = "SALE51";
	// 38 = AuthID
	iLength = decoder.getFieldLength(38);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(38);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test012
bool Tests::test012() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "3030313233343536373831323334353637383930313233";
	String expected_output = "00";
	// 39 = ResponseCode
	iLength = decoder.getFieldLength(39);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(39);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test013
bool Tests::test013() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "313233343536373831323334353637383930313233";
	String expected_output = "12345678";
	// 41 = TerminalID
	iLength = decoder.getFieldLength(41);
	String output = decoder.getField(input, iLength);  // Call the getTPDU method
	type = decoder.getTypeValue(41);
	String formattedOutput = decoder.getFormattedField(output, type);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << formattedOutput << " l: " << formattedOutput.Length() <<std::endl;

	return formattedOutput == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test014
bool Tests::test014() {
	int iLength;
	CDecoder::Type type = CDecoder::Type::None;
	
	std::vector<int> viOutput{2, 3, 4, 11, 14, 22, 23, 25, 35, 41, 42, 54, 55, 60};
	
	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "7024068020C00610";
	std::vector<int> fields = decoder.parseBitMap(input);
	String expected_output = Tests::vectorToString(viOutput);
	String output = Tests::vectorToString(fields);
	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << output << " l: " << output.Length() <<std::endl;

	return output == expected_output;  // Return true if the output is as expected, false otherwise
}




