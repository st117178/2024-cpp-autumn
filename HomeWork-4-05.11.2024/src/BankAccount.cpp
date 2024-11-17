#ifndef BANK_ACCOUNT_CPP
#define BANK_ACCOUNT_CPP

#include "BankAccount.h"

BankAccount::BankAccount(std::string accountNumber, double balance, std::string accountHolder) :
	accountNumber(accountNumber), balance(balance), accountHolder(accountHolder) {}

void BankAccount::Deposit(double amount)
{
	balance += amount;
}

void BankAccount::Withdraw(double amount)
{
	if (amount > balance)
	{
		std::cout << "Error: Insufficient funds in the account" << std::endl;
	}
	else
	{
		balance -= amount;
	}
}

double BankAccount::GetBalance()
{
	return balance;
}

std::string BankAccount::GetAccountHolder()
{
	return accountHolder;
}

std::string BankAccount::GetAccountNumber()
{
	return accountNumber;
}

void BankAccount::PrintAccountInfo()
{
	std::cout << "Account number: " << accountNumber << std::endl;
	std::cout << "Account holder: " << accountHolder << std::endl;
	std::cout << "Account balance: " << balance << std::endl;
}

#endif