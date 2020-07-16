#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(std::string IBAN, std::string customerID, double balance, double interestRate) : Account(IBAN, customerID, balance)
{
	setInterestRate(interestRate);
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::setInterestRate(double interestRate)
{
	this->interestRate = interestRate;
}

void SavingsAccount::printInformation()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "ACCOUNT TYPE: Savings Account" << std::endl;
	std::cout << "IBAN: " << getIBAN() << std::endl;
	std::cout << "Owner ID: " << getCustomerID() << std::endl;
	std::cout << "Interest Rate:" << getInterestRate() << std::endl;
	std::cout << "Balance:" << getBalance() << std::endl;
}
