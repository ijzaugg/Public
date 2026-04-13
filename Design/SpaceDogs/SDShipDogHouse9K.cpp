#include "SDShipDogHouse9K.h"

namespace CSC234 {
	/* Constructor.
	Precondition: Trade post creates ship.
	Postcondition: Ship object instantiated with stats for DogHouse 9K ship. */
	SDShipDogHouse9K::SDShipDogHouse9K() {
		name = "DogHouse 9K";
		value = 800;
		barkStrength = 5;
		biteStrength = 5;
		hull = 35;
		maxHull = 35;
		cargoWeight = 0;
		maxCargoWeight = 1000;
		description = "Now you're flying in style, Space Baron. In space.";
	}
}