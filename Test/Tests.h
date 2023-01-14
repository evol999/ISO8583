//---------------------------------------------------------------------------

#ifndef TestsH
#define TestsH
//---------------------------------------------------------------------------
#include <vcl.h> // include the VCL header
#include <sstream>
#include <vector>

class Tests {
public:
    // Constructor for Tests
    Tests();
	
    // Member function generete a String from a vector.
	static String vectorToString(const std::vector<int>& fields);
	// Member function to run test001
	static bool test001();
	// Member function to run test002
	static bool test002();
	// Member function to run test003
	static bool test003();
	// Member function to run test004
	static bool test004();
	// Member function to run test005
	static bool test005();
	// Member function to run test006
	static bool test006();
	// Member function to run test007
	static bool test007();
	// Member function to run test008
	static bool test008();
	// Member function to run test009
	static bool test009();
	// Member function to run test010
	static bool test010();
	// Member function to run test011
	static bool test011();
	// Member function to run test012
	static bool test012();
	// Member function to run test013
	static bool test013();
	// Member function to run test014
	static bool test014();
	// Member function to run test015
	static bool test015();
	// Member function to run test016
	static bool test016();
};
#endif
