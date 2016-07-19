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
	int numOfPatients;
	Random r;
	AllPatients ap;
	Patient p;

public:
	WaitingRoomQueue(){}
	void setNumOfPatientsPerHour(int numOfPatients) {
		this->numOfPatients = numOfPatients;
	}
	void addToQueue(int clock) {
	
		int num = rand() % 2000 + 1;
		if (r.nextDouble() < numOfPatients) {
			waitingRoomQueue.push(new Patient(clock, ap.getFirstName(num), ap.getSername(num), p.setIllnessLevel())); // making a patient with 
		}
	}
	
	friend class DischargeQueue;
};

#endif