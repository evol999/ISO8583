//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tests.h"
#include "CDecoder.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


// Constructor for Tests
Tests::Tests() {}

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

// Member function to run test015
bool Tests::test015() {
	int iLength;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "60000000";
	String expected_output = "Error with field: -1 TPDU";	
	
	TStringList *result = new TStringList();
	result = decoder.decodeMessage(input);
	String output = "";
	if(result->Count>0)
		output = result->Strings[result->Count - 1];

	std::wcout << "Expected: " << expected_output << " l: " << expected_output.Length() <<std::endl;
	std::wcout << "Obtained: " << output << " l: " << output.Length() <<std::endl;

	return output == expected_output;  // Return true if the output is as expected, false otherwise
}

// Member function to run test016
bool Tests::test016() {
	int iLength;
	int iIndex;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "600021000002003038078020c006b8003000000000000100000018161052032900510000002100285466050000356619d251220171904e473034383236313336393639363031303120202020200029323112303030303030303030303130321230303030303030303030303801519f260831bd32aa7c77c35b9f2701809f10120110a04001220000000000000000000000ff9f37042d0ea1ff9f36020722950500800080009a032203299c01009f02060000000001005f2a020840820239009f1a0202189f03060000000000009f3303e0f8c89f34031e03009f1e0832303034383735368407a00000000410109f090200005f3401009f0607a00000000410109f0702ff0000083030303033303030003230323130123030303030303030303030303131123030303030303030303038320006303031303031008430334d323430323030303530303033303030303030303030303030313244323630303030303030303030333030323138303030303030303030305532333032303030353030303330303030303030303030303031";
	
	TStringList *expected = new TStringList();
	TStringList *result = new TStringList();
	
/* 	expected->Add("0200");
	expected->Add("30 38 07 80 20 C0 06 B8");
	expected->Add("003000");
	expected->Add("000000000100");
	expected->Add("000018");
	expected->Add("161052");
	expected->Add("0329");
	expected->Add("051");
	expected->Add("000");
	expected->Add("021");
	expected->Add("00");
	expected->Add("5466050000356619=25122017190");
	expected->Add("NG048261");
	expected->Add("3696960101     ");
	expected->Add("32 31 12 30 30 30 30 30 30 30 30 30 30 31 30 32 12 30 30 30 30 30 30 30 30 30 30 30 38");
	expected->Add("9F 26 08 31 BD 32 AA 7C 77 C3 5B 9F 27 01 80 9F 10 12 01 10 A0 40 01 22 00 00 00 00 00 00 00 00 00 00 00 FF 9F 37 04 2D 0E A1 FF 9F 36 02 07 22 95 05 00 80 00 80 00 9A 03 22 03 29 9C 01 00 9F 02 06 00 00 00 00 01 00 5F 2A 02 08 40 82 02 39 00 9F 1A 02 02 18 9F 03 06 00 00 00 00 00 00 9F 33 03 E0 F8 C8 9F 34 03 1E 03 00 9F 1E 08 32 30 30 34 38 37 35 36 84 07 A0 00 00 00 04 10 10 9F 09 02 00 00 5F 34 01 00 9F 06 07 A0 00 00 00 04 10 10 9F 07 02 FF 00");
	expected->Add("00003000");
	expected->Add("30 32 31 30 12 30 30 30 30 30 30 30 30 30 30 30 30 31 31 12 30 30 30 30 30 30 30 30 30 30 38 32");
	expected->Add("001001");
	expected->Add("03M24020005000300000000000012D2600000000003002180000000000U2302000500030000000000001"); */

	expected->Add("-01 TPDU            : \"6000210000\"");
	expected->Add("000 MsgType         : \"0200\"");
	expected->Add("001 BitMap          : \"30 38 07 80 20 c0 06 b8\"");
	expected->Add("003 ProcessingCode  : \"003000\"");
	expected->Add("004 TxnAmount       : \"000000000100\"");
	expected->Add("011 SystemTraceNo   : \"000018\"");
	expected->Add("012 TxnTime         : \"161052\"");
	expected->Add("013 TxnDate         : \"0329\"");
	expected->Add("022 POSEntryMode    : \"0051\"");
	expected->Add("023 CardSequenceNo  : \"0000\"");
	expected->Add("024 NII             : \"0021\"");
	expected->Add("025 POSConditionCode: \"00\"");
	expected->Add("035 Track2          : \"5466050000356619d25122017190\"");
	expected->Add("041 TerminalID      : \"NG048261\"");
	expected->Add("042 AcquirerID      : \"3696960101     \"");
	expected->Add("054 AddAmounts      : \"32 31 12 30 30 30 30 30 30 30 30 30 30 31 30 32 12 30 30 30 30 30 30 30 30 30 30 30 38\"");
	expected->Add("055 Field55         : \"9f 26 08 31 bd 32 aa 7c 77 c3 5b 9f 27 01 80 9f 10 12 01 10 a0 40 01 22 00 00 00 00 00 00 00 00 00 00 00 ff 9f 37 04 2d 0e a1 ff 9f 36 02 07 22 95 05 00 80 00 80 00 9a 03 22 03 29 9c 01 00 9f 02 06 00 00 00 00 01 00 5f 2a 02 08 40 82 02 39 00 9f 1a 02 02 18 9f 03 06 00 00 00 00 00 00 9f 33 03 e0 f8 c8 9f 34 03 1e 03 00 9f 1e 08 32 30 30 34 38 37 35 36 84 07 a0 00 00 00 04 10 10 9f 09 02 00 00 5f 34 01 00 9f 06 07 a0 00 00 00 04 10 10 9f 07 02 ff 00\"");
	expected->Add("057 Field57         : \"00003000\"");
	expected->Add("059 Field59         : \"30 32 31 30 12 30 30 30 30 30 30 30 30 30 30 30 30 31 31 12 30 30 30 30 30 30 30 30 30 30 38 32\"");
	expected->Add("060 Field60         : \"001001\"");
	expected->Add("061 Field61         : \"03M24020005000300000000000012D2600000000003002180000000000U2302000500030000000000001\"");	

	result = decoder.decodeMessage(input);
	
	for (int i = 0; i < result->Count; i++)
	{
		std::wcout << result->Strings[i] << std::endl;
	}
	// iIndex = result->Compare(expected);
	// return iIndex == 0;  // Return true if the output is as expected, false otherwise
	return result->Text == expected->Text;  // Return true if the output is as expected, false otherwise
}

