#include "Person.h"
#include <stdexcept>

Person::Person(std::string name, int age)
{
	setName(name);
	validateAge(age);
	setAge(age);
}

const std::string Person::getName() const
{
	return this->name;
}

const int Person::getAge() const
{
	return this->age;
}

void Person::setName(const std::string name)
{
	this->name = name;
}

void Person::setAge(const int age)
{
	validateAge(age);
	this->age = age;
}

void Person::validateAge(int age)
{
	if (age < 18 || age>100) 
	{
		throw std::invalid_argument("Age must be between 18 and 100");
	}
}

