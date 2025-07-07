#include "SDShipSqueaker.h"

namespace CSC234 {
	/* Constructor.
	Precondition: Default ship for all players, or created by trade depot.
	Postcondition: Ship object instantiated with stats for Squaker ship.*/
	SDShipSqueaker::SDShipSqueaker() {
		name = "Squeaker";
		value = 0;
		barkStrength = 1;
		biteStrength = 1;
		hull = 10;
		maxHull = 10;
		cargoWeight = 0;
		maxCargoWeight = 100;
		description = "Basic ship. Does almost nothing useful, but it's fine for an afternoon chew.";
	}
}