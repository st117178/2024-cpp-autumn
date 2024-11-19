#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include "BankAccount.h"

class Bank
{
public:
	void AddAccount(BankAccount *account);
	double GetTotalBalnce();
	void PrintAllAccounts();

private:
	std::vector<BankAccount *> accounts;
};

#endif