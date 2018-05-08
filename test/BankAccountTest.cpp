#include "catch.hpp"
#include <BankAccount.h>

TEST_CASE("Depositing funds") {
	BankAccount account(300);
	SECTION("Valid amount") {
		account.deposit(500);
		REQUIRE(account.get_balance() == 800);
	}

	SECTION("Negative amount") {
		account.deposit(-30);
		REQUIRE(account.get_balance() == 300);
	}
}

TEST_CASE("Withdrawing funds") {
	BankAccount account(40);
	SECTION("Valid amount") {
		account.withdraw(40);
		REQUIRE(account.get_balance() == 0);
	}

	SECTION("Invalid amount") {
		account.withdraw(50);
		REQUIRE(account.get_balance() == 40);
	}
}

TEST_CASE("Info string") {
	BankAccount account(5);
	REQUIRE(account.info() == "You have $5 in your account.");
}