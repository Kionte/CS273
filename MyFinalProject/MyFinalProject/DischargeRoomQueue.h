#ifndef DISCHARGEROOMQUEUE_H_
#define DISCHARGEROOMQUEUE_H_
#include <queue>
#include "Patient.h"
#include "WaitingRoomQueue.h"

using std::queue;

class DischargeRoomQueue
{
private:
	int dischargeTime; // time the leave the queue
	double tt = 0; // total time in queue
	WaitingRoomQueue*waitingRoomQueue; // access to waiting room queue
	int visitTime; // time in the dcharge queue
	int patientsTreated; // num of patients treated increments by one every time a patient is treated
	queue<Patient*> doctorsQueue; // stores the patients before they are discharged 
	queue<Patient*> nursesQueue;

public:

	DischargeRoomQueue() {
		visitTime = 0;
		patientsTreated = 0;
	}
	int getVisitTime() { //-------------getters----------//
		return visitTime;
	}
	int getPatientsTreated() {
		return patientsTreated;
	}
	void setVisitTime(Patient* patient) { //-------------setters-----------//
		visitTime += (patient->dischargeTime - patient->arrivalTime);
	}
	void setPT() {
		patientsTreated++;
	}
	void update(int clock) {
		if (!doctorsQueue.empty()) // if the doctor is still treating patients 
		{
			Patient*patient = doctorsQueue.front();  // get the first patient in the queue
			//std::cout << patient->dischargeTime << "  ";
			patient->dischargeTime = clock; // set one 
			//std::cout << doctorsQueue.size();
			doctorsQueue.pop(); // send the patient on their way 
			setVisitTime(patient);
			setPT();
	
			delete patient;
			
		}
		if (!nursesQueue.empty()) // if the doctor is still treating patients 
		{
			Patient*patient = nursesQueue.front();  // get the first patient in the queue


			patient->dischargeTime = clock; // set one 
			nursesQueue.pop(); // send the patient on their way 

			setVisitTime(patient);
			setPT();

			delete patient;

		}
	}
	friend class TreatmentRoomQueue;
};
#endif
