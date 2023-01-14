#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>
#include <map>
#include "Tests.h"
#include <iostream>

// Function prototype for the callback function
typedef bool (*callback_t)( void);

// Definition of the dictionary type
typedef std::map<int, callback_t> callback_map_t;


int _tmain(int argc, _TCHAR* argv[])
{
	int iTestTotal = 0, iTestOK = 0, iTestNotOK = 0;
	callback_map_t callbackMap;  // Declare the dictionary
	callbackMap[0] = &Tests::test001;
	callbackMap[1] = &Tests::test002;
	callbackMap[2] = &Tests::test003;
	callbackMap[3] = &Tests::test004;
	callbackMap[4] = &Tests::test005;
	callbackMap[5] = &Tests::test006;
	callbackMap[6] = &Tests::test007;
	callbackMap[7] = &Tests::test008;
	callbackMap[8] = &Tests::test009;
	callbackMap[9] = &Tests::test010;
	callbackMap[10] = &Tests::test011;
	callbackMap[11] = &Tests::test012;
	callbackMap[12] = &Tests::test013;
	callbackMap[13] = &Tests::test014;
	callbackMap[14] = &Tests::test015;
	callbackMap[15] = &Tests::test016;

	// Iterate over the dictionary using an iterator
	for (callback_map_t::iterator it = callbackMap.begin(); it != callbackMap.end(); ++it) {
		std::cout << "Running test: " << it->first + 1 << std::endl;
		if(it->second())
		{
			std::cout << "Test OK" << std::endl;
			iTestOK++;
		}
		else
		{
			std::cout << "Test Fail" << std::endl;
			iTestNotOK++;
		}
		iTestTotal++;
	}
    std::cout << "Total Tests: " << iTestTotal << " OK = " << iTestOK << " NOT OK = " << iTestNotOK << std::endl;
    std::cout << "Press any key to continue... ";
	getchar();
	return 0;
}
