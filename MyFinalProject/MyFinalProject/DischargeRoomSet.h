#ifndef DISCHARGEROOMSET_H_
#define DISCHARGEROOMSET_H_
#include <queue>
#include "Patient.h"
#include "WaitingRoomSet.h"

using std::queue;

class DischargeRoomSet
{
private:
	int dischargeTime;
	WaitingRoomSet*waitingRoomSet;
	int visitTime;
	int patientsTreated;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;

public:

	DischargeRoomSet() {
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
		visitTime += patient->dischargeTime;
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
				std::cout << "pl";
				setVisitTime(patient);
				setPT();
				//delete patient;
			
		}
		if (!nursesQueue.empty()) // if the doctor is still treating patients 
		{
			Patient*patient = nursesQueue.front();  // get the first patient in the queue

			
				patient->dischargeTime = clock; // set one 
				nursesQueue.pop(); // send the patient on their way 
				std::cout << "pl\n";
				setVisitTime(patient);
				setPT();

				//delete patient;
			
		}
	}
	friend class TreatmentRoomSet;
};
#endif