#include "SDPirate.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace CSC234 {
	/* Constructor.
	Precondition: Trading System has randomly generated a Pirate object.
	Postcondition: Pirate object is instantiated with random stats for
	attack and defense. */
	SDPirate::SDPirate() {
		srand(time(NULL));
		attack = rand() % 5 + 1; // Attack between 1 and 10.

		//srand(time(NULL));
		hull = rand() % 30 + 1; // Between 1 and 30 hp.

		//srand(time(NULL));
		barkResistance = rand() % 8; // Bark resistance between 0 and 8.

		generateRandomTradeGood(); // Add a randomized number and type of goods.
	}

	/* Attacks player as part of combat round.
	Precondition: Player initiates combat.
	
	Postcondition: Rolls attack based on attach strength and returns damage amount. */
	int SDPirate::attackPlayer() {
		double attackRoll = (rand() % 100) / 100.0; // Percentage roll.
		int negativeRoll = rand() % 1; // Generates either 0 or 1.
		if (negativeRoll == 0)
			attackRoll *= -1; // If 0, attackRoll is negative.
		return (attack + (attack * attackRoll)); // Attack value +/- percentage of attack.
	}

	/* Subtracts hit points.
	Precondition: Player has attacked Pirate
	param int incomingDamage: Amount of damage done by player.
	
	Postcondition: Subtracts damage from hull and returns new hull value.
	Negative and 0 values (pirate destruction) handled by external functions. */
	int SDPirate::takeDamage(int incomingDamage) {
		hull -= incomingDamage;
		return hull;
	}

	/* Tries to resist a player's Bark attack.
	Precondition: Player uses Bark() function to attack Pirate.
	param int barkStrength: Incoming Bark "damage."
	
	Postcondition: Returns true if Bark was resisted, else returns false. */
	bool SDPirate::resistBark(int barkStrength) {
		if (barkStrength < barkResistance)
			return true;
		else
			return false;
	}

	/* Loots the pirate's cargo.
	Precondition: Pirate has been destroyed or a special ability has been
	used to rob the cargo.
	
	Postconditoin: Returns the TradeGood pointer that was looted and removes
	its reference from the Pirate. */
	SDTradeGood* SDPirate::lootCargo() {
		SDTradeGood* lootedGoods = pirateGoods;
		pirateGoods = NULL;
		return lootedGoods;
	}

	/* Prints all relevant information on this pirate. Mostly for test purposes.
	Precondition: Call to function from program.
	Postcondition: Statistics have been printed to screen. */
	void SDPirate::printStats() {
		cout << "Pirate information:" << endl;
		cout << "-------------------" << endl;

		cout << "Attack: " << attack << endl;
		cout << "Hull: " << hull << endl;
		cout << "Bark resistance: " << barkResistance << endl;
		cout << "Carried cargo: ";
		if (pirateGoods == NULL)
			cout << endl;
		else
			pirateGoods->toString();
		cout << endl;
	}

	/* Generates a random good to be populated on this object.
	Precondition: Constructor has been called.

	Postcondition: One random trade good of a random quantity has been generated
	and assigned to the pirateGoods pointer. */
	void SDPirate::generateRandomTradeGood() {
		srand(time(NULL));
		int quantity = rand() % 50 + 1; // Pirate can be carrying from 1-50 goods.
		srand(time(NULL));
		int randomNumber = rand() % 9 + 1; // Generate a number 1-9.

		switch (randomNumber) {
		case 1:
			pirateGoods = new SDTradeGood("Robo-Rope Tugs", quantity);
			break;
		case 2:
			pirateGoods = new SDTradeGood("Artificial Turfs", quantity);
			break;
		case 3:
			pirateGoods = new SDTradeGood("Galactic Plush Toys", quantity);
			break;
		case 4:
			pirateGoods = new SDTradeGood("Squeaky Cyber-Toys", quantity);
			break;
		case 5:
			pirateGoods = new SDTradeGood("Space Dog Beds", quantity);
			break;
		case 6:
			pirateGoods = new SDTradeGood("Self-walker Leashes", quantity);
			break;
		case 7:
			pirateGoods = new SDTradeGood("Smart-Balls", quantity);
			break;
		case 8:
			pirateGoods = new SDTradeGood("Power Collars", quantity);
			break;
		case 9:
			pirateGoods = new SDTradeGood("Automated Sun Beams", quantity);
			break;
		default:
			pirateGoods = new SDTradeGood();
			break;
		}
	}
}