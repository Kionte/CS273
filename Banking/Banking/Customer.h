#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates, 
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // Complete the implementation!
{
protected:
	int age;
	std::string name;
	std::string address;
	std::string telephone;

protected:
	std::string cust_type;
	std::string account_type;

public:
	Customer(int age,std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) {
		this->age = age;
		this->name = name;
		this->address = address;
		this->telephone = telephone;
		this->cust_type = cust_type;
		this->account_type = account_type;
	}
	int getAge() {
		return age;
	}
	std::string getName(){
		return name;
	}
	std::string getAddress(){
			return address;
	}
	std::string getTelephone(){
			return telephone;
	}
	std::string getCusType() {
		return cust_type;
	}
	std::string getAccountType() {
		return account_type;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setAddress(std::string address) {
		this->address = address;
	}
	void setTelephone(std::string telephone) {
		this->telephone = telephone;
	}

	virtual double checking_interest_rates() = 0;
	virtual double savings_interest_rates() = 0;
	virtual double overdraft_fees() = 0;
	virtual double check_charge() = 0;
	virtual double overdraft_penalty() = 0;
};

class Adult : public Customer {
public:
	Adult(int age, std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) : Customer(age, name, address, telephone, cust_type, account_type) {}
	double checking_interest_rates() {
		return .02;
	}
	double savings_interest_rates() {
		return .05;
	}
	double overdraft_fees() {
		return 25.0;
	}
	double check_charge() {
		return 5;
	}
	double overdraft_penalty() {
		return 10.0;
	}
};

class Senior : public Customer {
public:
	Senior(int age, std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) : Customer(age, name, address, telephone, cust_type, account_type) {}
	double checking_interest_rates() {
		return .04;
	}
	double savings_interest_rates() {
		return .1;
	}
	double overdraft_fees() {
		return 25.0;
	}
	double check_charge() {
		return 5;
	}
	double overdraft_penalty() {
		return 10.0;
	}
};

class Student : public Customer {
public:
	Student(int age, std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) : Customer(age, name, address, telephone, cust_type, account_type) {}
	double checking_interest_rates() {
		return .08;
	}
	double savings_interest_rates() {
		return .2;
	}
	double overdraft_fees() {
		return 2.50;
	}
	double check_charge() {
		return .5;
	}
	double overdraft_penalty() {
		return 1.00;
	}
};


#endif