//---------------------------------------------------------------------------

#pragma hdrstop

#include "Clog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
String CLog::keyWord = "";

void CLog::add(String str)
{
#if _DEBUG
	String tempStr;
	tempStr = "[" + keyWord + "]" + str;
	OutputDebugString(tempStr.c_str());	
#endif
}

void CLog::setKeyWord(String str)
{
#if _DEBUG
	keyWord = str;
#endif
}
