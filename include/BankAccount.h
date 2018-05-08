#include <string>

class BankAccount {
	double balance_;

	const std::string INSUFFICIENT_FUNDS = "You don't have enough money for that transaction.";

public:
	explicit BankAccount(double starting_balance = 0);

	void deposit(double amount);

	bool withdraw(double amount);

	double get_balance();

	std::string info();
};