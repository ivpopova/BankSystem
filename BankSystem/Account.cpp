#include "Account.h"

Account::Account(std::string IBAN, std::string customerID, double balance)
{
	setIBAN(IBAN);
	setCustomerID(customerID);
	setBalance(balance);
}

std::string Account::getIBAN() const
{
	return this->IBAN;
}

std::string Account::getCustomerID() const
{
	return this->customerID;
}

double Account::getBalance() const
{
	return this->balance;
}

void Account::setIBAN(const std::string IBAN)
{
	this->IBAN = IBAN;
}

void Account::setCustomerID(const std::string customerID)
{
	this->customerID = customerID;
}

void Account::setBalance(const double balance)
{
	this->balance = balance;
}

void Account::deposit(double deposit)
{
	this->setBalance(getBalance() + deposit);
}

void Account::withdraw(double withdraw)
{
	setBalance(getBalance() - withdraw);
}

