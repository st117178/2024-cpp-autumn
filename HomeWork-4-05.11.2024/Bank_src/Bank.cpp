#ifndef BANK_CPP
#define BANK_CPP

#include "Bank.h"

void Bank::AddAccount(BankAccount* account)
{
	accounts.push_back(account);
}

double Bank::GetTotalBalnce()
{
	double sum = 0;
	for (BankAccount* acc : accounts)
	{
		sum += acc->GetBalance();
	}

	return sum;
}

void Bank::PrintAllAccounts()
{
	for (BankAccount* acc : accounts)
	{
		acc->PrintAccountInfo();
	}
}

#endif