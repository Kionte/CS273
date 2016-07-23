#ifndef TREATMENTROOMSET_H_
#define TREATMENTROOMSET_H_

#include "Patient.h"
#include "WaitingRoomSet.h"
#include "DischargeRoomSet.h"
#include "Random.h"
#include "CareGiver.h"
#include <queue>

using std::queue;
class TreatmentRoomSet {

private:
	int begTreatmentTime;
	int totalTreatmentTime;
	WaitingRoomSet*waitingRoomSet;
	DischargeRoomSet*dischargeRoomSet;
	CareGiver*careGiver;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;
public:
	TreatmentRoomSet() {}


	void setWaitingRoomSet(WaitingRoomSet*waitingRoomSet) {
		this->waitingRoomSet = waitingRoomSet;
	}
	void setDischargeRoomSet(DischargeRoomSet*dischargeRoomSet) {
		this->dischargeRoomSet = dischargeRoomSet;
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
				waitingRoomSet->numOfDoc++;
				patient->dischargeTime = clock - patient->startTreatmentTime;
				
				dischargeRoomSet->doctorsQueue.push(patient);
			}
		}

		if (doctorsQueue.empty() || waitingRoomSet->numOfDoc > 0)
		{
			while (waitingRoomSet->numOfDoc > 0 && (!waitingRoomSet->doctorsQueue.empty()))
			{

				Patient*patient = waitingRoomSet->doctorsQueue.front();
				waitingRoomSet->doctorsQueue.pop();
				waitingRoomSet->numOfDoc--;
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
				waitingRoomSet->numOfNur++;
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeRoomSet->nursesQueue.push(patient);
			}
		}
		if (nursesQueue.empty())
		{
			if (!waitingRoomSet->nursesQueue.empty())
			{
				Patient*patient = waitingRoomSet->nursesQueue.front();
				waitingRoomSet->nursesQueue.pop();
				waitingRoomSet->numOfNur--;
				patient->startTreatmentTime = clock;
				double num = rand() % 10 + 1;
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
