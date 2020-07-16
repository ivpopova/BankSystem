#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(std::string IBAN, std::string customerID, double balance) : Account(IBAN, customerID,balance)
{
}

void CheckingAccount::printInformation()
{
	std::cout << "--------------------------"<< std::endl;
	std::cout << "ACCOUNT TYPE: Checking Account" << std::endl;
	std::cout << "IBAN: " << getIBAN() << std::endl;
	std::cout << "CustomerID: " << getCustomerID() << std::endl;
	std::cout << "Balance:" << getBalance() << std::endl;
}
