#include "SDShipCowBone.h"
namespace CSC234 {
	/* Constructor.
	Precondition: Created by trade post.
	Postcondition: Ship object instantiated with stats for CowBone ship. */
	SDShipCowBone::SDShipCowBone() {
		name = "CowBone";
		value = 350;
		barkStrength = 3;
		biteStrength = 4;
		hull = 25;
		maxHull = 25;
		cargoWeight = 0;
		maxCargoWeight = 200;
		description = "Bigger than your head and a lot harder to chew.";
	}
}