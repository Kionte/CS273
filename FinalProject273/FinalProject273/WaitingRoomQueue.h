#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "Random.h"
#include "Patient.h"
#include "EmergencyRoom.h"
#include "AllPatients.h"
#include "DischargeQueue.h"
class WaitingRoomQueue {

private:
	std::priority_queue<Patient*> waitingRoomQueue;
	DischargeQueue *dischargeQueue;
	std::vector<std::string> FNallPatientsVector;
	std::vector<std::string> SNallPatientsVector;

	double numOfPatients;
	Random r;
	AllPatients ap;
	Patient p;

public:
	WaitingRoomQueue() { }
	void setNumOfPatientsPerHour(double numOfPatients) {
		this->numOfPatients = numOfPatients;
	}
	void addToQueue(int clock) {

		//std::cout << "ndouble:  " << r.nextDouble() << "\n\n patients" << numOfPatients << std::endl;
		if (r.nextDouble() < numOfPatients) {
			//Patient pl;
			int num = rand() % 200 +1;

			waitingRoomQueue.push(new Patient(clock, getFirstName(num), getSername(num),p.setIllnessLevel() )); // making a patient with 
			//std::cout << waitingRoomQueue.top();
		//	std::cout << FNallPatientsVector[num] << "\n";
		}
		std::cout << waitingRoomQueue.size() << "\n";
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
	friend class DischargeQueue;
};

#endif