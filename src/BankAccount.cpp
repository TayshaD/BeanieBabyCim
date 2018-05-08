#include <BankAccount.h>

BankAccount::BankAccount(double starting_balance) : balance_(starting_balance) {};

void BankAccount::deposit(double amount) {
	//don't add negative money
	if (amount > 0) {
		this->balance_ += amount;
	}
}

bool BankAccount::withdraw(double amount) {
	if (amount <= this->balance_) {
		this->balance_ -= amount;
		return true;
	}

	return false;
}

double BankAccount::get_balance() {
	return this->balance_;
}

std::string BankAccount::info() {
	std::string info_string =  "You have $" + std::to_string(this->balance_)+ " in your account.";
	return info_string;
}