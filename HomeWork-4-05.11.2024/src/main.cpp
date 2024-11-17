#include "BankAccount.h"
#include "Bank.h"

int main(int argc, char* argv[])
{
	BankAccount bankAcc1("1", 12346.12, "Artem");
	BankAccount bankAcc2("2", 666.777, "Ilya");
	BankAccount bankAcc3("3", 228.1337, "Zahar");

	Bank bank;
	bank.AddAccount(&bankAcc1);
	bank.AddAccount(&bankAcc2);
	bank.AddAccount(&bankAcc3);

	bank.PrintAllAccounts();

	bankAcc1.Deposit(100);
	bank.PrintAllAccounts();

	bankAcc2.Withdraw(1000);
	bank.PrintAllAccounts();

	bankAcc1.Withdraw(12000);
	bank.PrintAllAccounts();

	return 0;
};