#include "readint.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int read_int(const string &prompt, int low, int high)

{
	cin.exceptions(ios::failbit | ios::badbit);
	int range = 0;
		if (low >= high) {
		throw(invalid_argument( "Invalid range high is less than low or low is more than high.\n"));
		}

		

		

	
	
	while (true) {
		try {
			cout << prompt;
			cin >> range;
			
			if (range <= low || range >= high) {
				throw(range_error("The range number inputed is out of range\n"));
			}
			return range;
		}
		catch (range_error& e) {
			cout << e.what();
		}
		catch(ios_base::failure &ex){
			cout << "you put in a invlaid input\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}

		
	}
}