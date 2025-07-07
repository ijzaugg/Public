#pragma once
#include "SDTradeGood.h"

/* Author: Irene Zaugg
* Class: CSC234
* Instructor: Robert Gilanyi

Class for NPC Cat Pirates in SpaceDogs game. Has basic stats for
attacking, hull strength, and bark resistance, all randomly
generated.

Private Fields:
	-int attack: Attack strength.
	-int hull: Hull strength (hit points).
	-int barkResistance: Ability to resist fleeing when player
	"barks" at this pirate.
	-SDTradeGood* pirateGoods: Random goods can be looted when
	pirate is destroyed.
	
Functions:
Public:
	+int attackPlayer(): Returns damage dealt to player.
	+int takeDamage(int incomingDamage): Damage dealt by player. Returns
	new hull strength.
	+bool resistBark(int barkStrength): True if bark is resisted.
	+SDTradeGood* lootCargo(): Returns pirateGoods when pirate is destroyed.
	+int getHull(): Returns current hull strength (hit points).
	+void printStats(): Prints information for pirate.
	
Private:
	-void generateRandomTradeGood(): Creates random trade good for constructor. */

namespace CSC234 {
	class SDPirate
	{
	public:
		SDPirate(); // Constructor.

		int attackPlayer(); // Attacks player and returns amount of damage dealt.
		int takeDamage(int incomingDamage); // Subtracts incoming damage from hull and returns new hull.
		bool resistBark(int barkStrength); // If true, does not flee.
		SDTradeGood* lootCargo(); // Take cargo from pirate.
		int getHull() { return hull; }; // Returns hull.

		void printStats(); // Prints info for pirate (largely for troubleshooting purposes).

	private:
		int attack; // Attack strength.
		int hull; // Hit points.
		int barkResistance; // Ability to not flee when Barked at.
		SDTradeGood* pirateGoods; // Random goods that can be looted when pirate defeated.

		void generateRandomTradeGood(); // Used by constructor to set a random trade good.
	};
}