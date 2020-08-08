#include "pch.h"
#include "Student.h"

Student::Student(const char* name, const char* gender)
	: Person()
{
	m_name = name;
	m_gender = gender;
}

Student::~Student()
{
}
