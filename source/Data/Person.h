#pragma once

class Person
{
public:
	static const char* k_male;
	static const char* k_female;

	struct SBirth
	{
		SBirth();
		SBirth(unsigned int day, unsigned int month, unsigned int year, const char* place);

		mufise::ui8		m_day;
		mufise::ui8		m_month;
		mufise::ui16	m_year;
		string			m_place;
	};

	void SetBirth(const SBirth& birth);
	
	const SBirth&	GetBirth()		{ return m_birth; };
	const string&	GetName()		{ return m_name; };
	mufise::ui8		GetAge()		{ return m_age; };

protected:
	~Person();

	string			m_name;
	string			m_gender;
	mufise::ui8		m_age;
	SBirth			m_birth;
};