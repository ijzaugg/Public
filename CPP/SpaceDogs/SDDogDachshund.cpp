#include "SDDogDachshund.h"
#include <iostream>

using namespace std;

namespace CSC234 {
	/* Constructor.
	Precondition: Dachshund class chosen by player.
	Postcondition: Object instantiated. Breed, traits, and special ability overwritten
	from parent class. */
	SDDogDachshund::SDDogDachshund(string playerName, vector<SDTradeSystem*>& map) {
		// Set basic info and traits.
		name = playerName;
		breed = "Dachshund";
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

	/* Uses special ability.
	Precondition: Player chooses special ability from main menu.
	Postcondition: If special ability available, adds random tradeGood
	to cargo hold. */
	void SDDogDachshund::specialAbility() {
		if (specialAbilityAvailable()) {
			int chooser = rand() % 9;
			int quantity = rand() % 30 + 5;
			SDTradeGood* newGood;
			if (chooser == 0)
				newGood = new SDTradeGood("Robo-Rope Tugs", quantity);
			else if (chooser == 1)
				newGood = new SDTradeGood("Artificial Turfs", quantity);
			else if (chooser == 2)
				newGood = new SDTradeGood("Galactic Plus Toys", quantity);
			else if (chooser == 3)
				newGood = new SDTradeGood("Squeaky Cyber-Toys", quantity);
			else if (chooser == 4)
				newGood = new SDTradeGood("Space Dog Beds", quantity);
			else if (chooser == 5)
				newGood = new SDTradeGood("Self-walker Leashes", quantity);
			else if (chooser == 6)
				newGood = new SDTradeGood("Smart-Balls", quantity);
			else if (chooser == 7)
				newGood = new SDTradeGood("Power Collars", quantity);
			else
				newGood = new SDTradeGood("Automated Sun Beams", quantity);

			cout << "You found Space Treasure!" << endl;
			newGood->toString();
			cout << endl;
			ship.addCargo(*newGood);

			specialAbilityReady = 5;
		}
		else {
			cout << "You dig and dig, but there's no Space Treasure here! Still totally worth it..." << endl;
			cout << "Special ability ready in " << specialAbilityReady << " space rounds." << endl;
		}
	}

	/* Sets traits for dachshund class.
	Precondition: Called by constructor.
	Postcondition: Traits set for Dachshund. */
	void SDDogDachshund::setTraits() {
		biteBonus = 2;
		barkBonus = 2;
		tradeBonus = 2;
	}

	/* Sets special ability descrption and name.
	Precondition: Called by constructor.
	Postcondition: Sets name and description for "Dig For Treasure" ability. */
	void SDDogDachshund::setSpecialAbilityDescription() {
		specialAbilityName = "Dig For Treasure";
		specialAbilityDescription = "Dig up some long-lost Space Cargo in the local system and\n";
		specialAbilityDescription += "add it to your cargo hold.\n";
	}
}