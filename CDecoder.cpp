//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDecoder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

static const int row_length = 32;

// This function takes a String as input and returns a new String
// with a space every two characters.
String insertSpaces(const String& input) {
	String output = "";
	// Loop through the input String and insert a space after
	// every two characters.
	for (int i = 1; i <= input.Length(); i += 2) {
		// Add the current character to the output String.
		output += input[i];

		// If there is another character, add it to the output String
		// and then add a space.
		if (i + 1 <= input.Length()) {
			output += input[i + 1];
			output += " ";
		}
	}
	return output;
}

String getHexLength(int value) {
	String sTemp;

	if(value > 0)
		value--;

	value /=2;
	sTemp = String().sprintf(_D("%04X: "), value);
	return sTemp;
}

TStringList* CDecoder::formatInput(const String& input) {

	TStringList *retVal = new TStringList;
	String sTemp;
	for (int i = 1; i < input.Length(); i += row_length) {
		sTemp = getHexLength(i);
		sTemp += insertSpaces(input.SubString(i, row_length));
		retVal->Add(sTemp);
	}
	return retVal;
}

// Member function to get the TPDU
String CDecoder::getTPDU(String& input) {
	// TODO: Add code to modify the input string and return the output2 string
	return UnicodeString();
}
