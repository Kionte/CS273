#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "Random.h"
#include "Patient.h"
#include "EmergencyRoom.h"
#include "AllPatients.h"

class WaitingRoomQueue {

private:
	std::priority_queue<Patient*> waitingRoomQueue;
	DischargeQueue *dischargeQueue;
	std::vector<std::string> FNallPatientsVector;
	std::vector<std::string> SNallPatientsVector;

	double numOfPatients;
	Random r = 0;
	AllPatients ap;
	Patient p;
	int num;
public:
	WaitingRoomQueue() { }
	void setNumOfPatientsPerHour(double numOfPatients) {
		this->numOfPatients = numOfPatients;
	}
	void addToQueue(int clock) {
		
		//std::cout << "ndouble:  " << r.nextDouble() << "\n\n patients" << numOfPatients << std::endl;
		if (r.nextDouble() < numOfPatients) {
//---------fixme	
			num = rand() % 200;

			waitingRoomQueue.push(new Patient(clock, getFirstName(num), getSername(num),p.setIllnessLevel() )); 
		}
	}
	void setDischargeQueue(DischargeQueue*dischargeQueue) {

		this->dischargeQueue = dischargeQueue;
	}
	void setVector(std::vector<std::string> FlNallPatientVector) { // sets the first name vecor up 
		this->FNallPatientsVector = FlNallPatientVector;
	}
	void setSNVector(std::vector<std::string> SNallPatientVector) { // sets the last name vector up
		this->SNallPatientsVector = SNallPatientVector;
	}
	std::string getFirstName(int num) {
		return FNallPatientsVector[num];
	}
	std::string getSername(int num) {
		return SNallPatientsVector[num];
	}
	double getP() {
		return numOfPatients;
	}
	friend class TreatmentQueue;
};

#endif