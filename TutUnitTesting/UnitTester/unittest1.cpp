#include "stdafx.h"

#include "CppUnitTest.h"

#include "Triangle.h" // This must GO AFTER CppUnitTest.h!!!!
#include "../TutUnitTesting/Triangle.h"
#include <Square.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester

{

	TEST_CLASS(TriangleTest) // This our test suite for testing isTriangle()

	{

	public:

		TEST_METHOD(AllDifferent) // Test case 1: all sides different

		{

			// We are checking that isTriangle() should return true

			Assert::AreEqual(isTriangle(3, 4, 5), true);

		}

		TEST_METHOD(TooLong) // Test case 2: one side is too long

		{

			// We are checking that isTriangle() should return false

			Assert::AreEqual(isTriangle(3, 3, 7), false);

		}

		TEST_METHOD(Zeros) // Test case 3: all sides zero

		{

			// We are checking that isTriangle() should return false

			Assert::AreEqual(isTriangle(0, 0, 0), false);

		}

		TEST_METHOD(Negatives) // Test case 4: all sides negative

		{

			// We are checking that isTriangle() should return false

			Assert::AreEqual(isTriangle(-1, -1, -1), false);

		}

	};
	TEST_CLASS(SquareTest) // Test suite for testing isSquare()

	{

		TEST_METHOD(SquareZeros) // Test case 1: all sides are zero

		{

			Assert::AreEqual(isSquare(0, 0, 0, 0), false);

		}
		TEST_METHOD(SquarenEqual)
		{
			Assert::AreEqual(isSquare(1, 2, 3, 4), false);
		}
		TEST_METHOD(SquareNegative)
		{
			Assert::AreEqual(isSquare(1, 1, 1, -1), false);
		}
		TEST_METHOD(SquareisEqual)
		{
			Assert::AreEqual(isSquare(2, 2, 2, 2), true);
		}
		TEST_METHOD(SquareAllNeg)
		{
			Assert::AreEqual(isSquare(-1, -1, -1, -1), false);
		}

		// Add your additional test cases here!

	};

}