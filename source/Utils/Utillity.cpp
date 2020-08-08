#include "pch.h"
#include "Utillity.h"

LPCTSTR Utillity::ToLPCTSTR(const string& str)
{
	STRTOWCHAR_T(str);
	return wc;
}

LPCTSTR Utillity::ToLPCTSTR(const char* str)
{
	CSTRTOWCHAR_T(str);
	return wc;
}
