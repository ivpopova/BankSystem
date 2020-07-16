#pragma once
#include <string>
#include"Customer.h"
#include"BusinessCustomer.h"
#include"Employee.h"
#include"Account.h"
#include"Loan.h"
#include"Manager.h"
#include <map>

class Bank 
{
public:
	Bank() = delete;
	Bank(std::string name, Manager* manager, std::map<std::string, Customer*> customers, std::map<std::string, Account*> accounts);
	virtual ~Bank();

	std::string getName() const;
	void setName(const std::string name);

	std::map<std::string, Customer*> getCustomers() const;
	std::map<std::string, Account*> getAccounts(std::string IBAN) const;

	Customer* getCurrentCustomer(std::string customerID) const;
	Account* getCurrentAccount(std::string IBAN) const;

	void addCustomer(std::string name, int age, std::string customerID);
	void addBusinessCustomer(std::string name, int age, std::string customerID, std::string businessType);
	void deleteCustomer(std::string customerID);
	void listCustomers();
	
	void addCheckingAccount(std::string IBAN, std::string customerID, double balance);
	void addSavingsAccount(std::string IBAN, std::string customerID, double balance, double interestRate);
	void deleteAccount(std::string IBAN);
	void listCustomerAccount(std::string IBAN);
	void listAccounts();

	void listEmployees();
	void getLoan(std::string customerID, double loanRate, double amount);

	void transfer(std::string fromIBAN, std::string toIBAN, double amount);
	void deposit(std::string IBAN, double amount);
	void withdraw(std::string IBAN, double amount);

	bool isValidTransaction(double amount, std::string IBAN);	
	bool IbanExists(std::string IBAN);
	bool isCustomerExist(std::string customerID);
private:
	std::string name;
	Manager* manager;

	std::map<std::string, Customer*> customers;
	std::map<std::string, Account*> accounts;
	std::map<std::string, Loan*> loans;

	void validateAmount(double amount);
};