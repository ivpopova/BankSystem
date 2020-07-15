#pragma once
#include"Employee.h"
#include <vector>

class Manager:public Employee {
public:
	Manager(std::string name, int age, std::vector<Employee*> employees, double salary);
	~Manager();

	const std::vector<Employee*> getEmployees() const;

	void addEmployee(std::string name, int age, std::string position, double salary);
	void removeEmployee(int employeeID);

	int getNumberOfEmployees() const;
	void listEmployees();
private:
	std::vector<Employee*> employees;
};