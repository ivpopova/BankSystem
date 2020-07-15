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

	TEST_CLASS(BankTests)
	{
	public:
		std::map<std::string, Customer*> customers;
		std::map<std::string, Account*> accounts;
		std::vector<Employee*> employees;

		Manager* manager = new Manager("Ivan Ivanov", 55, employees, 20000);
		Bank* bank = new Bank("DEMO BANK SYSTEM", manager, customers, accounts);

		const std::string NAME = "Peter Petrov";
		const std::string IBAN = "11BBN99";
		const std::string CUSTOMER_ID = "7766";
		const double INTEREST_RATE = 0.7;
		const std::string BUSINESS_TYPE = "Large";

		const int AGE = 22;
		const double ACCOUNT_BALANCE = 1000;
		const double AMOUNT = 200;
		TEST_METHOD(BankDepositTest)
		{
			Customer* customer = new Customer(NAME, AGE, CUSTOMER_ID);
			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);

			bank->deposit(IBAN, AMOUNT);

			Assert::AreEqual(ACCOUNT_BALANCE + AMOUNT, bank->getCurrentAccount(IBAN)->getBalance());
		}

		TEST_METHOD(BankWithdrawTest)
		{
			Customer* customer = new Customer(NAME, AGE, CUSTOMER_ID);
			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);

			bank->withdraw(IBAN, AMOUNT);

			Assert::AreEqual(ACCOUNT_BALANCE - AMOUNT, bank->getCurrentAccount(IBAN)->getBalance());
		}

		TEST_METHOD(BankTransferTest)
		{
			std::string senderIBAN = IBAN;
			std::string senderID = CUSTOMER_ID;

			std::string receiverIBAN = "12345890NN";
			std::string receiverID = "123456";
			double receiverBalance = 1200;

			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);
			bank->addCheckingAccount(receiverIBAN, receiverID, receiverBalance);

			bank->transfer(senderIBAN, receiverIBAN, AMOUNT);

			Assert::AreEqual(ACCOUNT_BALANCE - AMOUNT, bank->getCurrentAccount(IBAN)->getBalance());
		}

		TEST_METHOD(BankAddCustomerTest)
		{
			bank->addCustomer(NAME, AGE, CUSTOMER_ID);

			Assert::IsTrue(bank->isCustomerExist(CUSTOMER_ID));
		}

		TEST_METHOD(BankAddBusinessCustomerTest)
		{
			bank->addBusinessCustomer(NAME, AGE, CUSTOMER_ID, BUSINESS_TYPE);

			Assert::IsTrue(bank->isCustomerExist(CUSTOMER_ID));
		}
		TEST_METHOD(BankAddCheckingAccountTest)
		{
			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);

			Assert::IsTrue(bank->isIbanExist(IBAN));
		}

		TEST_METHOD(BankAddSavingsAccountTest)
		{
			bank->addSavingsAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE, INTEREST_RATE);

			Assert::IsTrue(bank->isIbanExist(IBAN));
		}

		TEST_METHOD(BankDeleteCustomerTest)
		{
			bank->addCustomer(NAME, AGE, CUSTOMER_ID);

			bank->deleteCustomer(CUSTOMER_ID);

			Assert::IsFalse(bank->isCustomerExist(CUSTOMER_ID));
		}

		TEST_METHOD(BankDeleteAccountTest)
		{
			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);

			bank->deleteAccount(IBAN);

			Assert::IsFalse(bank->isIbanExist(IBAN));
		}

		TEST_METHOD(BankDeleteAccountExceptionTest)
		{
			bool hasThrownException = false;

			try
			{
				bank->deleteAccount(IBAN);
			}
			catch (std::invalid_argument& ia)
			{
				hasThrownException = true;
			}

			Assert::IsTrue(hasThrownException);
		}

		TEST_METHOD(BankDeleteCustomerExceptionTest)
		{
			bool hasThrownException = false;

			try
			{
				bank->deleteCustomer(CUSTOMER_ID);
			}
			catch (std::invalid_argument& ia)
			{
				hasThrownException = true;
			}

			Assert::IsTrue(hasThrownException);
		}

		TEST_METHOD(BankAddCustomerExceptionTest)
		{
			bank->addCustomer(NAME, AGE, CUSTOMER_ID);
			bool hasThrownException = false;
			
			try
			{
				bank->addCustomer(NAME, AGE, CUSTOMER_ID);
			}
			catch (std::invalid_argument& ia)
			{
				hasThrownException = true;
			}

			Assert::IsTrue(hasThrownException);
		}

		TEST_METHOD(BankAddBusinessCustomerExceptionTest)
		{
			bool hasThrownException = false;

			try
			{
				bank->addBusinessCustomer(NAME, AGE, CUSTOMER_ID, BUSINESS_TYPE);
			}
			catch (std::invalid_argument& ia)
			{
				hasThrownException = true;
			}

			Assert::IsFalse(hasThrownException);
		}

		TEST_METHOD(BankAddCheckingAccountExceptionTest)
		{
			bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);
			bool hasThrownException = false;

			try
			{
				bank->addCheckingAccount(IBAN, CUSTOMER_ID, ACCOUNT_BALANCE);
			}
			catch (std::invalid_argument& ia)
			{
				hasThrownException = true;
			}

			Assert::IsTrue(hasThrownException);
		}
	};

	TEST_CLASS(ManagerTest)
	{
	public:
		const std::string MANAGER_NAME = "Simeon Georgiev";
		const int MANAGER_AGE = 47;
		const double MANAGER_SALARY = 2000;

		const std::string EMPLOYEE_NAME = "Maya Dimitrova";
		const int EMPLOYEE_AGE = 33;
		const double EMPLOYEE_SALARY = 800;
		const std::string EMPLOYEE_POSITION = "Cashier";

		TEST_METHOD(ManagerAddEmployeeTest)
		{
			std::vector<Employee*> employees;
			Manager* manager = new Manager(MANAGER_NAME, MANAGER_AGE, employees, MANAGER_SALARY);

			manager->addEmployee(EMPLOYEE_NAME, EMPLOYEE_AGE, EMPLOYEE_POSITION, EMPLOYEE_SALARY);

			Assert::IsTrue(manager->getEmployees().size() == 1);
		}

		TEST_METHOD(ManagerRemoveEmployeeTest)
		{
			std::vector<Employee*> employees;
			Manager* manager = new Manager(MANAGER_NAME, MANAGER_AGE, employees, MANAGER_SALARY);
			manager->addEmployee(EMPLOYEE_NAME, EMPLOYEE_AGE, EMPLOYEE_POSITION, EMPLOYEE_SALARY);

			manager->removeEmployee(0);

			Assert::IsTrue(manager->getEmployees().size() == 0);
		}
	};
}
