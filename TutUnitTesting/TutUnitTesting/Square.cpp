#include "Square.h"

bool isSquare(int a, int b, int c, int d) {

	// A correct function would return true if a, b, c, d are valid sides for a square
//	if (a == 0 && b == 0 && c == 0 && d == 0)
	//	return false;
	if(a == b && a == c && a == d && a > 0) 
		return true;

	return false;

}