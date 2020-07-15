#include "Loan.h"

Loan::Loan(double amount, double loanRate, std::string ownerID)
{
	setAmount(amount);
	setLoanRate(loanRate);
	setOwnerID(ownerID);
}

const double Loan::getAmount() const
{
	return this->amount;
}

const double Loan::getLoanRate() const
{
	return this->loanRate;
}

std::string Loan::getOwnerID() const
{
	return this->ownerID;
}

void Loan::setAmount(const double amount)
{
	this->amount = amount;
}

void Loan::setLoanRate(const double loanRate)
{
	this->loanRate = loanRate;
}

void Loan::setOwnerID(const std::string ownerID)
{
	this->ownerID = ownerID;
}
