#ifndef BEANIEBABYSIM_BANKACCOUNT_H
#define BEANIEBABYSIM_BANKACCOUNT_H

#include <string>

class BankAccount {
	double balance_;

public:

	static const std::string INSUFFICIENT_FUNDS = "You don't have enough money for that transaction.";

	explicit BankAccount(double starting_balance = 0);

	void deposit(double amount);

	bool withdraw(double amount);

	double get_balance();

	std::string info();
};

#endif //BEANIEBABYSIM_BANKACCOUNT_H