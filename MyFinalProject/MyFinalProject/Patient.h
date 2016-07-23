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
	Patient(std::string fName, std::string sName, int clock, int totalTreatmentTime)
	{
		this->arrivalTime = clock;
		this->startTreatmentTime = -1;
		this->dischargeTime = -1;
		this->fName = fName;
		this->sName = sName;
		this->totalTreatmentTime = totalTreatmentTime;

	}

	int getIllnessLevel() {
		return 0;
	}
	int setIllnessLevel() {
		this->illnessLevel = random.randomIllnessLevel();
		return illnessLevel;

	}
	int getTreatmentTime() {
		return totalTreatmentTime;
	}
	void setTreatmentTime(int startTreatmentTime) {
		this->startTreatmentTime = startTreatmentTime;

	}

};

#endif
