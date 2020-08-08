#include "pch.h"
#include "Person.h"

#include <ctime>

#define DATE_BASE_YEAR	1900
#define DATE_BASE_MONTH	1
#define DATE_BASE_DAY	1


const char* Person::k_male = "Male";
const char* Person::k_female = "Female";

void Person::SetBirth(const SBirth& birth)
{
	m_birth = birth;

	std::time_t time = std::time(0);
	tm* time_struct = localtime(&time);
	// add one because Aug is 7 instead of 8
	time_struct->tm_mon += 1;

	m_age = time_struct->tm_year - (m_birth.m_year - DATE_BASE_YEAR);
	
	if (m_birth.m_month > time_struct->tm_mon)
	{
		m_age -= 1;
	}
	else if (m_birth.m_month == time_struct->tm_mon)
	{
		if (m_birth.m_day > time_struct->tm_mday)
		{
			m_age -= 1;
		}
	}
}

Person::~Person()
{
}

Person::SBirth::SBirth()
{
}

Person::SBirth::SBirth(unsigned int day, unsigned int month, unsigned int year, const char* place)
	: m_day(day)
	, m_month(month)
	, m_year(year)
	, m_place(place)
{
}
