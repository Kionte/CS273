#ifndef CITIZENS_H_
#define CITIZENS_H_

#include<vector>
#include<string>
#include <fstream>
#include<iostream>
#include <ctime>
#include <cstdlib>

class Citizens {
private:
	std::vector<std::string> FNallPatientsVector; // used to stor the parients first name 
	std::vector<std::string> SNallPatientsVector; // used to store the patients last name 
	std::string firstName;
public:
	void addPeopleToVector() {
		std::ifstream firstName("residents_of_273ville.txt"); // pulls txt file
		std::ifstream surName("surnames_of_273ville.txt");
		int num = 0;
		if (firstName.fail()) { // makes sure it can still pull names
			std::cout << "fail"; 
		}
		else if (surName.fail()) { 
			std::cout << "fail";
		}
		else {
			std::string line; // set up string to actually get names
			std::string line2;
			while (std::getline(firstName, line)) { // loop that will add al the names to the first name vecotr
				FNallPatientsVector.push_back(line);
				//	std::cout << FNallPatientsVector[num];
				//		std::cout << "\n\n" << FNallPatientsVector.size();
				num++;
			}
			num = 0;
			while (std::getline(surName, line2)) { // loop that will add all the names to the first name vector
				SNallPatientsVector.push_back(line2);
				//	std::cout << SNallPatientsVector[num];
				num++;
			}

		}

	}
	Citizens() {} // no arg constructor

	std::vector<std::string> getVector() { // used to get the vector of first names
		return FNallPatientsVector;
	}
	std::vector<std::string> getSNVector() { // ''   '' last name 
		return SNallPatientsVector;
	}

	friend class EmergencyRoom; 
};


#endif // !ALLPATIENTS_H_
