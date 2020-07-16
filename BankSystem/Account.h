#pragma once
#include <string>

class Account 
{
public:
	Account() = delete;
	Account(std::string IBAN, std::string ownerID, double balance);
	virtual ~Account() = default;

	std::string getIBAN() const;
	std::string getCustomerID() const;
	double getBalance() const;

	void setIBAN(const std::string IBAN);
	void setCustomerID(const std::string customerID);
	void setBalance(const double balance);

	void deposit(double amount);
	void withdraw(double amount);
	virtual void printInformation() = 0;
private:
	std::string IBAN;
	std::string customerID;
	double balance;
};