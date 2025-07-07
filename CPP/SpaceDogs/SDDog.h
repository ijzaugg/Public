#pragma once
#include "SDShip.h"
#include "SDTradeSystem.h"
#include <string>
#include <vector>

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Player class for SpaceDogs game. This class doubles as a Mutt breed.
Includes fields for player's name, dog's breed, special ability
name and description, and location in the map.

Protected fields:
	-string name: Player's name.
	-string breed: Name of dog's breed.
	-int barkBonus: Rating for bark (causes pirate to flee).
	-int biteBonus: Rating for bite (damage to pirate).
	-int tradeBonus: Rating for trade (added to sale of goods, subtracted from
	purchase of goods).
	-string SpecialAbilityName: Name of special ability.
	-string SpecialAbilityDescription: Description of special ability.
	-int specialAbilityReady: Counts down on each turn. Starts at 5. At 0-,
	-special ability can be used.
	-SDShip ship: player's current ship. Starts as Squeaker.
	-vector<SDTradeSystem*> gameMap: Pointer to game map.
	-SDTradeSystem* location: Pointer to a field in game map (player's location).
	-SDTradeSystem* HOME_SYSTEM: Starting position for player.
	-int treats: Number of treats on hand (game currency).
	-int score: Numerical score (treats + ship value + cargo value).

Included functions:
Public:
	+string getName(): Returns name value.
	+string getBreed(): Returns breed value.
	+void printInfo(): Prints formatted information on name, breed,
	traits, and special ability.
	+SDShip* shipFunctions(): Shortcut access to ship functions. 
	+void buyNewShip(SDShip* newShip): Replaces current ship.
	+int getScore(): Updates and returns score.
	+int getTreats(): Returns number of treats.
	+SDTradeSystem* getLocation(): Returns current location.
	+void flyTo(SDTRadeSystem* location(): Updates current location.
	+int bark(): Returns total strength of bark (barkStrength + ship's barkStrength).
	+int bite(): Returns total strength of bite (biteStrength + ship's biteStrength).
	+void death(): Subtracts treats and resets location to home system when
	player dies.
	+virtual void specialAbility(): Uses breed's special ability (for Mutt,
	repairs 5 points of ship hull).
	+bool specialAbilityAvailable(): Returns true specialAbilityReady is <=0.
	+string getSpecialAbilityName(): Returns specialAbilityName.
	+string getSpecialAbilityDescription(): Returns specialAbilityDescription.
	+int getTradeBonus(): Returns tradeBonus.
	+void endTurn(): Updates specialAbilityReady at end of player's turn.
	+voidSpendOrEarnTreats(int numTreats): Adds number of treats to total (can
	be negative if spending treats).

Protected Functions:
	-virtual void setTraits(): Sets traits for current breed.
	-virtual void setSpecialAbilityDescription(): Sets string for
	specialAbilityDescription.
	-void updateScore(): Adds treats, ship value, and cargo value for score. */

namespace CSC234 {
	class SDDog
	{
	public:
		SDDog(); // Default constructor.
		SDDog(string name, vector<SDTradeSystem*>& gameMap);
		~SDDog();

		string getName() { return name; };
		string getBreed() { return breed; };
		void printInfo(); // Prints information on this Dog.

		SDShip* shipFunctions(); // Allows access to public ship functions.
		void buyNewShip(SDShip* newShip); // Replaces ship with newShip.
		int getScore(); // Updates and returns score.
		int getTreats() { return treats; }; // Returns number of treats on-hand.

		SDTradeSystem* getLocation() { return location; }; // Returns current location.
		void flyTo(SDTradeSystem* location); // Sets new location.

		int bark(); // Calculates bark during combat.
		int bite(); // Calculates bite during combat.
		void death(); // Resets player location and subtracts up to 50% treats when death occurs.

		virtual void specialAbility(); // Breed's basic ability (overwritten in all children).

		bool specialAbilityAvailable(); // Ability can be used only every 5 rounds.
		string getSpecialAbilityName() { return specialAbilityName; }; // Returns special ability name.
		string getSpecialAbilityDescription() { return specialAbilityDescription; }; // Returns special ability desc.

		int getTradeBonus() { return tradeBonus; }; // Returns trade bonus.

		void endTurn(); // Runs all necessary functions to end turn.

		void spendOrEarnTreats(int numTreats); // Adds or removes treats from total.

	protected:
		string name, breed; // Player descriptions.
		int barkBonus, biteBonus, tradeBonus; // Breed adaptive traits.
		string specialAbilityName, specialAbilityDescription; // Special ability descriptives.
		int specialAbilityReady; // When at 0, allows special ability use.
		SDShip ship; // Current ship.

		// Map features.
		vector<SDTradeSystem*> gameMap; // Points to game's map.
		SDTradeSystem* location; // Current location in map.
		SDTradeSystem* HOME_SYSTEM; // Starting location (returned here when player dies).

		// Scoring
		int treats; // Game currency.
		int score; // Numerical score.

		virtual void setTraits(); // Sets bonus traits (random for Mutt).
		virtual void setSpecialAbilityDescription(); // Sets description components for special ability.
		void updateScore(); // Adds treats, ship value, and cargo value to update score.
	};
}

