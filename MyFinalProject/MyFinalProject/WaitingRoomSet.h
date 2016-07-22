#ifndef WAITINGROOMSET_H_
#define WAITINGROOMSET_H_

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include "Patient.h"
#include "Citizens.h"
#include "Random.h"
#include "ctime"
#include "cstdlib"
#include "HospitalRecords.h"
using std::queue;
using std::string;
using std::vector;

extern Random random;

class WaitingRoomSet : HospitalRecords
{
private:
	int loc;
	int lvl;
	int numOfDoc;
	int numOfNur;
	double rate;
	Patient patient;
	Citizens citizens;
	string fName;
	string sname;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;
	vector<string> FNallPatientsVector;
	vector<string> SNallPatientsVector;
	int totalWait;

public:
	WaitingRoomSet() {}

	void update(int clock)
	{ 
		srand(time(0));
		loc = rand() % 2000;
		lvl = patient.setIllnessLevel();
		if (random.next_double() < rate) 
		{
			if (numOfDoc > 0 && numOfNur > 0) {
				if (lvl > 10 && numOfDoc > 0) {
					doctorsQueue.push(new Patient(getFirstName(loc), getSername(loc), clock));
					addRecords(new Patient(getFirstName(loc), getSername(loc), clock), lvl);
				}
				else if(lvl < 10) {
					nursesQueue.push(new Patient(getFirstName(loc), getSername(loc), clock));
					addRecords(new Patient(getFirstName(loc), getSername(loc), clock), lvl);
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
	void setRate(double rate) {
		this->rate = rate;
	}
	void setNur(int nur) {
		this->numOfNur = nur;
	}
	void setDoc(int doc) {
		this->numOfDoc = doc;
	}
	friend class TreatmentRoomSet;

};
#endif