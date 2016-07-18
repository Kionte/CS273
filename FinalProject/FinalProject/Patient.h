#ifndef PATIENT_H_
#define PATIENT_H_

#include "Doctor.h"
#include "Nurse.h"
#include <fstream>
#include "PatientRecords.h"
#include "Random.h"

class Patient {
private:
	std::string firstName;
	std::string serName;
	PatientRecords patientRecords;
	Random random;
	
protected:
	int illnessLevel;
	int numOfVisits;
	
public:
	Patient patient() {
		firstName = ""; // = text file
		serName = ""; //
	}
	void setIllnessLevel() { this->illnessLevel = random.randomIllnessLevel(); numOfVisits++; }
	int getIllnessLevel() { return illnessLevel; }
	int getnumOfVisits() { return numOfVisits; }


};

#endif