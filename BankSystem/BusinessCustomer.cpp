#include "BusinessCustomer.h"
#include <iostream>

BusinessCustomer::BusinessCustomer(std::string name, int age, std::string ID, std::string businessType):Customer(name, age, ID)
{
	setBusinessType(businessType);
}

const std::string BusinessCustomer::getBusinessType() const
{
	return this->businessType;
}

void BusinessCustomer::setBusinessType(const std::string businessType)
{
	this->businessType = businessType;
}

void BusinessCustomer::printInformation()
{
	std::cout << "Customer Info:" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "ID: " << this->getID() << std::endl;
	std::cout << "AGE " << this->getAge() << std::endl;
	std::cout << "BusinessType: " << this->getBusinessType() << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}
