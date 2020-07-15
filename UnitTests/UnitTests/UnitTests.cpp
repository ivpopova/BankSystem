#include "pch.h"
#include "CppUnitTest.h"
#include "../BankSystem/Account.h"
#include "../BankSystem/Bank.h"
#include "../BankSystem/BusinessCustomer.h"
#include "../BankSystem/CheckingAccount.h"
#include "../BankSystem/Customer.h"
#include "../BankSystem/Employee.h"
#include "../BankSystem/Loan.h"
#include "../BankSystem/Manager.h"
#include "../BankSystem/Menu.h"
#include "../BankSystem/Person.h"
#include "../BankSystem/SavingsAccount.h"
#include "../BankSystem/Account.cpp"
#include "../BankSystem/Bank.cpp"
#include "../BankSystem/BusinessCustomer.cpp"
#include "../BankSystem/CheckingAccount.cpp"
#include "../BankSystem/Customer.cpp"
#include "../BankSystem/Employee.cpp"
#include "../BankSystem/Loan.cpp"
#include "../BankSystem/Manager.cpp"
#include "../BankSystem/Menu.cpp"
#include "../BankSystem/Person.cpp"
#include "../BankSystem/SavingsAccount.cpp"
#include "../BankSystem/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(AccountsTest)
	{
	public:
		const std::string IBAN = "98444BB";
		const std::string CUSTOMER_ID = "7777";
		const double BALANCE = 1200;
		const double DEPOSIT_AMOUNT = 100;
		const double WITHDRAW_AMOUNT = 100;
		TEST_METHOD(CheckingAccountDepositTest)
		{
			CheckingAccount* account = new CheckingAccount(IBAN, CUSTOMER_ID, BALANCE);

			account->deposit(DEPOSIT_AMOUNT);

			const double balanceAfterDeposit = BALANCE + DEPOSIT_AMOUNT;
			Assert::AreEqual(balanceAfterDeposit, account->getBalance());
		}  
	    TEST_METHOD(CheckingAccountWithdrawTest)
		{
			CheckingAccount* account = new CheckingAccount(IBAN, CUSTOMER_ID, BALANCE);

			account->withdraw(WITHDRAW_AMOUNT);

			const double balanceAfterWithdraw = BALANCE - WITHDRAW_AMOUNT;
			Assert::AreEqual(balanceAfterWithdraw, account->getBalance());
		}
	};

	
	};
}
