//---------------------------------------------------------------------------

#pragma hdrstop

#include "Clog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CLog::CLog(String str)
{
	keyWord = str;
}
void CLog::add(String str)
{
	String tempStr;
	tempStr = "[" + keyWord + "]" + str;
	OutputDebugString(tempStr.c_str());	
}
