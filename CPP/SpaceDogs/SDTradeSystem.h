#pragma once
#include "SDPirate.h"
#include "SDTradePost.h"
#include "SDShipDepot.h"
#include <vector>

/* Author: Irene Zaugg
 Class: CSC234
 Instructor: Robert Gilanyi

 Trading System object for Space Dogs game. Trading Systems populate the
 map vector in the game manager and represent the locations in the game.
 Subclasses describe the differently sized systems and what each is able
 to contain. This parent class creates basic functions for the three
 subclasses.
 
 Private Fields:
	-vector<SDPirates> pirates: List of pirates in system.
	-string size: Size of system (small, medium, or large).
	-bool tradePostExists: True if there is a trade post in this system.
	-bool shipDepotExists: True if there is a ship depot in this system.
	SDTradePost* tradePost: Pointer to tradePost object.
	SDShipDepot* shipDepot: Pointer to shipDepot object.
	
Functions:
Public:
	+void systemInfo(): Prints information on system.
	+string getSize(): Returns size.
	+void addPirate(): Adds a new SDPirate object to pirates vector.
	+void addPirate(SDPirate* newPirate): Adds an existing pirate to
	the pirates vector.
	+SDPirate* removePirate(int removedPirateIndex): Allows pirate to
	be passed from this system to another (pirate flees).
	+SDTradeGood* destroyPirate(int destroyedPirateIndex): Destroys
	pirate and returns its tradeGood.
	+int getNumPirate(): Returns size of pirate vector.
	+SDPirate* getPirateInfo(int index): Allows access to pirate functions for
	given pirate.
	+void addTradePost(): Adds new trade post and sets tradePostExists to true.
	+void removeTradePost(): Removes trade post and sets tradePostExists to false.
	+bool tradePostPresent(): Returns true if trade post exists.
	+SDTradePost* tradePostFunction(): Allows access to trade post functions.
	+SDTradeGood* checkoutGood(int index) const: Returns link to good.
	+void addShipDepot(): Adds new ship depot and sets shipDepotExists to true.
	+void removeShipDepot(): Removes ship depot and sets shipDepotExists to false.
	+SDShipDepot* shipDepotFunction(): Allows access to ship depot functions.
	+bool shipDepotPresent(): Returns true if depot exists.
	
Private:
	-void buildSmallSystem(): Constructor builds small system.
	-void buildMediumSystem(): Constructor builds medium system.
	-void buildLargeSystem(): Constructor builds large system. */

namespace CSC234 {
	class SDTradeSystem
	{
	public:
		SDTradeSystem(string size); // Constructor.
		~SDTradeSystem(); // Destructor;

		void systemInfo(); // Prints information on system.
		string getSize() { return size; }; // Returns size.

		// Small system+ functions.
		void addPirate(); // Adds a Pirate object to the pirates vector.
		void addPirate(SDPirate* newPirate); // Adds a given pirate to the pirates vector.
		SDPirate* removePirate(int removedPirateIndex); // Allows Pirate to be passed from this system to another.
		SDTradeGood* destroyPirate(int destroyedPirateIndex); // Destroys pirate and returns looted goods.
		int getNumPirates() { return pirates.size(); }; // Returns number of pirates in system.
		SDPirate* getPirateInfo(int index) { return &pirates[index]; }; // Allows access to pirate functions for given pirate.
		
		// Medium system+ functions.
		void addTradePost(); // Allows trade post construction.
		void removeTradePost(); // Destroys existing trade post.

		bool tradePostPresent() { return tradePostExists; }; // True if trade post exists.
		SDTradePost* tradePostFunction(); // Returns pointer to tradePost for function access.
		SDTradeGood* checkoutGood(int index) const; // Returns pointer to a tradeGotod in the post.

		// Large system functions.
		void addShipDepot(); // Adds ship depot.
		void removeShipDepot(); // Removes ship depot.

		SDShipDepot* shipDepotFunction(); // Returns pointer to depot for function access.
		bool shipDepotPresent() { return shipDepotExists; }; // True if ship depot exists.

	private:
		vector<SDPirate> pirates; // Pirates in this system.
		string size; // Size of system.
		bool tradePostExists; // True if trade post is present.
		bool shipDepotExists; // True if ship depot is present.

		SDTradePost* tradePost;
		SDShipDepot* shipDepot;

		void buildSmallSystem(); // Adds parameters for small system.
		void buildMediumSystem(); // Adds parameters for medium system.
		void buildLargeSystem(); // Adds parameters for large system.
	};
}

