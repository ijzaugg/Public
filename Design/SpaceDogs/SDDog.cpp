#include "SDDog.h"
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>

using namespace std;

namespace CSC234 {
	/* Empty default constructor to satisfy program requirements. */
	SDDog::SDDog() {}

	/* Constructor. Used for default Mutt breed.
	
	Precondition: New human player created.
	Postcondition: Information for name and gameMap entered. Starting 
	ship implemented as Squeaker. */
	SDDog::SDDog(string playerName, vector<SDTradeSystem*>& map) {
		// Set basic info and traits.
		name = playerName;
		breed = "Mutt";
		setTraits();
		setSpecialAbilityDescription();
		specialAbilityReady = 0; // Starts "ready"

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

	/* Destructor.
	Precondition: Object falls out of scope.
	Postcondition: Dynamically allocated memory released. */
	SDDog::~SDDog() {
		delete location;
		delete HOME_SYSTEM;
	}

	/* Prints information on this Dog.
	Precondition: Info requested by main program.
	Postcondition: Information printed to output. */
	void SDDog::printInfo() {
		cout << "Name: " << name << endl;
		cout << "Breed: " << breed << endl;
		cout << "Trade Bonus: " << tradeBonus << endl;
		cout << "Bark Bonus: " << barkBonus << endl;
		cout << "Bite Bonus: " << biteBonus << endl;
		cout << "Special Ability: " << specialAbilityName << endl;
		cout << specialAbilityDescription << endl;
	}

	/* Allows access to ship functions.
	Precondition: Trading or combat functions required by game manager.
	Postcondition: Returns pointer to ship. */
	SDShip* SDDog::shipFunctions() {
		return &ship;
	}

	/* Swaps old ship for new ship.
	Precondition: New ship purchased.
	param SDShip* newShip: Ship that was purchased.
	
	Postcondition: ship = newShip. */
	void SDDog::buyNewShip(SDShip* newShip) {
		ship.transferCargo(*newShip);
		ship = *newShip;
	}

	/* Updates and returns score.
	Precondition: Request for score by main program.
	Postcondition: Returns int value of score. */
	int SDDog::getScore() {
		updateScore();
		return score;
	}

	/* Changes location.
	Precondition: Player chooses to fly to a new location.
	param SDTradeSystem* location: New location
	
	Postcondition: location updated to new position in map. */
	void SDDog::flyTo(SDTradeSystem* location) {
		this->location = location;
	}

	/* Bark attack during combat (tries to force pirate to flee).
	Precondition: Bark option chosen in combat.
	Postcondition: Returns total bark strength (ship bark + player bonus
	+ random percentage bonus) */
	int SDDog::bark() {
		double bonus = rand() % 60 / 100.0; // Bonus 0-60%.
		int barkDamage = (ship.bark() + barkBonus) + (bonus * (ship.bark() + barkBonus));
		return barkDamage;
	}

	/* Bite attack during combat (causes damage to pirate).
	Precondition: Bite option chosen in combat.
	Postcondition: Returns total bite strength (ship bite + player bonus
	+ random percentage bonus) */
	int SDDog::bite() {
		double bonus = rand() % 60 / 100.0; // Bonus 0-60%.
		int biteDamage = (ship.bite() + biteBonus) + (bonus * (ship.bite() + biteBonus));
		return biteDamage;
	}

	/* Player has died.
	Precondition: Ship's hull reaches 0.
	Postcondition: Randomly loses up to 50% of treats, location returned to homeworld. */
	void SDDog::death() {
		cout << "You return to your homeworld with your tail between your legs." << endl;
		cout << "Fortunately, the High Council of " << breed << "s is very understanding" << endl;
		cout << "and replace your ship, but the cats have made off with ";
		int lostTreats = ((rand() % 50 + 1)/ 100.0) * treats; // Lose between 1% and 50% treats.
		cout << lostTreats << " treats." << endl;
		treats -= lostTreats;

		location = HOME_SYSTEM; // Return to starting position.
		ship.repairHull(100); // Hull reset to max.
	}

	/* Does something special for each breed.
	Precondition: Default breed "Mutt" uses special ability during game.
	Postcondition: 5 points restored to ship hull. */
	void SDDog::specialAbility() {
		if (specialAbilityAvailable()) {
			cout << "You scramble around the nearest space junkyard and find" << endl;
			cout << "all the space parts you need to repair your ship." << endl;
			ship.repairHull(5);
			cout << "Your hull is now " << ship.getHull() << "/" << ship.getMaxHull() << endl;
			specialAbilityReady = 5; // Ready again in 5 turns.
		}
		else {
			cout << "You get chased away by the local space garbage man." << endl;
			cout << "Special ability not ready for " << specialAbilityReady << " space rounds." << endl;
		}
	}

	/* Determines if special ability can be used.
	Precondition: specialAbilityReady score is either > 0 or <= 0.
	Postcondition: If specialAbilityReady is > 0, return false. Else return true. */
	bool SDDog::specialAbilityAvailable() {
		if (specialAbilityReady <= 0)
			return true;
		else
			return false;
	}

	/* Runs end-of-turn processes.
	Precondition: Player has finished turn.
	Postcondition: specialAbilityReady reduced by 1. */
	void SDDog::endTurn() {
		specialAbilityReady--;
	}

	/* Adds number of treats to current (negative if spending treats).
	Precondition: Treats spent or earned, usually in trade action.
	param int numTreats: Number of treats added to total.
	
	Postcondition: numTreats added to total (may be negative).*/
	void SDDog::spendOrEarnTreats(int numTreats) {
		SDDog::treats += numTreats;
	}

	/* Adds together score elements and assigns to score variable.
	Precondition: Called by getScore() function.
	Postcondition: Adds treats on-hand, ship value, and cargo value.
	Assigns total to score variable. */
	void SDDog::updateScore() {
		score = 0;
		score += ship.getCargoValue();
		score += ship.getShipValue();
		score += treats;
	}

	/* Sets traits.
	Precondition: Called by constructor.
	Postcondition: biteBonus, barkBonus, and tradeBonus are set.
	For this default parent class, all bonuses are randomized
	between 0 and 3.*/
	void SDDog::setTraits() {
		srand(time(NULL));
		barkBonus = rand() % 3;
		biteBonus = rand() % 3;
		tradeBonus = rand() % 3;
	}

	/* Sets description of special ability.
	Precondition: Called by constructor.
	Postcondition: specialAbilityName and specialAbilityDescription initialized.
	For default Mutt class, ability is "Space Junkyard." */
	void SDDog::setSpecialAbilityDescription() {
		specialAbilityName = "Space Junkyard";
		specialAbilityDescription = "You're not one of those plush pure-breeds. You've spent";
		specialAbilityDescription += "\na fair amount of time in the space junkyards and you";
		specialAbilityDescription += "\nknow your way around.";
		specialAbilityDescription += "\nYou can repair 5 hull points on your ship every 5 rounds.";
	}
}