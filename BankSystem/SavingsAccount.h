#pragma once
#include"Account.h"

class SavingsAccount:public Account {
public:
	SavingsAccount(std::string IBAN, std::string customerID, double balance, double interestRate);
	~SavingsAccount() = default;

	double getInterestRate()const;
	void setInterestRate(double interestRate);

	void printInformation();
private:
	double interestRate;
};