// Member function to run test017
bool Tests::test017() {
	int iLength;
	int iIndex;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "60001900000220303800000a800000000000000000080000000002152028011430303030303030303030313230303132333435363738";
	
	TStringList *expected = new TStringList();
	TStringList *result = new TStringList();
	
	expected->Add("-01 TPDU            : \"6000190000\"");
	expected->Add("000 MsgType         : \"0220\"");
	expected->Add("001 BitMap          : \"30 38 00 00 0a 80 00 00\"");
	expected->Add("003 ProcessingCode  : \"000000\"");
	expected->Add("004 TxnAmount       : \"000000080000\"");
	expected->Add("011 SystemTraceNo   : \"000002\"");
	expected->Add("012 TxnTime         : \"152028\"");
	expected->Add("013 TxnDate         : \"0114\"");
	expected->Add("037 RetRefNo        : \"000000000012\"");
	expected->Add("039 ResponseCode    : \"00\"");
	expected->Add("041 TerminalID      : \"12345678\"");

	result = decoder.decodeMessage(input);
	
	if(result->Count == expected->Count)
	{
		for (int i = 0; i < result->Count; i++)
		{
			std::wcout << result->Strings[i] << std::endl;
			std::wcout << expected->Strings[i] << std::endl;
			if(result->Strings[i] != expected->Strings[i] )
			{
				std::wcout << "Strings are different" << std::endl;
				return false;
			}
		}
	}
	else
		return false;
	
	// iIndex = result->Compare(expected);
	// return iIndex == 0;  // Return true if the output is as expected, false otherwise
	return result->Text == expected->Text;  // Return true if the output is as expected, false otherwise
}

bool Tests::test018() {
	int iLength;
	int iIndex;
	bool retVal = False;

	CDecoder decoder;  // Create an instance of the CDecoder class
	String input = "60001900000220303800000A800000000000000000080000000002152028011430303030303030303030313230303132333435363738";
	String output = "";
	String test = "";

	// TPDU
	iIndex = -1;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}
	
	// MsgType
	iIndex = 0;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}
	
	// BitMap
	iIndex = 1;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// ProcessingCode
	iIndex = 3;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// TxnAmount
	iIndex = 4;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// SystemTraceNo
	iIndex = 11;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// TxnTime
	iIndex = 12;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// TxnDate
	iIndex = 13;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// RetRefNo
	iIndex = 37;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

	// ResponseCode
	iIndex = 39;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	}

/* 	// TerminalID
	iIndex = 41;
	iLength = decoder.getFieldLength(iIndex);
	output = decoder.getField(input, iLength);  // Call the getTPDU method
	test = input.SubString(input.Length() - 3, 4);
	// check for input ending
	if("3738" != test)
	{
		std::wcout << "iIndex: " << iIndex <<std::endl;
		return retVal;
	} */
	retVal = True;
	return retVal;
}




