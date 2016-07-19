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
	int clock;
public:
	Patient() {}
	Patient(int clock, std::string firstName, std::string serName, int illnessLevel) 
		{numOfVisits = 0;
		this->clock = clock;
		this->firstName = firstName;
		this->serName = serName;
		this->illnessLevel = illnessLevel;
		}
	
	int setIllnessLevel() { 
	this->illnessLevel = random.randomIllnessLevel();
	numOfVisits++;
	return illnessLevel; 
	}
	int getIllnessLevel() { return illnessLevel; }
	int getnumOfVisits() { return numOfVisits; }
	
	std::string getFirstName() { return firstName; }
	std::string getSeranme() { return serName; }

};

#endif