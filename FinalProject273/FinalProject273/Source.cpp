#include "EmergencyRoom.h"
#include "AllPatients.h"
EmergencyRoom sacredHeart;
int main() {
	AllPatients allPatients;
	allPatients.addPeopleToVector();
	sacredHeart.enterData();
	sacredHeart.runSacredHeart();
	sacredHeart.showStats();
}