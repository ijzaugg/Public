#include "SDShipChickenBone.h"

namespace CSC234 {
	/* Constructor.
	Precondition: Ship created by ship depot.
	Postcondition: Instantiates ship with stats for ChickenBone. */
	SDShipChickenBone::SDShipChickenBone() {
		name = "ChickenBone";
		value = 200;
		barkStrength = 2;
		biteStrength = 3;
		hull = 15;
		maxHull = 15;
		cargoWeight = 0;
		maxCargoWeight = 150;
		description = "A bit harder shell but still lots of chewy goodness inside. Just be careful of the little sharp pieces.";
	}
}