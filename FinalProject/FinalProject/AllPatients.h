#ifndef ALLPATIENTS_H_
#define ALLPATIENTS_H_

#include<vector>
#include<string>

#include <fstream>

class AllPatients {
private:
	std::vector<std::string> allPatientsVector;
public:
	void addPeopleToVector() {
		std::fstream firstName("residents_of_273ville.txt",ios::in | ios::out);
		std::fstream surName("surname_of_273ville.txt",ios::in | ios::out);

		if (firstName.fail()) {
			std::cout << "fail";
		}
		else if (surName.fail()) {
			std::cout << "fail";
		}
		else {
			while (std::getline(firstName, str)) {
				firstName.push_back(getline(firstName[]));
			}
			while (std::getline(surName, str)) {
				surname, push_back(getline(surname[i]));
			}
			allPatientsVector.push_back();
		}

	}


};

#endif // !ALLPATIENTS_H_
