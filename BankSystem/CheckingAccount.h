#pragma once
#include "Account.h"

class CheckingAccount : public Account 
{
public:
	CheckingAccount(std::string IBAN, std::string customerID, double balance);
	virtual ~CheckingAccount() = default;

	virtual void printInformation() override;
};