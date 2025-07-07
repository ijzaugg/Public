#include "SDShipKennel.h"

namespace CSC234 {
	/* Constructor.
	Precondition: Ship created by trade depot.
	Postcondition: Ship object instantiated with stats for Kennel ship. */
	SDShipKennel::SDShipKennel() {
		name = "Kennel";
		value = 200;
		barkStrength = 2;
		biteStrength = 1;
		hull = 20;
		maxHull = 20;
		cargoWeight = 0;
		maxCargoWeight = 300;
		description = "Great for stuffing all your secret goodies in. Some protection against the cats.";
	}
}