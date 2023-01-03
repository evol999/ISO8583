//---------------------------------------------------------------------------

#ifndef CDecoderH
#define CDecoderH
//---------------------------------------------------------------------------
#include <vcl.h> // include the VCL header
class CDecoder {
private:
	// Private member variables and functions
public:
	// Function to format the input string for easy reading in the display
	TStringList* formatInput(const String& input);

	// Member function to get the TPDU
	String getTPDU(String& input);

	// Function to decode the formatted input string
	// std::string decode(const std::string& formattedInput);
};
#endif
