#pragma once
//#include "Casino.h"
#include "SDCat.h"
#include "SDDog.h"
#include "SDShip.h"
#include "SDTradeSystem.h"
#include <set>
#include <vector>

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Runs SpaceDogs game, where the goal is to survive in deep space, eat treats,
and make friends and rivals at the Space Dog Park. Earn a "good boy/girl" rating
through trade and dog park actions.

Usage: makeGame returns game object. Callint start() function on the object will
run the game.

Uses Casino as parent class.

Private fields:
	-DOG_PTR* dogs: Dynamic array of player objects.
	-int numDogs: Number of human players.
	-CAT_PTR* cats: Dynamic array of AI objects (not implemented).
	-int numCats: Number of AI players (not implemented).
	-vector<SDTradeSystem*> map: system map of trade system pointers.
	-int numRounds: Player chooses number of rounds to be played.
	-int roundsPlayed: Total number of rounds completed.
	
Functions:
Public:
	+static SpaceDogs* makeGame(): Returns game object pointer.
	+void start(): Collects information from players and starts game.
	
Private:
	-void printRules(): Prints rules of the game.
	-void setupPlayers(): Sets up dog vector.
	-void setupAIs(): Sets up cat vector (not implemented).
	-SDDog* chooseBreed(string name): Returns appropriate subclass of SDDog
	object based on player's breed choice.
	-void setupMap(): Randomly generates map for beginning of game. Size
	is 3 per each player and AI.
	-void playGame(): Runs game turns.
	-void runCombat(SDDog& player, SDTradeSystem* location): Runs
	combat actions during player's turn.
	-void runTradePost(SDDog& player, SDTradeSystem* location): Runs
	trade post functions during player's turn.
	-void runShipDepot(SDDog& player, SDTradeSystem* location): Runs
	ship depot functions during player's turn.
	-void runFly(SDDog& player, SDTradeSystem* location): Player flies
	to a new system. Ends turn.
	-void getInfo(SDDog& player): Player requests print out of
	different information from a menu.
	-bool gameOver(): Returns true if all rounds have been played.
	-void printScores(): Prints formatted list of scores.
	-void printMap(int currentDog): Prints map of explored systems and
	-location of currently active player. */

namespace CSC234 {
	// Dynamic arrays.
	typedef SDDog* DOG_PTR;
	typedef SDCat* CAT_PTR;
	
	class SpaceDogs //: public Casino
	{
	public:
		SpaceDogs(); // Constructor.
		~SpaceDogs(); // Destructor.
		static SpaceDogs* makeGame(); // Instantiates game object.
		void start(); // Collects information and starts game.

	private:
		/* Player handlers */
		DOG_PTR* dogs; // Human player objects.
		int numDogs; // Number of human players.
		CAT_PTR* cats; // AI player objects. **TODO
		int numCats; // Number of AI players **TODO
		
		/* Map */
		vector<SDTradeSystem*> map; // System map.

		/* Game played for number of rounds */
		int numRounds; // Total number of rounds chosen for the game.
		int roundsPlayed; // Total number of rounds played so far.

		/* Setup functions */
		void printRules();
		void setupPlayers(); // For use by constructor to set up dogs vector.
		void setupAIs(); // For use by constructor to set up cats vector.
		SDDog* chooseBreed(string name); // Prints options and allows player to choose a breed.
		void setupMap(); // Sets up map.

		/* Gameplay functions */
		void playGame(); // Runs game turns.
		void runCombat(SDDog& player, SDTradeSystem* location); // Runs combat options.
		void runTradePost(SDDog& player, SDTradeSystem* location); // Runs trade options.
		void runShipDepot(SDDog& player, SDTradeSystem* location); // Runs ship depot options.
		void runFly(SDDog& player, SDTradeSystem* location); // Player flies to new system, ends turn.
		void getInfo(SDDog& player); // Prints information requested by player.

		bool gameOver(); // If true, end game.
		void printScores(); // Prints scores.

		void printMap(int currentDog); // Prints map.
	};
}

