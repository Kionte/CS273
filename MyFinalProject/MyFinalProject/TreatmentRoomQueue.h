#ifndef TREATMENTROOMSET_H_
#define TREATMENTROOMSET_H_

#include "Patient.h"
#include "WaitingRoomQueue.h"
#include "DischargeRoomQueue.h"
#include "Random.h"
#include "CareGiver.h"
#include <queue>
#include <iostream>

using std::queue;
class TreatmentRoomQueue {

private:
	int begTreatmentTime;
	int totalTreatmentTime;
	WaitingRoomQueue*waitingRoomQueue;
	DischargeRoomQueue*dischargeRoomQueue;
	CareGiver*careGiver;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;
public:
	TreatmentRoomQueue() {}


	void setWaitingRoomQueue(WaitingRoomQueue*waitingRoomQueue) {
		this->waitingRoomQueue = waitingRoomQueue;
	}
	void setDischargeRoomQueue(DischargeRoomQueue*dischargeRoomQueue) {
		this->dischargeRoomQueue = dischargeRoomQueue;
	}

	void update(int clock) {
		updateDoc(clock);
		updateNur(clock);
	}
	void updateDoc(int clock)
	{
		if (!doctorsQueue.empty()) // if the doctor is treating a patient(s)
		{
			Patient*patient = doctorsQueue.front(); // et the first patient 

			if ((clock - patient->startTreatmentTime) > patient->totalTreatmentTime)
			{
				doctorsQueue.pop();
				waitingRoomQueue->numOfDoc++;
				patient->dischargeTime = clock - patient->startTreatmentTime;

				dischargeRoomQueue->doctorsQueue.push(patient);
			}
		}

		if (waitingRoomQueue->numOfDoc > 0)
		{
			while (waitingRoomQueue->numOfDoc > 0 && (!waitingRoomQueue->doctorsQueue.empty()))
			{

				Patient*patient = waitingRoomQueue->doctorsQueue.front();
				waitingRoomQueue->doctorsQueue.pop();
				waitingRoomQueue->numOfDoc--;
				patient->startTreatmentTime = clock;
				doctorsQueue.push(patient);
			}
		}
	}
	void updateNur(int clock)
	{
		if (!nursesQueue.empty())
		{
			Patient*patient = nursesQueue.front();

			if ((clock - patient->startTreatmentTime) > patient->totalTreatmentTime)
			{
				nursesQueue.pop();
				waitingRoomQueue->numOfNur++;
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeRoomQueue->nursesQueue.push(patient);
			}
		}
		if (nursesQueue.empty())
		{
			if (!waitingRoomQueue->nursesQueue.empty())
			{
				Patient*patient = waitingRoomQueue->nursesQueue.front();
				waitingRoomQueue->nursesQueue.pop();
				waitingRoomQueue->numOfNur--;
				patient->startTreatmentTime = clock;
				nursesQueue.push(patient);
			}
		}
	}
	void setDQ(queue<Patient*>doctorsQueue) {
		this->doctorsQueue = doctorsQueue;
	}
	void setNQ(queue<Patient*>nursesQueue) {
		this->nursesQueue = nursesQueue;
	}
};
#endif
