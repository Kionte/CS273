#ifndef DISCHARGEROOMQUEUE_H_
#define DISCHARGEROOMQUEUE_H_
#include <queue>
#include "Patient.h"
#include "WaitingRoomQueue.h"

using std::queue;

class DischargeRoomQueue
{
private:
	int dischargeTime;
	WaitingRoomQueue*waitingRoomQueue;
	int visitTime;
	int patientsTreated;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;

public:

	DischargeRoomQueue() {
		visitTime = 0;
		patientsTreated = 0;
	}
	int getVisitTime() {
		return visitTime;
	}
	int getPatientsTreated() {
		return patientsTreated;
	}
	void setVisitTime(Patient* patient) {
		visitTime += patient->dischargeTime - patient->arrivalTime;
	}
	void setPT() {
		patientsTreated++;
	}
	void update(int clock) {
		if (!doctorsQueue.empty()) // if the doctor is still treating patients 
		{
			Patient*patient = doctorsQueue.front();  // get the first patient in the queue

			patient->dischargeTime = clock; // set one 
			std::cout << doctorsQueue.size();
			doctorsQueue.pop(); // send the patient on their way 
			setVisitTime(patient);
			setPT();
			//delete patient;

		}
		if (!nursesQueue.empty()) // if the doctor is still treating patients 
		{
			Patient*patient = nursesQueue.front();  // get the first patient in the queue


			patient->dischargeTime = clock; // set one 
			nursesQueue.pop(); // send the patient on their way 

			setVisitTime(patient);
			setPT();

			//delete patient;

		}
	}
	friend class TreatmentRoomQueue;
};
#endif