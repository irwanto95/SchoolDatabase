#pragma once

class Texts
{
	static string k_titleTag;

public:
	static void Parse(const char* filename);
	static const string&	GetString(const std::string& ID);
	static const char*		GetStringC(const std::string& ID);
	static LPCTSTR			GetStringL(const std::string& ID);

private:
	static map<string, string>	s_keyMap;
};