#pragma once

class Texts
{
	static std::string k_titleTag;

public:
	static void Parse(const char* filename);
	static std::string GetString(const std::string& ID);

private:
	static std::map<std::string, std::string>	s_keyMap;
};