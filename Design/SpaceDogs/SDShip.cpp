#include "SDShip.h"
#include <iostream>

using namespace std;

namespace CSC234 {
	/* Constructor.
	Precondition: SDShip constructor is called in another class. This is the
	default ship; parent class should not be used in this program.
	
	Postcondition: New ship object is instantiated of type determined by name. */
	SDShip::SDShip() {
		name = "";
		value = 0;
		barkStrength = 1;
		biteStrength = 1;
		hull = 10;
		maxHull = 10;
		cargoWeight = 0;
		maxCargoWeight = 100;
		description = "Default ship.";
	}

	/* Prints information on ship.
	Precondition: Information on this ship is requested.
	Postcondition: Prints foratted information on ship name, description, value,
	hull, bark strength, bite strength, and cargo value and weight to output. */
	void SDShip::printShipInfo() {
		updateCargoValueAndWeight();
		cout << name << endl;
		cout << "--------------------" << endl;
		cout << description << endl;
		cout << "Value: " << value << endl;
		cout << "Hull: " << hull << "/" << maxHull << endl;
		cout << "Bark: " << barkStrength << endl;
		cout << "Bite: " << biteStrength << endl;
		cout << "Cargo value: " << getCargoValue() << endl;
		cout << "Cargo Weight: " << cargoWeight << "/" << maxCargoWeight << endl;
	}

	/* Prints contents of cargo.
	Precondition: Request made for information on cargo hold.
	Postcondition: all SDTradeGoods contained in cargo have been printed to output. */
	void SDShip::printCargo() {
		int counter = 1;
		cout << "Current Cargo Hold:" << endl;
		cout << "-------------------" << endl;
		if (cargo.size() > 0) {
			for (auto i = cargo.begin(); i != cargo.end(); i++) {
				cout << counter << ". ";
				(*i).toString();
				cout << endl;
				counter++;
			}
			cout << cargoWeight << "lbs., " << cargoValue << " Treats" << endl;
		}
		else
			cout << "Your cargo hold is empty." << endl;		
	}

	/* Adds cargo to the hold.
	Precondition: Cargo has been claimed or bought.
	
	Postcondition: If there is already cargo of the same type in the hold, add quantity
	to that object. If not, add a new object to cargo vector. */
	void SDShip::addCargo(SDTradeGood &newCargo) {
		int quantity = 0;

		//if (cargo.size() > 0)
			for (unsigned int i = 0; i < cargo.size(); i++) {
				if (cargo[i].getName() == newCargo.getName()) { // If player already has cargo of this type, add to that object.
					if (cargoWeight + newCargo.getWeight() > maxCargoWeight) { // Cannot exceed maxCargoWeight.
						cout << "Your cargo hold is full! Could not add " << newCargo.getWeight()
							<< "lbs. of goods." << endl;
						int availableSpace = maxCargoWeight - cargoWeight; // Amount of available weight.
						quantity = availableSpace / newCargo.getIndividualWeight(); // Quantity that fits under weight limit.
					}
					else
						quantity = newCargo.getQuantity();
					cargo[i].addOrRemoveGoods(quantity);
					newCargo.addOrRemoveGoods(-quantity);

					updateCargoValueAndWeight();
					return;
				}
			}
		
		// Existing cargo not found. Add to cargo vector.
		if(newCargo.getWeight() + cargoWeight <= maxCargoWeight)
			cargo.push_back(newCargo);
		else {
			cout << "Your cargo hold is full! Could not add " << newCargo.getWeight()
				<< "lbs. of goods." << endl;
			int availableSpace = maxCargoWeight - cargoWeight; // Amount of available weight.
			quantity = availableSpace / newCargo.getIndividualWeight(); // Quantity that fits under weight limit.
			SDTradeGood addedGoods(newCargo.getName(), quantity);
			newCargo.addOrRemoveGoods(-quantity);

			cout << "Added " << quantity << " goods instead." << endl;
			cargo.push_back(addedGoods);
		}
		updateCargoValueAndWeight();
	}

	/* Removes cargo from the hold.
	Precondition: Some amount of cargo has been sold or lost.
	param int cargoIndex: Index of TradeGood in cargo vector to have number of items subtracted.
	param int quantity: Number of goods to be removed.
	
	Postcondition: Number of goods have been removed and returns tradeGood object. */
	SDTradeGood SDShip::removeCargo(int cargoIndex, int quantity) {
		SDTradeGood* removedGood;
		if (quantity > cargo[cargoIndex].getQuantity())
			removedGood = new SDTradeGood(cargo[cargoIndex].getName(), cargo[cargoIndex].getQuantity());
		else
			removedGood = new SDTradeGood(cargo[cargoIndex].getName(), quantity);

		if (quantity < cargo[cargoIndex].getQuantity()) {
			cargo[cargoIndex].addOrRemoveGoods(-quantity);
		}
		else {
			quantity = quantity - cargo[cargoIndex].getQuantity();
			cargo.erase(cargo.begin() + cargoIndex);
		}

		updateCargoValueAndWeight();
		return *removedGood;
	}

	/* Updates and returns cargoWeight.
	Precondition: Requested from main program.
	Postcondition: Updates cargo value and weight and returns
	cargoWeight. */
	int SDShip::getCargoWeight() {
		updateCargoValueAndWeight();
		return cargoWeight;
	}

	/* Updates and returns available cargo space.
	Precondition: Requested from main program.
	Postcondition: Updates cargo value and weight and returns
	maxCargoWeight - cargoWeight. */
	int SDShip::getAvailableSpace() {
		updateCargoValueAndWeight();
		return maxCargoWeight - cargoWeight;
	}

	/* Updates and returns cargoValue.
	Precondition: Requested from main program.
	Postcondition: Updates cargo value and weight and returns
	cargoValue. */
	int SDShip::getCargoValue() {
		updateCargoValueAndWeight();
		return cargoValue;
	}

	/* Subtracts amount of damage taken from hull.
	Precondition: Combat has resulted in an attack against the hull.
	param int damage: Amount of damage taken to hull.
	
	Postcondition: Damage is subtracted from hull strength. Returns new hull.
	This value can be negative or 0, which will be handled by a death function. */
	int SDShip::takeDamage(int damage) {
		hull -= damage;
		return hull;
	}

	/* Repairs hull.
	Precondition: Repair request made at ship depot.
	param int repaired: Amount of hull to be restored.
	
	Postcondition: Hull has been repaired up to the max value. Returns amount repaired. */
	int SDShip::repairHull(int repaired) {
		hull += repaired;
		if (hull > maxHull) {
			repaired = repaired - maxHull;
			hull = maxHull;
		}
		return repaired;
	}

	/* Transfers cargo to another ship.
	Precondition: New ship purchased.
	param SDShip newShip: new ship.
	
	Postcondition: All cargo copied to new ship. */
	void SDShip::transferCargo(SDShip& newShip) {
		if (cargo.size() > 0) {
			for (int i = 0; i < cargo.size(); i++)
				newShip.addCargo(cargo[i]);
		}
	}

	/* Helps other functions by updating the cargo value and weight.*/
	void SDShip::updateCargoValueAndWeight() {
		cargoWeight = 0;
		cargoValue = 0;
		for (auto i = cargo.begin(); i != cargo.end(); i++) {
			cargoWeight += (*i).getWeight();
			cargoValue += (*i).getValue();
		}
	}
}