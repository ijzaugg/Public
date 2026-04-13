#include "SDTradePost.h"
#include <iostream>
#include <stdio.h>
#include <iterator>

namespace CSC234 {
	/* Constructor.
	Precondition: Trade post is built either when a trade system is
	instantiated or by a player's special ability.
	
	Postcondition: Trade post is instantiated with populated trade goods
	and prices lists. */
	SDTradePost::SDTradePost() {
		setRandomGoodsForSale();
		setGoodsForPurchasePrices();
		setGoodsForSalePrices();
	}

	/* Prints a formatted list of goods for sale with prices.
	Precondition: Player arrived in system and visits trading post.
	param double tradeBonus: Percentage change in prices based on player's bonus.

	Postcondition: List of goods for sale printed to output.*/
	void SDTradePost::printGoodsForSale(double tradeBonus) {
		tradeBonus = tradeBonus * 5 / 100.0; // 1 = 5%, 2 = 10%...
		cout << "Goods For Sale:" << endl;
		cout << "Name                   Quant.  Weight      Treats" << endl;
		cout << "---------------------------------------------" << endl;
		for (int i = 0; i < goodsForSale.size(); i++) {
			int goodPrice = goodsForSalePrices[goodsForSale[i].getName()];
			goodPrice = goodPrice - (goodPrice * tradeBonus);
			printf("%i. %-20s%-8i%ilbs.%8i\n", i + 1, goodsForSale[i].getName().c_str(),
				goodsForSale[i].getQuantity(), goodsForSale[i].getIndividualWeight(),
				goodPrice);
		}
	}

	/* Prints a formatted list of prices for goods this trading post
	will purchase from players.
	Precondition: Player chooses to see list.
	param double tradeBonus: Percentage change in price based on player's bonus.
	
	Postcondition: List of prices for all goods printed to output. */
	void SDTradePost::printGoodsForPurchase(double tradeBonus) {
		tradeBonus = 5 * tradeBonus / 100.0; // 1 = 5%, 2 = 10%....
		string goodName;
		cout << "Goods Purchase List:" << endl;
		cout << "Name                  Treats/Unit" << endl;
		cout << "-------------------------------" << endl;

		map<string, int>::iterator iter;

		for(iter = goodsForPurchasePrices.begin(); iter != goodsForPurchasePrices.end(); iter++){
			int priceChange = iter->second * tradeBonus;
			printf("%-22s%i\n", iter->first.c_str(), iter->second + priceChange);
		}
	}

	/* Allows player to buy a good.
	Precondition: Player is trading at trade post.
	param int purchasedGood: Index number of purchased good.
	param int quantity: Number of goods bought.
	
	Postcondition: Specified good removed from trade post and returned so it can
	be added to player's cargo. */
	SDTradeGood SDTradePost::buyGood(int purchasedGood, int quantity) {
		if (quantity > goodsForSale[purchasedGood].getQuantity())
			quantity = goodsForSale[purchasedGood].getQuantity();

		goodsForSale[purchasedGood].addOrRemoveGoods(-quantity);

		SDTradeGood boughtGood(goodsForSale[purchasedGood].getName(), quantity);

		if (goodsForSale[purchasedGood].getQuantity() <= 0) {
			goodsForSale.erase(goodsForSale.begin() + purchasedGood);
		}

		return boughtGood;
	}

	/* Player sells good to the trading post.
	Precondition: Player chooses good to sell from cargo hold.
	param SDTradeGood soldGood: Good sold from player.
	param double tradeBonus: Percentage change based on player's bonus.
	
	Postcondition: TradeGood is added to vector and price is calculated.*/
	int SDTradePost::sellGood(SDTradeGood soldGood, double tradeBonus) {
		goodsForSale.push_back(soldGood);
		int priceChange = goodsForPurchasePrices[soldGood.getName()] * tradeBonus;
		return (soldGood.getQuantity() * (goodsForPurchasePrices[soldGood.getName()]
			+ priceChange));
	}

	/* Allows a good to be "checked out" from for-sale list so tests
	can be run on it in main function to determine if a player can
	buy it.
	param int index: Index of good in goodsForSale vector.
	
	Postcondition: Returns pointer to the good. */
	SDTradeGood* SDTradePost::getGoodForSale(int index) {
		return &goodsForSale[index];
	}

	/* Returns modified price for a good by name.
	Precondition: Good requested by user during trade function.
	param string name: Name of good for use in map lookup.
	
	Postcondition: Returns price for given good. */
	int SDTradePost::getGoodForSalePrice(string name) {
		return goodsForSalePrices[name];
	}

	/* Returns price for good this trade post will purchase.
	Precondition: Good price requested by main program.
	param string name: Name of good.
	
	Postcondition: Returns modified price of good. */
	int SDTradePost::getGoodForPurchasePrice(string name) {
		return goodsForPurchasePrices[name];
	}
	/* Trade Post is populated with random list of trade goods. For use with
	constructor.
	Precondition: TradePost is instantiated.
	
	Postcondition: goodsForSale and goodsForSalePrices are populated with list of goods. */
	void SDTradePost::setRandomGoodsForSale() {
		string name;
		int quantity;

		srand(time(NULL));
		int numGoods = rand() % 5 + 1; // Between 1 and 5 goods for sale.

		for (int i = 0; i < numGoods; i++) {
			int random = rand() % 9; // Choose a random good.
			name = TRADEGOODS_NAMES[random];

			quantity = rand() % 50 + 1; // Random quantity between 1 and 50.

			SDTradeGood newGood(name, quantity);
			goodsForSale.push_back(newGood);
		}
	}

	/* Adds a new price listing for a good.
	Precondition: New good generated or sold to trade post by player.
	param SDTradeGood newGood: new good that needs price.
	
	Postcondition: New price is added plus or minus some percentage of the
	average price of the good. */
	void SDTradePost::setGoodsForSalePrices() {
		int price = 0;
		srand(time(NULL));
		
		for(int i = 0; i < 9; i++){
			double percentage = (rand() % 20) / 100.0; // 0-20% change.
			int positiveOrNegative = rand() % 10 + 1; // Setting a 80% chance change is negative.
			if (positiveOrNegative <= 8)
				percentage *= -1;
			price = TRADEGOODS_PRICES[TRADEGOODS_NAMES[i]] +
				(TRADEGOODS_PRICES[TRADEGOODS_NAMES[i]] * percentage); // Add percentage to price.
			goodsForSalePrices.insert(pair<string, int>(TRADEGOODS_NAMES[i], price));
		}
	}

	/* Sets list of prices on goods that the trade post will purchase.
	Precondition: Trading post instantiated.
	Postcondition: Set of 9 different types of trade goods is populated. */
	void SDTradePost::setGoodsForPurchasePrices() {
		srand(time(NULL));
		double percentage;
		int price;

		for (int i = 0; i < 9; i++) {
			percentage = (rand() % 30 - 10) / 100.0; // Between -10% and 20%.
			price = TRADEGOODS_PRICES[TRADEGOODS_NAMES[i]] +
				(TRADEGOODS_PRICES[TRADEGOODS_NAMES[i]] * percentage);
			goodsForPurchasePrices.insert(pair<string, int>(TRADEGOODS_NAMES[i], price));
		}
	}
}