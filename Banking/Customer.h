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
class Customer // FIXME: Complete the implementation!
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
		double rate;
		return rate;
	}
	double savings_interest_rates() {
		double rate;
		return rate;
	}
	virtual double overdraft_fees() {
		double rate;
		return rate;
	}
	virtual double check_charge() {
		double rate;
		return rate;
	}
	virtual double overdraft_penalty() {
		double rate;
		return rate;
	}
};

class Senior : public Customer {
public:
	Senior(int age, std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) : Customer(age, name, address, telephone, cust_type, account_type) {}
	double checking_interest_rates() {
		double rate;
		return rate;
	}
	double savings_interest_rates() {
		double rate;
		return rate;
	}
	virtual double overdraft_fees() {
		double rate;
		return rate;
	}
	virtual double check_charge() {
		double rate;
		return rate;
	}
	virtual double overdraft_penalty() {
		double rate;
		return rate;
	}
};

class Student : public Customer {
public:
	Student(int age, std::string name, std::string address, std::string telephone, std::string cust_type, std::string account_type) : Customer(age, name, address, telephone, cust_type, account_type) {}
	double checking_interest_rates() {
		double rate;
		return rate;
	}
	double savings_interest_rates() {
		double rate;
		return rate;
	}
	virtual double overdraft_fees() {
		double rate;
		return rate;
	}
	virtual double check_charge() {
		double rate;
		return rate;
	}
	virtual double overdraft_penalty() {
		double rate;
		return rate;
	}
};


#endif