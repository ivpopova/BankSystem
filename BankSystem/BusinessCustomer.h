#pragma once
#include "Customer.h"

class BusinessCustomer : public Customer 
{
public:
	BusinessCustomer(std::string name, int age, std::string ID, std::string businessType);
	~BusinessCustomer() = default;

	const std::string getBusinessType() const;
	void setBusinessType(const std::string businessType);
	
	void printInformation() override;
private:
	std::string businessType;
};