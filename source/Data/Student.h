#pragma once

#include "Person.h"

class Student : public Person
{
public:
	Student(const char* name, const char* gender);
	~Student();
};