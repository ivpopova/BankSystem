#pragma once
#include <string>

class Loan
{
public:
	Loan() = delete;
	Loan(double amount, double loanRate, std::string ownerID);
	~Loan() = default;

	const double getAmount() const;
	const double getLoanRate() const;
	std::string getOwnerID() const;

	void setAmount(const double amount);
	void setLoanRate(const double loanRate);
	void setOwnerID(const std::string ownerID);
private:
	double amount;
	double loanRate;
	std::string ownerID;
};