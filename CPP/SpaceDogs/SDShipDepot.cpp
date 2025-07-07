#include "SDShipDepot.h"
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace CSC234 {
	/* Constructor.
	Precondition: Large trade system randomly generates depot or player uses
	special ability to add one to system.
	
	Postcondition: Depot is instantiated with list of ships and repair price.*/
	SDShipDepot::SDShipDepot() {
		addShips();

		srand(time(NULL));
		repairPrice = rand() % 10 + 1; // Repair price from 1 to 10 per hull point.
	}

	/* Prints list of ships for sale.
	Precondition: Player chooses to look at trade ships.
	Postcondition: List of ships is printed to output. */
	void SDShipDepot::listShips() {
		cout << "Ships Currently for Sale:" << endl;
		cout << "Name               Treats" << endl;
		int counter = 1;
		for (auto i = shipsForSale.begin(); i != shipsForSale.end(); i++) {
			printf("%i. %-25s%i\n", counter, i->getName().c_str(), i->getShipValue());
			counter++;
		}
	}

	/* Trades player's current ship for another.
	Precondition: Player has chosen a ship from the list of possible ships.
	Postcondition: If player's choice is legitimate, return new ship and add
	old ship to shipsForSale vector. Else return the traded ship.*/
	SDShip SDShipDepot::tradeShip(SDShip tradedShip, int purchasedShip) {
		if (purchasedShip < shipsForSale.size()) {
			shipsForSale.push_back(tradedShip);
			SDShip tempShip = shipsForSale[purchasedShip];
			shipsForSale.erase(shipsForSale.begin() + purchasedShip);
			return tempShip;
		}
		else
			return tradedShip;
	}

	/* Prints information on ships for sale.
	Precondition: Player requested information.
	Postcondition: Prints information on requested ship to output.*/
	void SDShipDepot::getShipForSaleInfo(int requestedShip) {
		cout << "Ship Information:" << endl;
		cout << "-----------------" << endl;
		if (requestedShip < shipsForSale.size())
			shipsForSale[requestedShip].printShipInfo();
		else
			cout << "Ship does not exist." << endl;
	}

	/* Restores hull points.
	Precondition: Player has chosen repair option at depot.
	param SDShip& repairedShip: passed by reference Ship object. Hull values
	will be restored.
	param int treatsPaid: Number of treats player has spent. Used for checking
	that player can afford repairs. 
	
	Postcondition: Hull points are restored any amount up to maxHull. Returns
	number of treats not spent, if any. */
	int SDShipDepot::repairShip(SDShip& repairedShip, int treatsPaid) {
		int hullAmount = treatsPaid / repairPrice; // Number of points possible with paid treats.
		int repaired = repairedShip.repairHull(hullAmount);
		return (hullAmount - repaired) * repairPrice; // Return unrepaired points * amount of treats per point.
	}

	/* Adds ships to list of ships for sale.
	Precondition: Constructor called.
	Postcondition: Random number of ships have been added to shipsForSale vector. */
	void SDShipDepot::addShips() {
		srand(time(NULL));
		int numShips = rand() % 5 + 1; // Up to 5 ships can be added.

		int shipChooser = 0;
		for (int i = 0; i < numShips; i++) {
			shipChooser = rand() % 5 + 1;

			// Switch for random ship.
			switch (shipChooser) {
			case 1: shipsForSale.push_back(SDShipChickenBone());
				break;
			case 2: shipsForSale.push_back(SDShipCouch800());
				break;
			case 3: shipsForSale.push_back(SDShipCowBone());
				break;
			case 4: shipsForSale.push_back(SDShipDogHouse9K());
				break;
			case 5: shipsForSale.push_back(SDShipKennel());
				break;
			default: shipsForSale.push_back(SDShipSqueaker());
				break;
			}
		}
	}
}
