#include "Manager.h"
#include <iostream>

Manager::Manager(std::string name, int age, std::vector<Employee*> employees, double salary): Employee(name, age, "Manager", salary)
{
	this->employees = employees;
}

Manager::~Manager()
{
	for (int i = 0; i < employees.size(); i++) 
	{
		delete employees[i];
	}
}

const std::vector<Employee*> Manager::getEmployees() const
{
	return this->employees;
}

void Manager::addEmployee(std::string name, int age, std::string position, double salary)
{
	employees.push_back(new Employee(name, age, position, salary));
}

void Manager::removeEmployee(int employeeID)
{
	employees.erase(employees.begin() + employeeID);
}

int Manager::getNumberOfEmployees() const
{
	return employees.size();;
}

void Manager::listEmployees()
{
	for (int i = 0; i < employees.size(); i++)
	{
		employees[i]->printInformation();
	}
}
