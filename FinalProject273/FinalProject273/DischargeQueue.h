#ifndef DISCHARGEQUEUE_H_
#define DISCHARGEQUEUE_H_
#include <queue>
#include "Random.h"
#include "Patient.h"
#include "EmergencyRoom.h"
#include "AllPatients.h"

class DischargeQueue {

private:
	int clock;

public:
	DischargeQueue(){}
	void removeFromQueue(int clock) {

	}

	friend class Treatment;
};
#endif // !DISCHARGEQUEUE_H_
