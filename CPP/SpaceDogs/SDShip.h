#pragma once
#include "SDTradeGood.h"
#include <string>
#include <vector>

/* Author: Irene Zaugg
* Class: CSC234
* Instructor: Robert Gilanyi

Parent Ship class for SpaceDogs game in Wolf Casino.
Every Dog and Cat player type has a Ship with various
stats. Ships include a cargo hold and combat stats
(bite/bark).

Protected Fields:
	-vector<SDTradeGood> cargo: Cargo hold full of trade goods.
	-int biteStrength: Strength of bite attack.
	-int barkStrength: Strength of bark attack.
	-int hull: Current hull strength (hit points).
	-int maxHull: Maximum hull strength.
	-int maxCargoWeight: Maximum allowed cargo weight.
	-int cargoWeight: Current cargo weight.
	-int cargoValue: Value of all cargo in the hold.
	-string name: Name of ship.
	-int value: Value of ship in treats.
	-string description: Ship description.
	
Functions:
Public:
	+string getName(): Returns name.
	+string getDescription(): Returns description.
	+int getShipValue(): Returns ship value.
	+void printShipInfo(): Prints formatted information on ship.
	+void printCargo(): Prints formatted list of cargo.
	+void addCargo(SDTradeGood &newCargo): Adds new tradeGood to cargo vector.
	+SDTradeGood removeGood(int cargoIndex, int quantity): Removes tradeGood
	from cargo vector.
	+int getCargoWeight(): Returns current weight of cargo.
	+int getAvailableSpace(): Returns amount of unused weight.
	+int getCargoValue(): Returns total value of cargo.
	+int getCargoQuantity(int index): Returns quantity of a tradeGood in
	cargo vector.
	+int getNumGoods(): Returns total size of cargo vector.
	+int getHull(): Returns current hull.
	+int getMaxHull(): Returns maxHull value.
	+int bark(): Returns barkStrength for combat.
	+int bite(): Returns biteStrength for combat.
	+int takeDamage(int damage): Subtracts damage from hull.
	+int repairHull(int repaired): Adds repaired amount to hull up to maxHull value.
	+void transferCargo(SDShip& newShip): Transfers all cargo to new ship.
	
Protected:
	-void updateCargoValueAndWeight(): Updates cargoValue and cargoWeight
	based on cargo vector contents. */

namespace CSC234 {

	class SDShip
	{
	public:
		SDShip(); // Constructor.
		
		string getName() { return name; }; // Returns name of ship.
		string getDescription() { return description; }; // Returns description of ship.
		int getShipValue() { return value; }; // Returns value of ship.
		void printShipInfo(); // Prints formatted information for ship.
		
		// TRADE FUNCTIONS
		void printCargo(); // Prints current contents of cargo hold.

		void addCargo(SDTradeGood &newCargo); // Cargo purchased and added to cargo hold.
		SDTradeGood removeCargo(int cargoIndex, int quantity); // Cargo either sold or lost.

		int getCargoWeight(); // Returns total weight of cargo.
		int getAvailableSpace(); // Returns amount of space still available by weight.
		int getCargoValue(); // Returns total value of cargo.
		int getCargoQuantity(int index) { return cargo[index].getQuantity(); }; // Returns quantity of given cargo.
		int getNumGoods() { return cargo.size(); }; // Returns size of cargo vector.

		// COMBAT FUNCTIONS
		int getHull() { return hull; }; // Returns value of hull (hit points remaining).
		int getMaxHull() { return maxHull; }; // Returns value of max hull (maximum hp).
		int bark() { return barkStrength; }; // Returns value of barkStrength (used in attacks).
		int bite() { return biteStrength; }; // Returns value of biteStrength (used in attacks).
		int takeDamage(int damage); // Takes damage amount from hull and returns new hull strength.
		int repairHull(int repaired); // Repairs hull (adds points back to hull up to max). Returns repaired amount.
		void transferCargo(SDShip& newShip); // Transfers all cargo to a new ship.
		
	protected:
		vector<SDTradeGood> cargo; // Contains TradeGood objects - ship's cargo hold.
		int biteStrength, barkStrength; // Combat abilities.
		int hull, maxHull; // Hit points.
		int maxCargoWeight; // Statistics for cargo hold.
		int cargoWeight, cargoValue; // Current weight and value of cargo items.

		string name; // Name of ship.
		int value; // Value of ship.
		string description; // Description of ship.

		void updateCargoValueAndWeight(); // Calculates total value and weight of items in cargo hold.
	};
}

