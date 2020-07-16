#pragma once
#include<iostream>
#include"Bank.h"
#include "Manager.h"

class Menu 
{
public:
	void showMenu();
	void listCustomers(Bank&);
	void addNewCustomer(Bank&);
	void addNewBusinessCustomer(Bank&);
	void deleteCustomer(Bank&);
	void listAllAccounts(Bank&);
	void listCustomerAccount(Bank&);
	void addNewCheckingAccount(Bank&);
	void addNewSavingAccount(Bank&);
	void deleteAccount(Bank&);
	void withdrawFromAccount(Bank&);
	void depositToAccount(Bank&);
	void transfer(Bank&);
	void getLoan(Bank&);
	void listEmployees(Bank&);
};