#ifndef WAITINGROOMSET_H_
#define WAITINGROOMSET_H_

#include <iostream>
#include <string>
#include <queue>
#include "Patient.h"
#include "Citizens.h"
#include "Random.h"
#include "HospitalRecords.h"
#include "CareGiver.h"
using std::queue;
using std::string;
using std::vector;

extern Random random;

class WaitingRoomSet : HospitalRecords
{
private:
	int loc;
	int lvl;
	int tt;
	int numOfDoc;
	int numOfNur;
	int visitTime;
	int patientsTreated;
	double rate;
	Patient patient;
	Citizens citizens;
	Doctor doctor;
	Nurse nurse;
	string fName;
	string sname;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;
	vector<string> FNallPatientsVector;
	vector<string> SNallPatientsVector;

	int totalWait;

public:
	WaitingRoomSet() {
		visitTime = 0;
		patientsTreated = 0;
	}
	void cast() {
		loc = rand() % 1000;
		lvl = patient.setIllnessLevel();
		tt = doctor.setTreatmentTime();
	}
	void update(int clock)
	{
		//for (int i = 0; i < 10; i++) {
			cast();
			
		
		if (random.next_double() < rate)
		{
			if (numOfDoc > 0 || numOfNur > 0) {
				if (lvl > 10 && numOfDoc > 0) {
					doctorsQueue.push(new Patient(getFirstName(loc), getSername(loc), clock, tt));
					addRecords(new Patient(getFirstName(loc), getSername(loc), clock, tt), lvl);
				}
				else if (lvl < 10) {
					nursesQueue.push(new Patient(getFirstName(loc), getSername(loc), clock, tt));
					addRecords(new Patient(getFirstName(loc), getSername(loc), clock, tt), lvl);
				}
			}
			
		}	
	}

	string getFirstName(int num) {
		return FNallPatientsVector[num];
	}
	string getSername(int num) {
		return SNallPatientsVector[num];
	}
	void setFirstName(vector<string>FNallPatients) {
		this->FNallPatientsVector = FNallPatients;
	}
	void setSerName(vector<string>SNallPatients) {
		this->SNallPatientsVector = SNallPatients;
	}
	void setRate(double rate) {
		this->rate = rate;
	}
	void setNur(int nur) {
		this->numOfNur = nur;
	}
	void setDoc(int doc) {
		this->numOfDoc = doc;
	}
	int getVisitTime() { return visitTime; }
	int getPatientsTreted() { return patientsTreated; }
	void setVisitTime(int time) { this->visitTime += time; }
	void setPatientsTreated() { patientsTreated++; }
	friend class TreatmentRoomSet;

};
#endif