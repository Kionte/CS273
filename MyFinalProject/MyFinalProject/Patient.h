#ifndef PATIENT_H_
#define PATIENT_H_

#include <vector>
#include "Random.h"
struct Patient
{
	int arrivalTime;
	int startTreatmentTime;
	int totalTreatmentTime;
	int dischargeTime;

	int illnessLevel;
	std::string fName;
	std::string sName;
	Random random;
	
	Patient() {}
	Patient(std::string fName, std::string sName, int clock)
	{
		arrivalTime = clock;
		startTreatmentTime = -1;
		totalTreatmentTime = -1;
		dischargeTime = -1;
		this->fName = fName;
		this->sName = sName;
	}

	int getIllnessLevel() {
		return 0;
	}
	 int setIllnessLevel() {
		this->illnessLevel = random.randomIllnessLevel();
		return illnessLevel;
	}
};

#endif
