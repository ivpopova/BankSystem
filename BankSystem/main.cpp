#include<iostream>
#include"Bank.h"
#include"Manager.h"
#include"Menu.h" 

int main()
{
	std::map<std::string, Customer*> customers;
	std::map<std::string, Account*> accounts;
	std::vector<Employee*> employees;

	Manager* manager = new Manager("Ivan Ivanov", 55, employees, 20000);
	Bank bank("DEMO BANK SYSTEM", manager, customers, accounts);

	bank.addCustomer("Lili Petrova", 33, "1111");
	bank.addCustomer("Ana Dimitrova", 28, "2211");
	bank.addCustomer("Petya Mitova", 20, "3211");
	bank.addCustomer("Peter Petrov",  32, "3200");
	
	bank.addBusinessCustomer("Ivo Ivanov",  55, "9987", "Large");
	bank.addBusinessCustomer("Boyka Stanoeva", 35, "8087", "Small");
	
	bank.addCheckingAccount("12345AA", "1111", 3000.00);
	bank.addCheckingAccount("12345BB", "2211", 4000.00);
	bank.addCheckingAccount("33345AA", "9987", 6000.00);

	bank.addSavingsAccount("33345CC", "3211", 4000.00, 1.2);
	bank.addSavingsAccount("33667CC", "300", 200.00, 0.8);

	bank.getLoan("8087", 2.2, 10000);

	manager->addEmployee("Martina Dimitrova", 35, "Accountant", 2500);
	manager->addEmployee("Elena Nikolova", 40, "Cashier", 800);
	manager->addEmployee("Evgeni Georgiev", 33, "Cashier", 800);

	Menu menu;
	int option;

	do 
	{
		menu.showMenu();
		std::cin >> option;

		if (option == 1) 
		{
			menu.listCustomers(bank);
		}
		else if (option == 2) 
		{
			menu.addNewCustomer(bank);
		}
		else if (option == 3) 
		{
			menu.addNewBusinessCustomer(bank);
		}
		else if (option == 4)
		{
			menu.deleteCustomer(bank);
		}
		else if (option == 5)
		{
			menu.listAllAccounts(bank);
		}
		else if (option == 6)
		{
			menu.listCustomerAccount(bank);
		}
		else if (option == 7)
		{
			menu.addNewCheckingAccount(bank);
		}
		else if (option == 8)
		{		
			menu.addNewSavingAccount(bank);
		}
		else if (option == 9) 
		{ 
			menu.deleteAccount(bank);
		}
		else if (option == 10) 
		{ 
			menu.withdrawFromAccount(bank);
		}
		else if (option == 11) 
		{
			menu.depositToAccount(bank);
		}
		else if (option == 12) 
		{
			menu.transfer(bank);
		}
		else if (option == 13) 
		{
			menu.getLoan(bank);
		}
		else if (option == 14) 
		{
			menu.listEmployees(bank);
		}
	
	} while (option < 16 && option > 0);

	std::cout << "***************QUIT*****************";
	return 0;
}