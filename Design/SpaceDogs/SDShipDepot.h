#pragma once
#include "SDShip.h"
#include "SDShipChickenBone.h";
#include "SDShipCouch800.h";
#include "SDShipCowBone.h";
#include "SDShipDogHouse9K.h"
#include "SDShipKennel.h"
#include "SDShipSqueaker.h"
#include <map>
#include <typeinfo>

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Ship Depot class for Space Dogs game. Players can trade in
their current ship for a new ship here and repair the hull
of their current ship (restore hit points).

Private fields:
	-vector<SDShip> shipsForSale: List of ships for sale.
	-int repairPrice: Price this depot will repair ships for.
	
Functions:
Public:
	+void listShips(): Print list of ships and prices.
	+SDShip tradeShip(SDShip tradedShip, int purchasedShip):
	Adds tradedShip to shipsForSale and returns the ship
	at the index purchasedShip.
	+int getRepairPrice(): Returns repairPrice.
	+int shipPrice(int index): Returns price for ship at index.
	+int numShipsForSale(): Returns size of shipsForSale vector.
	
Private:
	-void addShips(): Generates random list of ships for constructor. */

// Returns map that stores names and values of all ships.
struct ships_map {
	const static map<string, int> createMap() {
		map<string, int> temp;
		temp["Squeaker"] = 0;
		temp["ChickenBone"] = 200;
		temp["Kennel"] = 200;
		temp["Cowbone"] = 350;
		temp["Couch 800"] = 500;
		temp["DogHouse 9K"] = 800;

		return temp;
	}
};

static map<string, int> shipPrices = ships_map::createMap(); // Map of prices for all ships.

namespace CSC234 {
	class SDShipDepot
	{
	public:
		SDShipDepot(); // Constructor.

		void listShips(); // Prints list of ships for sale and prices.
		SDShip tradeShip(SDShip tradedShip, int purchasedShip); // Swaps one ship for another.
		void getShipForSaleInfo(int requestedShip); // Prints information on a ship.
		int repairShip(SDShip& repairedShip, int treatsPaid); // Restores hull up to max.
		
		int getRepairPrice() { return repairPrice; }; // Returns repairPrice.
		int shipPrice(int index) { return shipsForSale[index].getShipValue(); }; // Returns price of a ship.
		int numShipsForSale() { return shipsForSale.size(); }; // Returns number of ships for sale.

	private:
		vector<SDShip> shipsForSale; // List of ships for sale.
		int repairPrice; // Price per point of hull repair.

		void addShips(); // Generates list of ships for constructor.
	};
}