#ifndef BANK_H_
#define BANK_H_
#include <vector>
#include <stdexcept>
#include "Account.h"
#include "Customer.h"

/**
The CS273 Bank has Accounts and Customers

@author: Ed Walker
*/
class Bank
{
private:
	std::vector<Account *> accounts; // Bank HAS accounts
	std::vector<Customer *> customers;  // Bank HAS customers

	// Counters for generating unique account and customer IDs
	int account_id;
	int customer_id;


	/**
	Return a vector of accounts owned by the specified name of the customer.
	Remember a customer can have many accounts.
	@param name The customer name
	@return vector of account ids
	*/
	std::vector<int> find_accounts_by_name(std::string name)
	{
		std::vector<int> user_accounts;
		// Find all the accounts belonging to a customer name and add it to the vector of account numbers.
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->get_customer()->getName() == name)
				user_accounts.push_back(accounts[i]->get_account());
		}
		return user_accounts;
	
	}

	/**
	Find a customer based on his/her name
	@param name The customer name
	@return customer object if found, NULL otherwise
	*/
	Customer *find_customer(std::string name)
	{
		for (int i = 0; i < customers.size();i++) {
			if (customers[i]->getName() == name)
				return customers[i];
		}
		// Find and return the Customer object with the parameter name
		return NULL;
	}

	/**
	Add a new account to a customer object (irrespective of its specific type: adult, senior, or student)
	@param cust The customer object
	@param account_type The account type, i.e. "savings" or "checking"
	@return the newly created account object
	*/
	Account * add_account(Customer *cust, std::string account_type)
	{


		Account *acct = NULL;
		account_id++;
		if (account_type == "savings")
				acct = new Savings_Account(cust,account_id,0);
		else if (account_type == "checking")
			acct = new Checking_Account(cust, account_id, 0);
		else
			std::cout << "not valid account type\n";
		// Factory method for creating a Account object (could be a Saving_Account or a Checking_Account).
		accounts.push_back(acct);
		return acct;
	}



public:
	/** Constructor
	*/
	Bank() : account_id(1000), customer_id(1000) {}

	/**
	Add account for an existing user
	@param name The customer name
	@param account_type The account type, i.e. "checking" or "savings"
	@return the newly created account object if the customer exist, or NULL otherwise
	*/
	Account* add_account(std::string name, std::string account_type)
	{
		Customer *cust = find_customer(name);
		if (cust == NULL)
			return NULL;
		return add_account(cust, account_type);
	}

	/**
	Add account for new user.  This creates a new customer and adds an account to him/her.
	@param name Customer name
	@param address Customer address
	@param telephone Customer telephone number
	@param age Customer age
	@param cust_type Customer type, i.e. "adult", "senior" or "student"
	@param account_type Account type, i.e. "checking" or "savings"
	@return the newly created account object
	*/
	Account* add_account(std::string name, std::string address, std::string telephone, int age, std::string cust_type, std::string account_type)
		// Depending on the customer type, we want to create an Adult, Senior, or Student object.
	{
		Customer *cust;
		if (cust_type == "adult") 
			cust = new Adult(age, name, address, telephone, cust_type, account_type);
		else if (cust_type == "senior")
			cust = new Senior(age, name, address, telephone, cust_type, account_type);
		else if (cust_type == "tudent")
			cust = new Student(age, name, address, telephone, cust_type, account_type);
		else {
			std::cout << "Not a valid Type";
			return 0;
		}
		customers.push_back(cust);
		return add_account(cust, account_type);
		}

		/**
		Make a deposit in an account identified by the account id
		@param acct_number	The account id
		@param amt			The amount to deposit
		*/
		void make_deposit(int acct_number, double amt)
		{
			Account *acct = get_account(acct_number);
			if (acct) {
				// Deposit the amt in the account
				// acct->deposit(amt);

			}
		}

		/**
		Make a withdrawal in an account identified by the account id
		@param acct_number	The account id
		@param amt			The amount to withdraw
		*/
		void make_withdrawal(int acct_number, double amt)
		{
			Account *acct = get_account(acct_number);
			if (acct) {
				// Withdraw the amt from the account
				// acct->withdraw(amt);
			}
		}

		/**
		Get the list of account numbers associated with a user, identified by his/her name
		@param name The customer name
		@return vector of account ids
		*/
		std::vector<int> get_account(std::string name)
		{
			return find_accounts_by_name(name);
		}

		/**
		Get the account object for an account identified by an account id
		@param acct_name The account id
		@return the account object if it exists, NULL otherwise
		*/
		Account *get_account(int acct_number)
		{
			for (size_t i = 0; i < accounts.size(); i++) {
				if (accounts[i]->get_account() == acct_number)
					return accounts[i]; 
			}
			return NULL;
		}
	};

#endif
