
#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!

// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;
	
public:
	PartyTicket * add(std::string name) 
	{
		room.push_front(name); // add person to front of list
		std::list<std::string>::iterator it = room.begin(); // create a iterator that can access all points in the list 
		PartyTicket * birthdayPartyTicket = new BirthdayPartyTicket(this, it); // create a ticket that way the person can be identified with the kind of party they are attending
		return birthdayPartyTicket; // return the ticket 
	}

	void list()
	{
		std::list<std::string>::iterator it = room.begin(); // create iterator that will go through the whole room 
		for (it; it != room.end(); it++) // until it reaches the end of the room keep on outputting the name of whoever the it is pointing to 
		{
			std::cout << *it << std::endl;
		}
	}
	
	void remove(std::list<std::string>::iterator it) // remove the perosn from the party forever 
	{
		room.erase(it);
	}

	BirthdayParty() {} // no arg constructor for this class 
};

#endif