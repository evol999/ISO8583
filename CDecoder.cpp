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

// Constructor
CDecoder::CDecoder() {
    // Insert some key-value pairs into the map
    isoFields[-1] = std::make_tuple(5, "TPDU");
    isoFields[0] = std::make_tuple(2, "MsgType");
    isoFields[1] = std::make_tuple(8, "BitMap");
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

// Method that takes an int key and returns the int value associated with the key
int CDecoder::getFieldLength(int key) {
    try {
        // Return the first element of the tuple (the int value) associated with the key
        return std::get<0>(isoFields.at(key));
    } catch (const std::out_of_range& e) {
        // If the key is not found, return 0
        return -1;
    }
}

// Method that takes an int key and returns the string value associated with the key
String CDecoder::getStringValue(int key) {
    try {
        // Return the second element of the tuple (the string value) associated with the key
        return std::get<1>(isoFields.at(key));
    } catch (const std::out_of_range& e) {
        // If the key is not found, return an empty string
        return NULL;
    }
}

// Member function to read any field
String CDecoder::getField(String& input, int iLength) {
	String retVal = NULL;

	if(iLength*2 < input.Length())
	{
		retVal = input.SubString(1, iLength*2);
		input = input.SubString(iLength+1, input.Length());
	}
		
	return retVal;
}
