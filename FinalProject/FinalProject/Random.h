#ifndef RANDOM_H_
#define RANDOM_H_

#include <ctime>
#include <cstdlib>
//-0-------------------------------------come bak to this ======================================//
class Random {
public:
	Random() {
		srand((unsigned int)std::time(0));
	}
	Random(int startTime) {
		srand(startTime);
	}

	double nextDouble() {
		return double(rand()) / RAND_MAX;
	}
	int nextInt(int n) {
		return int(nextDouble() * n);
	}
	int randomIllnessLevel() {
		int range = rand() % 10 + 1;
		int num = 0;

		if (range > 9) {
			num = rand() % 5 + 16;
			return num;
		}
		else if (range > 7) {
			num = rand() % 5 + 11;
			return num;
		}
		else 
			num = rand() % 10 + 1;
		return num;
	}
	
};
		

#endif