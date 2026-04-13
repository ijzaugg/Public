#include "SDDogChihuahua.h"
#include <iostream>

using namespace std;

namespace CSC234 {
	/* Constructor.
	Precondition: Player chooses chihuahua class.
	Postcondition: SDDogChihuahua instantiated. Overwrites breed and traits from parent class. */
	SDDogChihuahua::SDDogChihuahua(string playerName, vector<SDTradeSystem*>& map) {
		// Set basic info and traits.
		name = playerName;
		breed = "Chihuahua";
		setTraits();
		setSpecialAbilityDescription();
		specialAbilityReady = 0;

		// Setup score items (ship and treats).
		ship = SDShipSqueaker();
		treats = 500;

		// Setup map info.
		gameMap = map;
		srand(time(NULL));
		int locationChooser = rand() % map.size();
		HOME_SYSTEM = map[locationChooser];
		location = HOME_SYSTEM;
	}

	/* Runs special ability.
	Precondition: Special ability chosen from main menu.
	Postcondition: If special ability is ready, "Mighty Chomp" destroys all pirates,
	trade posts, and ship depotsin player's current location. */
	void SDDogChihuahua::specialAbility() {
		if (specialAbilityAvailable()) {
			cout << "With a mighty chomp, you show the whole trade system who's boss!" << endl;
			if (location->getNumPirates() > 0)
				for (int i = 0; i < location->getNumPirates(); i++)
					ship.addCargo(*location->destroyPirate(0));

			if (location->tradePostPresent())
				location->removeTradePost();

			if (location->shipDepotPresent())
				location->removeShipDepot();

			specialAbilityReady = 5;
		}
		else {
			cout << "You nip at the air. Nothing happens." << endl;
			cout << "Special ability ready in " << specialAbilityReady << " space rounds." << endl;
		}
	}

	/* Sets traits for chihuahua class.
	Precondition: Called by constructor.
	Postcondition: Traits set for class. */
	void SDDogChihuahua::setTraits(){
		biteBonus = 5;
		barkBonus = 1;
		tradeBonus = 0;
	}

	/* Sets special ability description for Chihuahua.
	Precondition: Called by constructor.
	Postcondition: Special ability description and name set for "Mighty Bite" ability. */
	void SDDogChihuahua::setSpecialAbilityDescription() {
		specialAbilityName = "Mighty Bite";
		specialAbilityDescription = "Though you be small, you be but fierce. You're in charge and you know it.\n";
		specialAbilityDescription += "Your bite can destroy all pirates, trade posts, and ship depots in a\n";
		specialAbilityDescription += "system.";
	}
}