#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

class BankAccount {
public:
	BankAccount(std::string accountNumber, double balance, std::string accountHolder);
	void Deposit(double amount);
	void Withdraw(double amount);
	double GetBalance();
	std::string GetAccountHolder();
	std::string GetAccountNumber();
	void PrintAccountInfo();
private:
	std::string accountNumber;
	double balance;
	std::string accountHolder;
};

#endif