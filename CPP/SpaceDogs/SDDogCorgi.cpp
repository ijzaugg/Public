#include "SDDogCorgi.h"
#include <iostream>

using namespace std;

namespace CSC234 {
	/* Constructor.
	Precondition: Player chooses Corgi class.
	Postcondition: Instantiates corgi object. Breed, traits, and special
	ability are overwritten from parent class. */
	SDDogCorgi::SDDogCorgi(string playerName, vector<SDTradeSystem*>& map) {
		// Set basic info and traits.
		name = playerName;
		breed = "Corgi";
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
	Preconditions: Player chooses special ability option in main program.
	Postconditions: If special ability ready, adds either a trade post or
	ship depot to current system, if allowed. */
	void SDDogCorgi::specialAbility() {
		char input;

		if (specialAbilityAvailable() && location->getSize() != "small") {
			cout << "The local Space Trade Masters love your winning smile and agree" << endl;
			cout << "to a new Space Business Venture!" << endl;
			cout << "What would you like to build?" << endl;

			if (location->getSize() == "medium" || location->getSize() == "large")
				cout << "|T|rade Post." << endl;

			if (location->getSize() == "large")
				cout << "|S|hip Depot." << endl;

			while (!(cin >> input)) {
				cout << "I'm sorry, I didn't catch that. Try again: " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}

			input = tolower(input);

			if (input == 't') // Trade post.
				if (location->getSize() != "small") // Trade posts can only be built in medium or large systems.
					location->addTradePost();
				else {
					cout << "This system is too small to support a trade post!" << endl;
					return;
				}
			else if (input == 's') // Ship depot.
				if (location->getSize() == "large") // Depots can only be built in large systems.
					location->addShipDepot();
				else {
					cout << "This system is too small to support a ship depot!" << endl;
					return;
				}

			specialAbilityReady = 5;
		}
		else {
			cout << "The local traders aren't impressed by your space charm...." << endl;
			if (location->getSize() == "small")
				cout << "This system is too small!" << endl;
			cout << "Special ability ready in " << specialAbilityReady << " space rounds." << endl;
		}
	}

	/* Sets traits for corgi class.
	Precondition: Called by constructor.
	Postcondition: Sets traits appropriate for corgi. */
	void SDDogCorgi::setTraits() {
		biteBonus = 0;
		barkBonus = 1;
		tradeBonus = 5;
	}

	/* Sets ability description and name.
	Precondition: Called by constructor.
	Postcondition: Sets description and name for "Happy Smile" ability. */
	void SDDogCorgi::setSpecialAbilityDescription() {
		specialAbilityName = "Happy Smile";
		specialAbilityDescription = "Your smile makes everyone think they're your friend.\n";
		specialAbilityDescription += "You convince the local merchants to build a new Ship Depot or\n";
		specialAbilityDescription += "Trade Post in the local system (Depots must be built in Large\n";
		specialAbilityDescription += "systems, and Trade Posts must be built in Medium or Large systems.";
	}
}