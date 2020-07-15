#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <exception>

Bank::Bank(std::string name, Manager* manager, std::map<std::string, Customer*> customers, std::map<std::string, Account*> accounts)
{
	this->name = name;
	this->manager = manager;
	this->customers = customers;
	this->accounts = accounts;
}

Bank::~Bank()
{
	for (std::map<std::string, Customer*>::iterator it = customers.begin(); it != customers.end(); it++) 
	{
		delete it->second;
	}

	for (std::map<std::string, Account*>::iterator it = accounts.begin(); it != accounts.end(); it++)
	{
		delete it->second;
	}

	for (std::map<std::string, Loan*>::iterator it = loans.begin(); it != loans.end(); it++) 
	{
		delete it->second;
	}
}

std::string Bank::getName() const
{
	return this->name;
}

void Bank::setName(const std::string name)
{
	this->name = name;
}

std::map<std::string, Customer*> Bank::getCustomers() const
{
	return this->customers;
}

std::map<std::string, Account*> Bank::getAccounts(std::string IBAN) const
{
	return accounts;
}

Customer* Bank::getCurrentCustomer(std::string customerID) const
{
	return customers.find(customerID)->second;
}

Account* Bank::getCurrentAccount(std::string IBAN) const
{
	return accounts.find(IBAN)->second;
}

void Bank::addCustomer(std::string name, int age, std::string customerID)
{
	if (isCustomerExist(customerID)) 
	{
		throw std::invalid_argument("Customer with ID:: " + customerID + " already exist!");
	}
	else 
	{
		customers[customerID] = new Customer(name, age, customerID);
	}	
}

void Bank::addBusinessCustomer(std::string name, int years, std::string businessID, std::string businessType)
{
	if (isCustomerExist(businessID))
	{
		throw std::invalid_argument("Customer with ID:: " + businessID + " already exist!");
	}
	else 
	{
		customers[businessID] = new BusinessCustomer(name, years, businessID, businessType);
	}
}

void Bank::deleteCustomer(std::string customerID)
{
	std::map<std::string, Customer*>::iterator customerIterator= customers.find(customerID);

	if (customerIterator != customers.end()) 
	{
		customers.erase(customerIterator);
	} 
	else 
	{
		throw std::invalid_argument("A customer with ID " + customerID + " doesn't exist!");
	}
}  

void Bank::listCustomers()
{
	std::cout << "List of Customers:"<<std::endl;

	for (std::map<std::string, Customer*>::iterator it = customers.begin(); it != customers.end(); it++)
	{
		it->second->printInformation();
	}
}

void Bank::addCheckingAccount(std::string IBAN, std::string customerID, double balance)
{
	if (IbanExists(IBAN)) 
	{
		throw std::invalid_argument("Customer with ID:: " + IBAN + " already exist!");	
	}
	else 
	{
		validateAmount(balance);
		accounts[IBAN] = new CheckingAccount(IBAN, customerID, balance);
	}	
}

void Bank::addSavingsAccount(std::string IBAN, std::string customerID, double balance, double interestRate)
{
	if (IbanExists(IBAN)) 
	{
		throw std::invalid_argument("Customer with ID:: " + IBAN + " already exist!");
	}
	else 
	{
		validateAmount(balance);
		accounts[IBAN] = new SavingsAccount(IBAN, customerID, balance, interestRate);
	}
}

void Bank::deleteAccount(std::string IBAN)
{
	std::map<std::string, Account*>::iterator accountIterator = accounts.find(IBAN);

	if (accountIterator != accounts.end()) 
	{
		accounts.erase(accountIterator);
	}
	else
	{
		throw std::invalid_argument("A IBAN number " + IBAN + " doesn't exist!");
	}
}

void Bank::listAccounts()
{
	std::cout << "List of Accounts:" << std::endl;

	for (std::map<std::string, Account*>::iterator it = accounts.begin(); it != accounts.end(); it++) 
	{
		it->second->printInformation();
	}
}

void Bank::listEmployees()
{
	this->manager->listEmployees();
}

void Bank::getLoan(std::string customerID, double loanRate, double amount)
{
	if (isCustomerExist(customerID))
	{
		loans[customerID] = new Loan(amount, loanRate, customerID);
	}
	else 
	{
		throw std::invalid_argument("Customer doesn't exist!");
	}
}

void Bank::listCustomerAccount(std::string IBAN)
{
	if (IbanExists(IBAN)) 
	{
		accounts[IBAN]->printInformation();
	}
	else 
	{
		throw std::invalid_argument("IBAN number doesn't exist!");
	}
	
}

void Bank::transfer(std::string fromIBAN, std::string toIBAN, double amount)
{
	if (IbanExists(fromIBAN) && IbanExists(toIBAN))
	{
		validateAmount(amount);
		accounts[fromIBAN]->withdraw(amount);
		accounts[toIBAN]->deposit(amount);
	}
	else 
	{
		throw std::invalid_argument("IBAN number doesn't exist!");
	}
}

void Bank::deposit(std::string IBAN, double amount)
{
	if (IbanExists(IBAN)) 
	{
		validateAmount(amount);
		accounts[IBAN]->deposit(amount);
	}
	else 
	{
		throw std::invalid_argument("IBAN number doesn't exist!");
	}
}

void Bank::withdraw(std::string IBAN, double amount)
{
	if (IbanExists(IBAN)) 
	{
		validateAmount(amount);
		accounts[IBAN]->withdraw(amount);
	}
	else 
	{
		throw std::invalid_argument("IBAN number doesn't exist!");
	}
}

void Bank::validateAmount(double amount)
{
	if (amount < 0)
	{
		throw std::invalid_argument("Negative amount!");
	}
}

bool Bank::isValidTransaction(double amount, std::string IBAN)
{
	if (!IbanExists(IBAN)) 
	{
		throw std::invalid_argument("IBAN number doesn't exist!");
	} 
	else if (accounts[IBAN]->getBalance() <= amount)
	{
		throw std::invalid_argument("Don't have enough money for this transaction!");
	}
	else 
	{
		return true;
	}
}

bool Bank::IbanExists(std::string IBAN)
{
	if (accounts.count(IBAN) > 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}	
}

bool Bank::isCustomerExist(std::string customerID)
{
	if (customers.count(customerID) > 0) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

