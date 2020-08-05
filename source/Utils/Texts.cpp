#include "pch.h"
#include "Texts.h"

std::string Texts::k_titleTag = "TXT_";
std::map<std::string, std::string> Texts::s_keyMap;

void Texts::Parse(const char* filename)
{
	xlnt::path f(filename);
	if (f.exists())
	{
		xlnt::workbook book(f);
		xlnt::worksheet sheet;
		for (usize i = 0; i < book.sheet_count(); i++)
		{
			sheet = book.sheet_by_index(i);
			if (sheet.has_active_cell())
			{
				string _strID, _strValue;
				bool isTitleFound = false;

				xlnt::range rows = sheet.rows();
				for (auto rIt = rows.begin(); rIt != rows.end(); rIt++)
				{
					MF_ASSERT((*rIt).length() == 2);

					_strID = (*rIt)[0].to_string();
					_strValue = (*rIt)[1].to_string();					

					if (!isTitleFound)
					{
						MF_ASSERT_MSG(_strID.find(k_titleTag) != string::npos, "Invalid Title format!");

						isTitleFound = true;
						continue;
					}

					s_keyMap[_strID] = _strValue;
				}
			}
		}
	}
	else
	{
		MF_ASSERT(0);
	}
}

const std::string& Texts::GetString(const std::string& ID)
{
	if (s_keyMap.find(ID) != s_keyMap.end())
	{
		return s_keyMap[ID];
	}
	else
	{
		return "";
	}
}

const char* Texts::GetStringC(const std::string& ID)
{
	return GetString(ID).c_str();
}

LPCTSTR Texts::GetStringL(const std::string& ID)
{
	const char* cc = GetString(ID).c_str();
	const size_t sz = strlen(cc) + 1;
 	wchar_t* wc = new wchar_t[sz];
	
	mbstowcs(wc, cc, sz);

	return wc;
}
