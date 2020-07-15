#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, int age, std::string ID): Person(name, age)
{
	setID(ID);
}

void Customer::setID(const std::string ID)
{
	this->ID = ID;
}

const std::string Customer::getID() const
{
	return this->ID;
}

void Customer::printInformation()
{
	std::cout << "Customer Info:" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "ID: " << this->getID() << std::endl;
    std::cout << "AGE " << this->getAge() << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}
