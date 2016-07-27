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
#include <vector>
#include <iterator>
#include <iostream>
using std::queue;
using std::string;
using std::vector;

extern Random random;

class WaitingRoomQueue 
{
private:
	int loc;
	int lvl;
	int ttD;
	int ttN;
	int numOfDoc;
	int numOfNur;
	int visitTime;
	int patientsTreated;
	double rate;

	Patient patient;
	Citizens citizens;
	Doctor doctor;
	Nurse nurse;
	vector<HospitalRecords> hospitalRecordsVector;
	HospitalRecords hospitalRecords;
	string fName;
	string sname;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;
	vector<string> FNallPatientsVector;
	vector<string> SNallPatientsVector;

	int totalWait;

public:
	WaitingRoomQueue() {
		visitTime = 0;
		patientsTreated = 0;
	}
	void cast() {
		loc = rand() % 1000;
		lvl = patient.setIllnessLevel();
		ttD = doctor.setTreatmentTime();
		ttN = nurse.setTreatmentTime();
	}
	bool checkForCopy(int num) {
		for (int i = 0; i < hospitalRecordsVector.size(); i++) {
			if (getFirstName(num) == hospitalRecordsVector[i].getFName())
				return true;
		}
		return false;
	}
	void update(int clock)
	{
		//for (int i = 0; i < 10; i++) {
		cast();

		std::cout << random.next_double() << "  ";
		//	_sleep(1000);
		if (random.next_double() < rate)
		{
			std::vector<int>temp;
			if (numOfDoc > 0 || numOfNur > 0)
			{
				if (lvl > 10 && numOfDoc > 0) {
					doctorsQueue.push(new Patient(getFirstName(loc), getSername(loc), clock, ttD));
					if (!checkForCopy(loc)) {
						hospitalRecords.addRecords(getFirstName(loc), temp, lvl);
					}
				}
				else if (lvl < 11) {
					nursesQueue.push(new Patient(getFirstName(loc), getSername(loc), clock, ttN));
					if (!checkForCopy(loc))
						hospitalRecords.addRecords(getFirstName(loc), temp, lvl);
					else {
						std::map<std::string, std::vector<int>>::iterator it;
						it = hospitalRecords.hospitalRecords.find(getFirstName(loc));
						if (it == hospitalRecords.hospitalRecords.end()) { hospitalRecords.hospitalRecords[getFirstName(loc)].push_back(lvl); }

					}
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
	friend class TreatmentRoomQueue;


};
#endif