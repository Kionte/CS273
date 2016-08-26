#include "BirthdayPartyTicket.h"
#include "BirthdayParty.h"

/**
* Implements the leave method
*/
void BirthdayPartyTicket::leave() {
	// FIXME 4: Implement leave for birthday parties
	BirthdayParty * thisParty = dynamic_cast<BirthdayParty *>(the_party); // down cast this party to the correct kind of party 
	thisParty->remove(me); // go to this party and find 'me' once found remove 'me' from the party
}