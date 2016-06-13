#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace Exam1 // NAMESPACE
{
	// STEP 1: Complete the implementation of the Footwear base class 
	// as described in the UML diagram

	//------------------------------------------FootWear------------------------------------//
	class FootWear
	{
	private:
		int size;
	public:
		FootWear(int size) {
			// Complete the implementation
			this->size = size; // sets the size to whatever is put in the constructor 
		}
		int getSize() { // gets size of object 
			return size;
		}
		virtual void Description() = 0;
	};

	//------------------------------------------Wheel------------------------------------//
	class Wheel
	{
	private:
		string color;
	public:
		Wheel() {}
		void set_color(string color) {
			this->color = color;
		}
	};

	// STEP 2:  Define the Sandle and RollerSkate classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.

	//------------------------------------------Sandle------------------------------------//
	class Sandle : public FootWear {

	public:
		Sandle(int size) : FootWear(size) {} //uses the footwear constructor to create a object of type sandle 
		void Description() {cout << "I am a sandle of size " << getSize() << endl; } // descibes object 
	};
	//------------------------------------------RollerSkate------------------------------------//
	class RollerSkate : public FootWear, public Wheel {
	private:
		Wheel wheel; // shows the HAS - A relationship 
	public:
		RollerSkate(int size, string color) : FootWear(size) {wheel.set_color(color);} // uses footwear constructor plus set_color to create a rollerskate object
		void Description() { cout << "I am a RollerSkate of size "  << getSize() << endl; } // describes obbject
	};
}

int main()
{
	Exam1::FootWear * ShoeCloset[2];

	// STEP 3: Assign ONE RollerSkate AND ONE Sandle object to each of the two elements 
	// in the ShoeCloset array.  Remember the classes are defined in the namespace Exam1.
	//ShoeCloset[0] = ??? 
	//ShoeCloset[1] = ???
	Exam1::FootWear * sandle = new Exam1::Sandle(10); // creates a sandle that is able to be in Shoe CLoset
	Exam1::FootWear * rollerSkate = new Exam1::RollerSkate(8, "blue"); // creates a rollerskate for shoe closet
	ShoeCloset[0] = sandle; // assigns object to array location 
	ShoeCloset[1] = rollerSkate; // assigns object to array locaion 
	for (int i = 0; i < 2; ++i)
	{
		// The method Description() should display an output like 
		// “I am a sandle (or rollerSkate) and my size is X”,
		// where X is the shoe size of the Sandle or RollerSkate objects you constructed above.
		ShoeCloset[i]->Description();

	}
}
