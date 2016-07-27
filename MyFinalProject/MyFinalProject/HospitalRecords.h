#ifndef HOSPITALRECORDS_H_
#define HOSPITALRECORDS_H_

#include <vector>
#include <map>
#include <iostream>
#include "Patient.h"
struct HospitalRecords // use  maps for this 
{
	std::string name;
	int lvl;
	std::map<std::string, std::vector<int>> hospitalRecords;
	HospitalRecords() {}
	void addRecords(std::string name, std::vector<int> illnessPerVisit,int lvl) 
	{
		illnessPerVisit.push_back(lvl);
		this->name = name;
		hospitalRecords.insert(std::pair <std::string,std::vector<int>>(name,illnessPerVisit));
	}
	std::string getFName() {
		return name;
	}

};

#endif