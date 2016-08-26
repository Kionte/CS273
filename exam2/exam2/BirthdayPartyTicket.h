
#ifndef _BIRTHDAY_PARTY_TICKET_H_
#define _BIRTHDAY_PARTY_TICKET_H_

#include <list>
#include <string>
#include "Party.h"
#include "PartyTicket.h"

class BirthdayPartyTicket : public PartyTicket
{
private:

	Party * the_party; // points to "the party"
	std::list<std::string>::iterator me; // an iterator that points to the the person who this ticket belongs to 

public:

	void leave(); // virtual function 
	
	// 2 arg constructor every ticket will have the current party they are at and a itterator that points to themselve 
	BirthdayPartyTicket(Party * the_party, std::list<std::string>::iterator me) : the_party(the_party), me(me) {}

};

#endif