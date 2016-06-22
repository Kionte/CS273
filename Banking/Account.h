#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <sstream>
#include "Customer.h"
#include "Transaction.h"

/**
The Bank has Accounts and an Account belongs to a Customer.
Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.

@author: Ed Walker
*/

class Account {
protected:
	Customer *customer;		// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;		// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account

	/**
	Describe fees associated with the customer who owns this account.
	The fee will depend on the specific type of customer.
	@return string showing checking and overdraft fees
	*/
	std::string get_fees()
	{
		int overdraft, charge;

		// Polymorphism: calls the correct virtual methods from the specific customer type
		// FIXME: Get the overdraft and check charge information from this accounts customer

		std::stringstream ss;
		ss << "Check Charge: " << charge << " Overdraft Fee: " << overdraft;
		return ss.str();
	}

protected:
	/**
	Add interest based on a specified interest rate to account
	@param interest	The interest rate
	*/
	void add_interest(double interest) {
		double amt = balance*interest;
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = NULL;

		// Create a Transaction object and assign it to the transaction vector.
		tran = new Transaction(account_number, " Add interest ", amt, fees);
		transactions.push_back(tran);
	}

public:
	/**
	Constructor requires a customer to create an account
	Balance always starts with 0 when account is created.
	*/
	Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}

	/**
	Generic accesser and setter methods for properties customer, balance, and account_number
	*/

	Customer *get_customer() {
		return customer;
	}

	void set_customer(Customer *cust) {
		customer = cust;
	}

	int get_account() {
		return account_number;
	}

	void set_balance(double new_balance) {
		balance = new_balance;
	}

	void set_account(int account_number) {
		this->account_number = account_number;
	}

	double get_balance() {
		return balance;
	}

	/**
	Generic method describing the account information.

	Remember that you will need to indicate if an account is Savings or Checking in 
	an overridden version of to_string() in the derived classes. 

	@return string describing generic information about the account
	*/
	virtual std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

		// Add information about the customer who owns this account.
		
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		//for (int i = 0; i < transactions.size(); i++) {
		//	ss << "  " << i + 1 << ":" << transactions[i]->process_tran() << std::endl;
		//}
		return ss.str();
	}

	/**
	Deposits amount into account
	@param amt The deposit amount
	*/
	virtual void deposit(double amt) {
		balance += amt;
		std::string fees = get_fees();
		Transaction *tran = NULL;

		// Create a Transaction object and assign it to transaction vector.
		tran = new Transaction(account_number, "Deposit", amt, fees);
		transactions.push_back(tran);
	}

	/**
	Withdraws amount from account
	@param amt The withdrawal amount
	*/
	virtual void withdraw(double amt) {
		std::cout << "PL\n";
		balance -= amt;
		std::string fees = get_fees();
		//std::cout << "SRGpoiupoiupoiu\n";
		Transaction *tran = NULL;
		

		// Create a Transaction object and assign it to tran.
		tran = new Transaction(account_number,"withdraw",amt,fees);
		transactions.push_back(tran);
	}

	// We want the Savings_Account and Checking_Account to implement this.
	virtual void add_interest() = 0;

};
class Checking_Account : public Account {
public:
	Checking_Account(Customer * cust, int id, double balance) : Account(cust, id) { balance = 0; }
	void add_interest() {

	}
	
};
class Savings_Account : public Account{
public:
	Savings_Account(Customer * cust, int id, double balance) : Account(cust, id) { balance = 0; }
	void add_interest() {

	}
};


#endif