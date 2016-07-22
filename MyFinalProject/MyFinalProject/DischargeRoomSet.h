#ifndef DISCHARGEROOMSET_H_
#define DISCHARGEROOMSET_H_
#include <queue>
#include "Patient.h"

using std::queue;

class DischargeRoomSet
{
private:
	int dischargeTime;
	queue<Patient*> doctorsQueue;
	queue<Patient*> nursesQueue;

public:

	DischargeRoomSet() {}

	void update(int clock) {
		if (!doctorsQueue.empty())
		{
			Patient*patient = doctorsQueue.front();
			if (patient->dischargeTime == -1)
			{
				patient->dischargeTime = clock;
				doctorsQueue.pop();
			}
		}
	}
	friend class TreatmentRoomSet;
};
#endif