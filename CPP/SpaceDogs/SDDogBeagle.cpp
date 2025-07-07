#include "SDDogBeagle.h"
#include <iostream>

using namespace std;
namespace CSC234 {
	/* Constructor. Overwrites breed name from parent class.
	Preconditions: Player chooses Beagle class.
	Postconditions: New SDDogBeagle object instantiated. */
	SDDogBeagle::SDDogBeagle(string playerName, vector<SDTradeSystem*>& map) {
		// Set basic info and traits.
		name = playerName;
		breed = "Beagle";
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

	/* Uses beagle's special ability.
	Preconditions: Player chooses ability in trade system.
	Postconditions: If special ability ready, adds a pirate to the
	current system. */
	void SDDogBeagle::specialAbility() {
		if (specialAbilityAvailable()) {
			cout << "BaROOOO! A cat pirate scurries out of hiding!" << endl;
			location->addPirate();

			specialAbilityReady = 5;
		}
		else {
			cout << "BaROooOooo... Well, that didn't go as planned..." << endl;
			cout << "Special ability ready in " << specialAbilityReady << " space rounds." << endl;
		}
	}

	/* Sets beagle's traits.
	Preconditions: Called by constructor.
	Postconditions: Sets traits appropriate for class. */
	void SDDogBeagle::setTraits() {
		biteBonus = 1;
		barkBonus = 5;
		tradeBonus = 0;
	}

	/* Sets description for special ability.
	Precondition: Called by constructor.
	Postcondition: Sets specialAbilityName and specialAbilityDescription for beagle special
	ability, "BaROOO!" */
	void SDDogBeagle::setSpecialAbilityDescription() {
		specialAbilityName = "BaROOOO!";
		specialAbilityDescription = "Scare the local cats out of hiding. One cat pirate will launch\n";
		specialAbilityDescription += "its ship in a panic (adds one cat pirate to the local system.";
	}
}