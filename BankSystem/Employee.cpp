#include "Employee.h"
#include <iostream>

Employee::Employee(std::string name, int age, std::string position, double salary): Person(name, age)
{
	setPosition(position);
	setSalary(salary);
}

std::string Employee::getPosition() const
{
	return this->position;
}

double Employee::getSalary() const
{
	return this->salary;
}

void Employee::setPosition(const std::string position)
{
	this->position = position;
}

void Employee::setSalary(const double salary)
{
	this->salary = salary;
}

void Employee::printInformation()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Employee Info:" << " Name: " << this->getName() << std::endl;
	std::cout << "--Position: " << this->getPosition() << " ---Salary: " << this->getSalary() << std::endl;
}
