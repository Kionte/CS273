#ifndef HOSPITALRECORDS_H_
#define HOSPITALRECORDS_H_

#include <vector>
#include <map>
#include "Patient.h"
#include <string>

struct HospitalRecords // use multi maps for this //
{
	std::map<std::string,std::vector<int>illnessLevelPerVisit> records
	//std::vector<Patient*>records;
	//std::vector<int> illnessPerVisit;
	HospitalRecords() {}
	//HospitalRecords(std::vector<Patient*>records,std::vector<int> illnessPerVisit)
	//{
//		this->records = records;
//		this->illnessPerVisit = illnessPerVisit;
	//}
	void addRecords(Patient* patient, int lvl) {
		records.push_back(patient);
		illnessPerVisit.push_back(lvl);
	}
};

#endif
