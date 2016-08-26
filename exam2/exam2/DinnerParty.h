#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

/**
* DinnerParty is derived from Party
*/
class DinnerParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

	/**
	* Constructor for creating a DinnerParty
	*/
	DinnerParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		/**
		* FIXME 1a:
		*   Pseudo-code
		*    1. add name to the front of room
		*    2. get iterator to the front of the room (this points to the recently added party goer)
		*    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*            Pass to the constructor "this" party, and the iterator from step 2
		*    4. return this new party ticket 
		*/
		room.push_front(name); // add person to the front of the room 
		std::list<std::string>::iterator it = room.begin(); // create a itterator that will be able to point to everyone in the room 
		PartyTicket *  dinnerPartyTicket = new DinnerPartyTicket(this, it); // create a ticket to identify the perosn with 
		return dinnerPartyTicket; // return said ticket 
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		// FIXME 1b: iterate through all the persons here.
		std::list<std::string>::iterator it = room.begin(); // create a iterator that will go through the whole room 
		for (it; it != room.end();it++) // while the iterator is not at the end of the room then out put every person the iterator points at
		{
			std::cout << *it << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1c: someone's getting out of hand. Let's ask them to leave.
		room.erase(it);
	}
	friend class PartyFactory;
};
#endif