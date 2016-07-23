#ifndef CAREGIVER_H_
#define CAREGIVER_H_

#include<string>
#include<ctime>
#include<cstdlib>

class CareGiver {

private:
	int numOfCareGiver;
	int treatmentTime;

public:
	CareGiver() {}
	virtual int getNumOfCareGiver() = 0;
	virtual void setNumOfCareGiver(int numOfCareGiver) = 0;
	virtual int getTreatmentTime() = 0;
	virtual int setTreatmentTime() = 0;

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