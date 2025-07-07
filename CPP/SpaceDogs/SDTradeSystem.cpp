#include "SDTradeSystem.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace CSC234 {
	/* Constructor.
	Precondition: Object called by manager program either during initial game
	construction or player exploration.

	Postcondition: Object instantiated. 50% chance that a pirate has been
	added to this space. */
	SDTradeSystem::SDTradeSystem(string size = "small") {
		this->size = size;
		pirates.resize(0);

		if (size == "small")
			buildSmallSystem();
		else if (size == "medium")
			buildMediumSystem();
		else
			buildLargeSystem();
	}

	/* Destructor.
	Precondition: Object has fallen out of scope.
	Postcondition: Memory pointers are removed. */
	SDTradeSystem::~SDTradeSystem() {
		delete tradePost;
		delete shipDepot;
	}

	/* Prints information on system.
	Precondition: Player has started turn in System.

	Postcondition: Information on System printed to output. */
	void SDTradeSystem::systemInfo() {
		cout << "This is a " << size << " system." << endl;
		if (pirates.size() == 1)
			cout << "There is 1 cat pirate in this system." << endl;
		else if (pirates.size() > 1)
			cout << "There are " << pirates.size() << " cat pirates in this system." << endl;
		if (tradePost != NULL)
			cout << "There is a trading post in this system." << endl;
		if (shipDepot != NULL)
			cout << "There is a ship depot in this system." << endl;
	}

	/* Adds a Pirate.
	Precondition: System instantiated, player enters space, or special ability
	used.

	Postcondition: New Pirate object added to priates vector. */
	void SDTradeSystem::addPirate() {
		pirates.push_back(SDPirate());
	}

	/* PIRATE FUNCTIONS */

	/* Adds a Pirate from another system.
Precondition: Pirate flees from nearby sector.

Postcondition: Pirate object added to priates vector. */
	void SDTradeSystem::addPirate(SDPirate* newPirate) {
		pirates.push_back(*newPirate);
	}

	/* Removes a pirate from the pirate vector.
	Precondition: Pirate is destroyed or flees.

	Postcondition: Pirate is removed from local pirates vector. Returns reference
	to that Pirate so that it can either be added to another System or asked for
	loot function and destroyed. */
	SDPirate* SDTradeSystem::removePirate(int removedPirateIndex) {
		SDPirate* tempPirate = &pirates[removedPirateIndex];
		pirates.erase(pirates.begin() + removedPirateIndex);
		return tempPirate;
	}

	SDTradeGood* SDTradeSystem::destroyPirate(int destroyedPirateIndex) {
		SDPirate* tempPirate = &pirates[destroyedPirateIndex];
		pirates.erase(pirates.begin() + destroyedPirateIndex);
		return tempPirate->lootCargo();
	}
	
	/* TRADEPOST FUNCTIONS */

	/* Adds a TradePost.
Precondition: Either constructor or player ability has added a trade post to the system.

Postcondition: tradePostExists = true. forSale, modifiedSalePrices, and modifiedBuyPrices
are all populated with TradeGood values. */
	void SDTradeSystem::addTradePost() {
		if (!tradePostExists && (size == "medium" || size == "large")) { // Do not replicate, must be correct size
			tradePostExists = true;
			tradePost = new SDTradePost;
		}
	}

	/* Removes a TradePost.
	Precondition: TradePost destroyed (special ability only).

	Postcondition: TradePost pointer cleared and set to NULL. */
	void SDTradeSystem::removeTradePost() {
		tradePostExists = false;
		tradePost = NULL;
	}

	/* Returns pointer to trade post if it exists. Allows access
	to trade functions from system level. */
	SDTradePost* SDTradeSystem::tradePostFunction() {
		try {
			return tradePost;
		}
		catch (string e) {
			cout << "Trade post does not exist." << endl;
		}
	}

	/* Returns a pointer to a good inside the trade post.
	Allows that good to be examined by functions in the
	main program.
	Precondition: Trade good is requested by index.
	param int index: Index of good in tradePost's
	goodsForSale vector.
	
	Postcondition: Returns pointer to tradeGood, which
	can then run public functions from main program. */
	SDTradeGood* SDTradeSystem::checkoutGood(int index) const {
		return tradePost->getGoodForSale(index);
	}

	/* SHIPDEPOT FUNCTIONS */
	
	/* Adds a new ship depot.
	Precondition: System constructed or player uses special ability.

	Postcondition: If there was no depot in the system, instantiates new one and sets
	shipDepotExists to true. */
	void SDTradeSystem::addShipDepot() {
		if (!shipDepotExists && size == "large") {
			shipDepotExists = true;
			shipDepot = new SDShipDepot;
		}
	}

	/* Removes ship depot from system.
	Precondition: System has a depot and player has destroyed it using special ability.
	Postcondition: shipDepotExists set to false and shipDepot deleted. */
	void SDTradeSystem::removeShipDepot() {
		if (shipDepotExists) {
			shipDepotExists = false;
			shipDepot = NULL;
		}
	}

	/* Returns pointer to ship depot if it exists. Allows access
	to trade functions from system level. */
	SDShipDepot* SDTradeSystem::shipDepotFunction() {
		try {
			return shipDepot;
		}
		catch (string e) {
			cout << "Ship depot does not exist." << endl;
		}
	}

	/* CONSTRUCTOR HELPERS */
	
	/* Formats small system.
	Precondition: New system created of "small" size.
	Postcondition: 50% chance cat pirate is added. */
	void SDTradeSystem::buildSmallSystem() {
		srand(time(NULL));
		int pirateGenerator = rand() % 2; // Generate either a 0 or 1.
		if (pirateGenerator == 1)
			addPirate();

		tradePostExists = false;
		tradePost = NULL;

		shipDepotExists = false;
		shipDepot = NULL;
	}

	/* Formats medium system.
	Precondition: New system created of "medium" size.
	Postcondition: Has a 50% chance of containing a trade post and 40%
	chance of containing a Cat Pirate.*/
	void SDTradeSystem::buildMediumSystem() {
		srand(time(NULL));
		int tradePostChance = rand() % 2; // Generate a 0 or 1.
		if (tradePostChance == 1) { // 50% chance of generating a trade post.
			tradePostExists = true;
			tradePost = new SDTradePost();
		}
		else {
			tradePostExists = false;
			tradePost = NULL;
		}

		int pirateChance = rand() % 10 + 1; // Random number between 1 and 10.
		if (pirateChance <= 4) // 40% chance of pirate being generated.
			addPirate();

		shipDepotExists = false;
		shipDepot = NULL;
	}

	/* Foramts large system.
	Precondition: New system constructed of "large" size.
	Postcondition: System formatted with 50 % chance of ship depot
	being present, 70 % chance of trade post being present, and 30 % chance
	of cat pirate being present. */
	void SDTradeSystem::buildLargeSystem() {
		srand(time(NULL));

		int shipDepotChance = rand() % 2; // Generate a 0 or 1.
		if (shipDepotChance == 1) { // 50% chance of generating a trade post.
			shipDepotExists = true;
			shipDepot = new SDShipDepot;
		}
		else {
			shipDepotExists = false;
			shipDepot = NULL;
		}

		int tradePostChance = rand() % 10 + 1;
		if (tradePostChance <= 7) { // 70% chance of generating a trade post.
			addTradePost();
		}

		int pirateChance = rand() % 10 + 1; // Random number between 1 and 10.
		if (pirateChance <= 3) // 30% chance of pirate being generated.
			addPirate();
	}
}

