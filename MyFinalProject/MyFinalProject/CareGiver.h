#ifndef CAREGIVER_H_
#define CAREGIVER_H_

#include<string>
#include<ctime>
#include<cstdlib>

class CareGiver {

private:
	int numOfCareGiver; // user input 
	int treatmentTime; // random num

public:
	CareGiver() {}
	virtual int getNumOfCareGiver() = 0; // used to keep trck of cargivers
	virtual void setNumOfCareGiver(int numOfCareGiver) = 0; // used after user input 
	virtual int getTreatmentTime() = 0; // used to apply random value for treating patients
	virtual int setTreatmentTime() = 0; // will return a random int iether between 1-10(nurse) or 1-20(doctor)

};
class Doctor : public CareGiver {
private:
	int numOfCareGiver;
	int treatmentTime;
public:
	Doctor() : CareGiver() {}

	int getNumOfCareGiver() {
		return numOfCareGiver;
	}
	void setNumOfCareGiver(int numOfCareGivers) {
		this->numOfCareGiver = numOfCareGiver;
	}
	int getTreatmentTime() {
		return treatmentTime;
	}
		
	int setTreatmentTime() {
		return rand() % 20 + 1;
	 }
};

class Nurse : public CareGiver {
private:
	int numOfCareGiver;
	int treatmentTime;
public:
	Nurse() : CareGiver() {}

	int getNumOfCareGiver() {
		return numOfCareGiver;
	}
	void setNumOfCareGiver(int numOfCareGivers) {

		this->numOfCareGiver = numOfCareGiver;
	}
	int getTreatmentTime() {
		return treatmentTime;
	}

	int setTreatmentTime() {
		return  rand() % 10 + 1;
	}
};


#endif
