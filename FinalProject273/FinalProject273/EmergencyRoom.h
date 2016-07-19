#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <queue>
#include <stdexcpt.h>
#include "ReadInt.h"
#include "WaitingRoomQueue.h"
#include "DischargeQueue.h"
#include "TreatmentQueue.h"

class EmergencyRoom {

private:
	int clock;
	int numOfDoctors;
	int numOfNurses;
	double numOfPatients;
	int timeOfSimulation;

	WaitingRoomQueue *waitingRoomQueue;
	TreatmentQueue *treatmentQueue;
	DischargeQueue *dischargeQueue;

	AllPatients * allPatients;
	//std::vector<std::string> FNallPatientsVector;

	//std::vector<std::string> FNallPatientVector;

public:
	EmergencyRoom() {
		clock = 0;
		timeOfSimulation = 10080;
		numOfDoctors = -1;
		numOfNurses = -1;
		numOfPatients = -1;
		waitingRoomQueue = new WaitingRoomQueue();
		dischargeQueue = new DischargeQueue();
		allPatients = new AllPatients();
		treatmentQueue = new TreatmentQueue();
	}


	int getNumOfDoctors() { return numOfDoctors; }
	int getNumOfnurses() { return numOfNurses; }
	int getnumOfPatients() { return numOfPatients; }
	void setNumOfDoctors(int numOfDoctors) { this->numOfDoctors = numOfDoctors; }
	void setNumOfNurses(int numOfNurses) { this->numOfNurses = numOfNurses; }
	void setNumOfPatients(int numOfPatients) { this->numOfPatients = numOfPatients; }
	
	void enterData() {
		allPatients->addPeopleToVector();

		std::cout << "Hello my name is Dr. Itor, Jan Itor. I am the chief of medicine of Sacred Heart. Please answer these questions below...\n\n";
		numOfDoctors = read_int("Enter Number of Doctors: ", 0, 100);
		numOfNurses = read_int("Enter Number of Nurses : ", 0, 100);
		numOfPatients = read_int("Enter Number of Patients arriving per hour: ", 0, 60);
		double numOfPatientsPerHour = numOfPatients / 60;
		waitingRoomQueue->setNumOfPatientsPerHour(numOfPatientsPerHour);
	//	std::cout<< "-------------------------------------------"<< waitingRoomQueue->getP() << "\n";
		//break;
		waitingRoomQueue->setDischargeQueue(dischargeQueue);
		waitingRoomQueue->setVector(allPatients->getVector());
		waitingRoomQueue->setSNVector(allPatients->getSNVector());
//		allPatients->setVector(allPatients->getVector());
		
	}
	void runSacredHeart() {
		for (clock = 0; clock < timeOfSimulation; clock++) {
			waitingRoomQueue->addToQueue(clock);
			dischargeQueue->removeFromQueue(clock);
		}
	}
	void listTreatedPatients() {

		for (int i = 0; i < 9; i++) {
		
		}
		std::cout << "listP";
	}
	void findPatientrecords() {
		std::cout << "findP";
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
		//get records by name 
	}
	void showStats() {
		std::cout << "Dr. Itor:  Thank you for helping us with the simulation everything went very well here are the results if you are interested...\n\n";
		std::cout << "Patients Treated: ";
		std::cout << "\n\nAverage Time With Patients: ";
		std::cout << "Please Select from the menu below...\n\n";
		statsMenu();
	}



};



#endif