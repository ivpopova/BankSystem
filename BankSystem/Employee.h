#pragma once
#include"Person.h"

class Employee:public Person {
public:
	Employee(std::string name, int age, std::string position, double salary);
	~Employee() = default;

	std::string getPosition() const;
	double getSalary() const;

	void setPosition(const std::string position);
	void setSalary(const double salary);

	virtual void printInformation() override;
private:
	std::string position;
	double salary;
};