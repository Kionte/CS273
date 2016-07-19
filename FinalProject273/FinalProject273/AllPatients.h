#ifndef ALLPATIENTS_H_
#define ALLPATIENTS_H_

#include<vector>
#include<string>
#include <fstream>
#include<iostream>
#include <ctime>
#include <cstdlib>

class AllPatients {
private:
	std::vector<std::string> FNallPatientsVector;
	std::vector<std::string> SNallPatientsVector;
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
	AllPatients() {} // no arg constructor
	std::string getFirstName(int num) {
		
		return FNallPatientsVector[num];
	}
	std::string getSername(int num) {
		return SNallPatientsVector[num];
	}
		
};

#endif // !ALLPATIENTS_H_
