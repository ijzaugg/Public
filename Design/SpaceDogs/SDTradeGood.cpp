#include "SDTradeGood.h"
#include <iostream>
#include <string>

using namespace std;

namespace CSC234 {
	/* Constructor for goods owned by cat pirates.
	Precondition: TradeGood is called by TradeSystem or PirateCat object.
	param string name: Name of good.
	param int quantity: Number of goods.
	
	Postcondition: TradeGood is instantiated. Values for name, quantity, price, weight, and total price
	and weight have all been set appropriately for the type of good. Note that pirated goods do
	not have a random price and are automatically set to be 5 higher than the average price. */
	SDTradeGood::SDTradeGood(string name = "", int quantity = 100) {
		this->name = name;
		this->quantity = quantity;
		setValue();
		setWeight();
		totalValue = value * quantity;
		totalWeight = weight * quantity;
	}

	/* Prints out a formatted version of the values for the good. */
	void SDTradeGood::toString() {
		cout << name << ":" << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Weight: " << weight << " lbs." << endl;
		cout << "Value: " << value << " Treats per good" << endl;
		cout << totalWeight << " lbs., " << totalValue << " Treats." << endl;
	}

	/* Adds some number of goods to this object. Use negative numbers to remove goods.
	Precondition: Goods have been bought, claimed, sold, or pirated.
	param int numRemovedGoods: number of goods to be added (subtracted if number is negative).
	
	Postcondition: quantity of goods has been adjusted. */
	void SDTradeGood::addOrRemoveGoods(int numGoods) {
		quantity = quantity + numGoods;
		totalValue = value * quantity;
		totalWeight = weight * quantity;
	}

	/* Sets value. Uses enum values for switch statement.
	Precondition: TradeGood is instantiated for a CatPirate or TradingSystem object.

	Postcondition: value is set appropriately for good. */
	void SDTradeGood::setValue() {
		switch (nameHash()) {
		case ropes:
			value = 10;
			break;
		case turfs:
			value = 25;
			break;
		case plushes:
			value = 35;
			break;
		case squeaks:
			value = 40;
			break;
		case beds:
			value = 50;
			break;
		case leashes:
			value = 60;
			break;
		case balls:
			value = 75;
			break;
		case collars:
			value = 80;
			break;
		case sun:
			value = 100;
			break;
		}
	}

	/* Sets weight. Same for captured or traded goods. Uses enum for switch statement.
	Precondition: New TradeGood is instantiated.
	Postcondition: weight is assigned a value according to name of good.*/
	void SDTradeGood::setWeight() {
		switch (nameHash()) {
		case ropes:
			weight = 5;
			break;
		case turfs:
			weight = 10;
			break;
		case plushes:
			weight = 10;
			break;
		case squeaks:
			weight = 5;
			break;
		case beds:
			weight = 15;
			break;
		case leashes:
			weight = 5;
			break;
		case balls:
			weight = 5;
			break;
		case collars:
			weight = 15;
			break;
		case sun:
			weight = 20;
			break;
		default:
			weight = 5;
			break;
		}
	}

	/* Hashes name into an enum tag for use with other functions.
	Precondition: name is a string of some value.
	Postcondition: enum good_type value is returned. enums can be used for switch statements. */
	good_type SDTradeGood::nameHash() {
		if (name == "Robo-Rope Tug")
			return ropes;
		if (name == "Artificial Turf")
			return turfs;
		if (name == "Galactic Plush Toys")
			return plushes;
		if (name == "Squeaky Cyber-Toys")
			return squeaks;
		if (name == "Space Dog Beds")
			return beds;
		if (name == "Self-Walker Leashes")
			return leashes;
		if (name == "Smart-Balls")
			return balls;
		if (name == "Power Collars")
			return collars;
		return sun;
	}
}