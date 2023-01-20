//---------------------------------------------------------------------------

#ifndef ClogH
#define ClogH
//---------------------------------------------------------------------------
#include <System.hpp>
class CLog
{
private:
	static String keyWord;
public:
    static void add(String str);
    static void setKeyWord(String str);
};
#endif
