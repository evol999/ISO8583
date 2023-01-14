//---------------------------------------------------------------------------

#ifndef CDecoderH
#define CDecoderH
//---------------------------------------------------------------------------
#include <vcl.h> // include the VCL header
#include <map>
#include <tuple>
#include <sstream>
#include <vector>
#include <System.SysUtils.hpp>

class CDecoder {
public:
	enum class Type {
			None,
			Hex,
			Binary,
			BCD,
			ASCII
		};
	// Constructor
	CDecoder();
	
	// Function to format the input string for easy reading in the display
	TStringList* formatInput(const String& input);
	
	// Method that takes an int key and returns the int value associated with the key
	int getFieldLength(int key);
	
	// Method that takes an int key and returns the desciption value associated with the key
	String getDescValue(int key);

	// Method that takes an int key and returns the Type value associated with the key
	Type getTypeValue(int key);
	
	// Member function to read any field
	String getField(String& input, int length);
	
	// Member function to format the field for visualization.
	String getFormattedField(String& input, Type type);
	
	// Member function to get the fields to be decoded.
	std::vector<int> parseBitMap(const String& bitmap);
	
	// Member function that inserts decoded field into visualization TStringList
	bool insertDecodedField(int iField, String& inputStr, TStringList& stringList, String& partialStr);
	// Member function to do the actual decoding
	TStringList* decodeMessage(String inputStr);
	

	// Function to decode the formatted input string
	// std::string decode(const std::string& formattedInput);
private:
	// Private member variables and functions
	// Define a map with an int key and a tuple of an int and a string as the value
    std::map<int, std::tuple<int, String, Type>> isoFields;
};
#endif
