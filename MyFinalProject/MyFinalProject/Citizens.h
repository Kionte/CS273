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
	std::vector<std::string> FNallPatientsVector;
	std::vector<std::string> SNallPatientsVector;
	std::string firstName;
public:
	void addPeopleToVector() {
		std::ifstream firstName("residents_of_273ville.txt");
		std::ifstream surName("surnames_of_273ville.txt");
		int num = 0;
		if (firstName.fail()) {
			std::cout << "fail";
		}
		else if (surName.fail()) {
			std::cout << "fail";
		}
		else {
			std::string line;
			std::string line2;
			while (std::getline(firstName, line)) {
				FNallPatientsVector.push_back(line);
				//	std::cout << FNallPatientsVector[num];
				//		std::cout << "\n\n" << FNallPatientsVector.size();
				num++;
			}
			num = 0;
			while (std::getline(surName, line2)) {
				SNallPatientsVector.push_back(line2);
				//	std::cout << SNallPatientsVector[num];
				num++;
			}

		}

	}
	Citizens() {} // no arg constructor

	std::vector<std::string> getVector() {
		return FNallPatientsVector;
	}
	std::vector<std::string> getSNVector() {
		return SNallPatientsVector;
	}

	friend class EmergencyRoom;
};


#endif // !ALLPATIENTS_H_
