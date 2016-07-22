#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <ios>
#include "WaitingRoomSet.h"
#include "TreatmentRoomSet.h"
#include "DischargeRoomSet.h"
#include "Random.h"

Random random;
using std::cout;
using std::cin;

class EmergencyRoom
{
private:
	int totalTime;
	int clock;

	WaitingRoomSet * waitingRoomSet;
	TreatmentRoomSet * treatmentRoomSet;
	DischargeRoomSet * dischargeRoomSet;

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
		waitingRoomSet = new WaitingRoomSet();
		treatmentRoomSet = new TreatmentRoomSet();
		dischargeRoomSet = new DischargeRoomSet();
	}

	void enterInfo() {
		int patPerHour = read_int("enter rate: ", 1, 59);
		double rate = patPerHour / 60;
		int numOfDoc = read_int("enter doc: ", 1, 59);
		int numOfNur = read_int("enter nur: ", 1, 59);

		waitingRoomSet->setRate(rate);
		waitingRoomSet->setNur(numOfNur);
		waitingRoomSet->setDoc(numOfDoc);
	}

	void runSacredHeart() {
		for (clock = 0; clock < 10800; clock++) {
			waitingRoomSet->update(clock);
			treatmentRoomSet->update(clock);
			dischargeRoomSet->update(clock);
		}
	}
	void showStats() {

	}
};

#endif