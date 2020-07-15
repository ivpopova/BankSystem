#include "Menu.h"

void Menu::showMenu()
{
	std::cout << "****BANK MENU****" << std::endl;
	std::cout << ">>>>> Options <<<<" << std::endl;
	std::cout << "1 - List customers" << std::endl;
	std::cout << "2 - Add new customer" << std::endl;
	std::cout << "3 - Add new business customer" << std::endl;
	std::cout << "4 - Delete customer" << std::endl;
	std::cout << "5 - List all accounts" << std::endl;
	std::cout << "6 - List customer account" << std::endl;
	std::cout << "7 - Add new Checking Account" << std::endl;
	std::cout << "8 - Add new Saving Account" << std::endl;
	std::cout << "9 - Delete account" << std::endl;
	std::cout << "10 - Withdraw from account" << std::endl;
	std::cout << "11 - Deposit to account" << std::endl;
	std::cout << "12 - Transfer" << std::endl;
	std::cout << "13 - Get Loan" << std::endl;
	std::cout << "14 - List Employees" << std::endl;
	std::cout << "Quit - Any other number" << std::endl;
	std::cout << "................................." << std::endl;
	std::cout << "Enter option: ";
}

void Menu::listCustomers(Bank& bank)
{
	bank.listCustomers();
}

void Menu::addNewCustomer(Bank& bank)
{
	while (true)
	{
		std::cout << "Please enter name: " << std::endl;
		std::string name;
		std::cin >> name;

		std::cout << "Please enter age: " << std::endl;
		int age;
		std::cin >> age;

		std::cout << "Please enter customer ID: " << std::endl;
		std::string customerID;
		std::cin >> customerID;

		try 
		{
			bank.addCustomer(name, age, customerID);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::addNewBusinessCustomer(Bank& bank)
{
	while (true) 
	{
		std::cout << "Please enter name: " << std::endl;
		std::string name;
		std::cin >> name;

		std::cout << "Please enter age: " << std::endl;
		int age;
		std::cin >> age;

		std::cout << "Please enter customer ID: " << std::endl;
		std::string customerID;
		std::cin >> customerID;

		std::cout << "Please enter Business Type: " << std::endl;
		std::string businessType;
		std::cin >> businessType;

		try 
		{
			bank.addBusinessCustomer(name, age, customerID, businessType);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::deleteCustomer(Bank& bank)
{
	while (true) 
	{
		std::string customerID;
		std::cout << "Delete customer with ID: " << std::endl;
		std::cin >> customerID;

		try 
		{
			bank.deleteCustomer(customerID);
			break;
		}
		catch (std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::listAllAccounts(Bank& bank)
{
	bank.listAccounts();
}

void Menu::listCustomerAccount(Bank& bank)
{
	while (true) 
	{
		std::string IBAN;
		std::cout << "Please enter the IBAN number for information: " << std::endl;
		std::cin >> IBAN;

		try 
		{
			bank.listCustomerAccount(IBAN);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::addNewCheckingAccount(Bank& bank)
{
	while (true) 
	{
		std::cout << "Please enter the IBAN number: " << std::endl;
		std::string IBAN;
		std::cin >> IBAN;

		std::cout << "Please enter customer ID: " << std::endl;
		std::string customerID;
		std::cin >> customerID;

		std::cout << "Please enter balance: " << std::endl;
		double balance;
		std::cin >> balance;

		try 
		{
			bank.addCheckingAccount(IBAN, customerID, balance);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::addNewSavingAccount(Bank& bank)
{
	while (true) 
	{
		std::cout << "Please enter the IBAN number: " << std::endl;
		std::string IBAN;
		std::cin >> IBAN;

		std::cout << "Please enter customer ID: " << std::endl;
		std::string customerID;
		std::cin >> customerID;

		std::cout << "Please enter balance: " << std::endl;
		double balance;
		std::cin >> balance;

		std::cout << "Please enter interestRate: " << std::endl;
		double interestRate;
		std::cin >> interestRate;

		try 
		{
			bank.addSavingsAccount(IBAN, customerID, balance, interestRate);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::deleteAccount(Bank& bank)
{
	while (true) 
	{
		std::cout << "Delete account with IBAN number: " << std::endl;
		std::string IBAN;
		std::cin >> IBAN;

		try 
		{
			bank.deleteAccount(IBAN);
			break;
		}
		catch (std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::withdrawFromAccount(Bank& bank)
{
	while (true)
	{
		std::string IBAN;
		std::cout << "Please enter IBAN: " << std::endl;
		std::cin >> IBAN;

		double amount;
		std::cout << "Please enter the amount: " << std::endl;
		std::cin >> amount;

		try 
		{
			bank.isValidTransaction(amount, IBAN);
			bank.withdraw(IBAN, amount);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::depositToAccount(Bank& bank)
{
	while (true) {
		std::string IBAN;
		std::cout << "Please enter IBAN: " << std::endl;
		std::cin >> IBAN;

		double amount;
		std::cout << "Please enter the amount: " << std::endl;
		std::cin >> amount;

		try
		{
			bank.deposit(IBAN, amount);
			break;
		}
		catch (std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::transfer(Bank& bank)
{
	while (true) 
	{
		std::string fromIBAN;
		std::cout << "Please enter IBAN of the sender: " << std::endl;
		std::cin >> fromIBAN;

		std::string toIBAN;
		std::cout << "Please enter IBAN of the receiver: " << std::endl;
		std::cin >> toIBAN;

		double amount;
		std::cout << "Please enter the amount to withdraw: " << std::endl;
		std::cin >> amount;

		try 
		{
			bank.isValidTransaction(amount, fromIBAN);

			bank.withdraw(fromIBAN, amount);
			bank.deposit(toIBAN, amount);
			break;
		}
		catch (std::invalid_argument& ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::getLoan(Bank& bank)
{
	while (true) 
	{
		std::cout << "Please enter amount: " << std::endl;
		double amount;
		std::cin >> amount;

		std::cout << "Please enter loanRate: " << std::endl;
		double loanRate;
		std::cin >> loanRate;

		std::cout << "Please enter customer ID: " << std::endl;
		std::string customerID;
		std::cin >> customerID;

		try 
		{
			bank.getLoan(customerID, loanRate, amount);
			break;
		}
		catch (std::invalid_argument& ia) 
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

void Menu::listEmployees(Bank& bank)
{
	bank.listEmployees();
}

