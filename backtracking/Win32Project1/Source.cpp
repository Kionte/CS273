/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {
	// FIXME: Implement recursive binary search
	
	if (first > last) // makes sure that the vector is in numerical order 
		return -1;
	else {
		int middle = (first + last) / 2; // find the mdddle of the icrrent list 

		if (target == items[middle]) {
			return middle;
		}
		if (target < items[middle]) { // if the target value is less then the middle value 
			return binary_search(items, first, middle - 1, target); // pass through the vecctor the begginging point and because target is less that middle we need to lok at th e bottom half and we need to do first start at the beggingin of the vectro and the middle - 1 to make sure we stay in the first half
		}
		else {
			return binary_search(items, middle + 1, last, target);
		}

	}
	return -1;
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size() - 1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	int r;
	for (int j = 0; j < 100; j += 10) {

		for (int i = 0; i < 10; ++i) { // initialize the vector with random values
			r = rand() % 100 + 1;
			haystack.push_back(r);
			std::cout << haystack.at(i + j) << "	";
		}
		std::cout << std::endl;
	}

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		}
		else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}