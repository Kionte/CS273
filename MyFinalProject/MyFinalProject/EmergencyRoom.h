#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include "WaitingRoomQueue.h"
#include "TreatmentRoomQueue.h"
#include "DischargeRoomQueue.h"
#include "Citizens.h"
#include "Random.h"
#include "CareGiver.h"
#include "HospitalRecords.h"

using std::cout;
using std::cin;

class EmergencyRoom : HospitalRecords
{
private:
	int totalTime;
	int clock;

	WaitingRoomQueue * waitingRoomQueue;
	TreatmentRoomQueue * treatmentRoomQueue;
	DischargeRoomQueue * dischargeRoomQueue;
	HospitalRecords * hospitalRecords;
	Citizens * citizens;

	int read_int(const std::string &prompt, int low, int high)
	{
		if (low >= high) // invalid range
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					if (num >= low && num <= high) { // within the specified range
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}
public:
	EmergencyRoom() {
		waitingRoomQueue = new WaitingRoomQueue();
		treatmentRoomQueue = new TreatmentRoomQueue();
		dischargeRoomQueue = new DischargeRoomQueue();
		citizens = new Citizens();
		hospitalRecords = new HospitalRecords();
	}

	void enterInfo() {
		this->citizens->addPeopleToVector();
		int patPerHour = read_int("enter rate: ", 1, 59);
		double rate = patPerHour / 60;
		int numOfDoc = read_int("enter doc: ", 1, 59);
		int numOfNur = read_int("enter nur: ", 1, 59);

		waitingRoomQueue->setRate(patPerHour);
		waitingRoomQueue->setNur(numOfNur);
		waitingRoomQueue->setDoc(numOfDoc);
		waitingRoomQueue->setFirstName(citizens->getVector());
		waitingRoomQueue->setSerName(citizens->getSNVector());
		treatmentRoomQueue->setDischargeRoomQueue(dischargeRoomQueue);
		treatmentRoomQueue->setWaitingRoomQueue(waitingRoomQueue);
		hospitalRecords->setHospitalRecords(hospitalRecords);
	}

	void runSacredHeart() {
		for (clock = 0; clock < 10080; clock++) {
			waitingRoomQueue->update(clock);
			treatmentRoomQueue->update(clock);
			dischargeRoomQueue->update(clock);
		}
	}
	void listTreatedPatients() {
		listPatients();
	}

	void findPatientrecords() {
	}
	void endOfProgram() {
		std::cout << "End Of Program...";
		exit(0);
	}
	void invalidOption() {
		std::cout << "invalidO";
	}

	void statsMenu() {
		int choice = 0;
		std::cout << "1,2,3\n";
		choice = read_int("Pick one of the above options: ", 1, 2);
		switch (choice)
		{
		case 1: listTreatedPatients();
			statsMenu();
			break;
		case 2: findPatientrecords();
			statsMenu();
		case 3: endOfProgram();
			break;
		default:  invalidOption();
			statsMenu();
			break;

		}
	}
	void showStats() {
		std::cout << "Dr. Itor:  Thank you for helping us with the simulation everything went very well here are the results if you are interested...\n\n";
		std::cout << "Patients Treated: " << dischargeRoomQueue->getPatientsTreated();//->getPatientsTreted();
		std::cout << "AVG visit time: " << dischargeRoomQueue->getVisitTime() / dischargeRoomQueue->getPatientsTreated();
		std::cout << "\n\nPlease Select from the menu below...\n\n";
		statsMenu();
	}
};

#endif