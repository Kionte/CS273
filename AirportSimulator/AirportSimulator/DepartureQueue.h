#ifndef DEPARTURE_Q_H_
#define DEPARTURE_Q_H_

#include <queue>
#include "Plane.h"

class DepartureQueue
{
private:
	std::queue<Plane *> the_queue;  // the queue of planes in the departure queue
	int departure_time;  // the time a plane has to wait when it reaches the front of the queue before it can take-off
	int total_wait;   // total accumulated wait time in the departure queue
	int num_served;   // number of planes served through the departure queue
public:
	DepartureQueue() : total_wait(0), num_served(0) {}

	void set_departure_time(int departure_time) {
		this->departure_time = departure_time;
	}

	int get_num_served() {
		return num_served;
	}

	int get_total_wait() {
		return total_wait;
	}

	void update(int clock)
	{
		// are there planes waiting in the departure queue?
		if (!the_queue.empty()) { // if the departure queue is not empty meaning if there is no planes ready to depart 
			Plane *plane = the_queue.front(); // create a pointer that will point to the object in the front of the queue 
			if (plane->ready_takeoff_time == -1) { // new plane has arrived at the front
												   // update the ready_takeoff_time attribute of the plane
				plane->ready_takeoff_time = clock;
			}
			else {
				// compute the time the plane has been waiting at the front
				if (clock - plane->ready_takeoff_time > departure_time) { // once the plane has met the requirment of how long 
					//it needs to be in the departure queue it will take off you determine that by doing 
					//the current time - the time the plane arrived in the departure queue. that value is current departure time.
					//once current departure time is no longer less than the set departure time the plane can take off 

					// plane has waited long enough
					// FIXME: remove plane from departure queue
					the_queue.pop();

					// FIXME: calculate the wait time
					int waitTime = 0; // temp var to store the amount of timne the plane was waiting in the departure queue 
					waitTime = clock - plane->ready_takeoff_time; // set the wait time to the difference between the current time and the time when the pane arrived in departure queue the dffeernce will be how long the plane was waitng 


					// FIXME: update total_wait and num_served
					total_wait += waitTime; // added this planes wait time to the total wait time 
					num_served++; // incremnt num served by one becasue we served one more plane 


					// take off!   goodbye plane
					delete plane;
				}
			}
		}

	}

	friend class ServiceQueue;

};

#endif
