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
			if(i + 1 != input.Length())
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

String hexToAscii(const String& hex_string) {
    std::stringstream ss;
    for (int i = 1; i <= hex_string.Length(); i += 2) {
        std::string byte = AnsiString(hex_string.SubString(i, 2)).c_str();
        char chr = (char) strtol(byte.c_str(), NULL, 16);
        ss << chr;
    }
    AnsiString ascii = ss.str().c_str();
    return String(ascii);
}

// Constructor
CDecoder::CDecoder() {
    // Key = field number,
	// first value = field length in bytes,
	// second value = field desciption,
	// third value = field type,
	// -1 in the first value means LLVAR
	// Insert some key-value pairs into the map
    isoFields[-1] = std::make_tuple(5, "TPDU", Type::Hex);
    isoFields[0] = std::make_tuple(2, "MsgType", Type::Hex);
    isoFields[1] = std::make_tuple(8, "BitMap", Type::Binary);
    isoFields[2] = std::make_tuple(-1, "PAN", Type::BCD);
    isoFields[3] = std::make_tuple(3, "ProcessingCode", Type::Hex);
    isoFields[4] = std::make_tuple(6, "TxnAmount", Type::BCD);
    isoFields[11] = std::make_tuple(3, "SystemTraceNo", Type::BCD);
    isoFields[12] = std::make_tuple(3, "TxnTime", Type::BCD);
    isoFields[13] = std::make_tuple(2, "TxnDate", Type::BCD);
    isoFields[37] = std::make_tuple(12, "RetRefNo", Type::ASCII);
    isoFields[38] = std::make_tuple(6, "AuthID", Type::ASCII);
    isoFields[39] = std::make_tuple(2, "ResponseCode", Type::ASCII);
    isoFields[41] = std::make_tuple(8, "TerminalID", Type::ASCII);
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

// Method that takes an int key and returns the desciption value associated with the key
String CDecoder::getDescValue(int key) {
    try {
        // Return the second element of the tuple (the string value) associated with the key
        return std::get<1>(isoFields.at(key));
    } catch (const std::out_of_range& e) {
        // If the key is not found, return an empty string
        return NULL;
    }
}

// Method that takes an int key and returns the Type value associated with the key
CDecoder::Type CDecoder::getTypeValue(int key) {
    try {
        // Return the second element of the tuple (the string value) associated with the key
        return std::get<2>(isoFields.at(key));
    } catch (const std::out_of_range& e) {
        // If the key is not found, return an empty string
        return Type::None;
    }
}

// Member function to read any field
String CDecoder::getField(String& input, int iLength) {
	String retVal = NULL;
	int iRealLength = 0;
	
	// variable length
	if( -1 == iLength)
	{
		if(input.Length()>2)
			iRealLength = input.SubString(1,2).ToInt();
		if(input.Length()>3)
			input = input.SubString(3, input.Length());
	}
	else
		iRealLength = 2*iLength;
		
	if(iRealLength < input.Length() && iRealLength != 0)
	{
		retVal = input.SubString(1, iRealLength);
		input = input.SubString(iLength+1, input.Length());
	}
	
	// check for correct decodification
	if("" != retVal && iRealLength != retVal.Length())
		retVal = "";
	return retVal;
}

// Member function to format the field for visualization.
String CDecoder::getFormattedField(String& input, Type type) {

	String retVal = input;
	
	switch(type)
	{
		case Type::Binary:
		{
			retVal = insertSpaces(input);
			break;
		}
		case Type::ASCII:
		{
			retVal = hexToAscii(input);
			break;
		}
		case Type::None:
		case Type::Hex:
		case Type::BCD:
		default:
		{
			// Do nothing
		}
	}

	return retVal;
}

std::vector<int> CDecoder::parseBitMap(const String& bitmap)
{
    std::vector<int> fields;
	int value, high, low;

    int length = bitmap.Length();
    for (int i = 1; i <= length; i+=2) {
		String tempString = "0x";
		// get substring
		tempString += bitmap.SubString(i, 2);
		value = StrToInt(tempString);
		// high part
		high = value & 0xF0;
        if (high != 0) {
			if(0x80 & high)
				fields.push_back((i-1) * 4 + 1);
			if(0x40 & high)
				fields.push_back((i-1) * 4 + 2);
			if(0x20 & high)
				fields.push_back((i-1) * 4 + 3);
			if(0x10 & high)
				fields.push_back((i-1) * 4 + 4);
		}

		// low part
		low = value & 0x0F;
        if (low != 0) {
			if(0x08 & low)
				fields.push_back((i-1) * 4 + 5);
			if(0x04 & low)
				fields.push_back((i-1) * 4 + 6);
			if(0x02 & low)
				fields.push_back((i-1) * 4 + 7);
			if(0x01 & low)
				fields.push_back((i-1) * 4 + 8);
            
        }
    }

    return fields;
}

bool CDecoder::insertDecodedField(int iField, String& inputStr, TStringList& stringList, String& partialStr)
{
	bool retVal = True;
	int iLength;
	String errorMessage = "Error with field: ";
	
	iLength = getFieldLength(iField);
	partialStr = getField(inputStr, iLength);  // Call the getField method
	if("" == partialStr)
	{
		stringList.Add(errorMessage + iField + " " +getDescValue(iField));
		retVal = False;
	}
    return retVal;	
	
}

TStringList* CDecoder::decodeMessage(String inputStr) {
    TStringList* retVal = new TStringList();
	int iField;
	bool isOK;
	String partialStr;

	// mandatory fields
	// try to get TPDU
	iField = -1;
	isOK = insertDecodedField(iField, inputStr, *retVal, partialStr);
	if(!isOK)
		return retVal;

	// try to get MsgType
	iField = 0;
	isOK = insertDecodedField(iField, inputStr, *retVal, partialStr);
	if(!isOK)
		return retVal;

	// try to get BitMap
	iField = 1;
	isOK = insertDecodedField(iField, inputStr, *retVal, partialStr);
	if(!isOK)
		return retVal;
	
	// use info in the TStringList no sirve porque esta formateada devolver partialStr
	std::vector<int> fields = parseBitMap(partialStr);
	
	for (int i = 0; i < fields.size(); i++) {
		isOK = insertDecodedField(fields[i], inputStr, *retVal, partialStr);
		if(!isOK)
			break;
    }
	return retVal;
}