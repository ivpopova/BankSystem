#pragma once
#include"Person.h"

class Customer : public Person 
{
public:
	Customer(std::string name, int age, std::string ID);
	~Customer() = default;

	const std::string getID() const;
	void setID(const std::string ID);

	void printInformation() override;
private:
	std::string ID;
};