#ifndef HOSPITALRECORDS_H_
#define HOSPITALRECORDS_H_

#include <vector>
#include "Patient.h"
struct HospitalRecords // use multi maps for this 
{
	std::vector<Patient*>records;
	std::vector<int> illnessPerVisit;
	HospitalRecords() {}
	HospitalRecords(std::vector<Patient*>records,std::vector<int> illnessPerVisit)
	{
		this->records = records;
		this->illnessPerVisit = illnessPerVisit;
	}
	void addRecords(Patient* patient, int lvl) {
		records.push_back(patient);
		illnessPerVisit.push_back(lvl);
	}
};

#endif