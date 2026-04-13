#include "SDShipCouch800.h"

namespace CSC234 {
	/* Constructor.
	Precondition: Ship created by trade depot.
	Postcondition: Object instantiated with stats for Couch 800 ship. */
	SDShipCouch800::SDShipCouch800() {
		name = "Couch 800";
		value = 500;
		barkStrength = 3;
		biteStrength = 2;
		hull = 25;
		maxHull = 25;
		cargoWeight = 0;
		maxCargoWeight = 700;
		description = "All the stuff you ever wanted, all in one conveniently squishy location.";
	}
}