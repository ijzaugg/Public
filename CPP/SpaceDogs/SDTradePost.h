#pragma once
#include "SDTradeGood.h"
#include <map>
#include <string>
#include <vector>

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Creates a Trade Post for the Space Dogs game where players can
buy and sell Trade Goods. Contains modified prices for goods,
randomly generated, which players can utilize to their advantage
in making a profit.

Private Fields:
	-vector<SDTradeGood> goodsForSale: List of trade goods for sale.
	-map<string, int> goodsForSalePrices: Map of modified prices for goods for this
	trade post.
	-map<string, int> goodsForPurchasePrices: Prices this trade post will
	purchase goods from players at.
	
Functions:
Public:
	+void printGoodsForSale(double tradeBonus): Prints list of
	goods for sale minus player's tradeBonus.
	+void printGoodsForPurchase(double tradeBonus): Prints list
	of prices post will buy goods at minus player's tradeBonus.
	+SDTradeGood buyGood(int purchasedGood, int quantity): Returns
	a good from index purchasedGood from goodsForSale of given
	quantity.
	+int getGoodForSalePrice(string good, double playerBonus): Returns
	price for a requested good by name minus playerBonus.
	+int getGoodForPurchasePrice(string good, double playerBonus):
	Returns price for requested good by name plus playerBonus.
	+int getNumGoodsForSale(): Returns size of goodsForSale vector.
		
Private:
	-void setRandomGoodsForSale(): Sets up list of goods for constructor.
	-void setGoodsForSalePrices(): Sets up map of prices for goods for sale for
	constructor.
	-void setGoodsForPurchasePrices(): Sets up map of prices for goods for
	purchase for constructor. */

struct tradegoods_map {
	static map<string, int> createMap() {
		map<string, int> temp;
		temp["Robo-Rope Tugs"] = 10;
		temp["Artificial Turfs"] = 25;
		temp["Galactic Plush Toys"] = 35;
		temp["Squeaky Cyber-Toys"] = 40;
		temp["Space Dog Beds"] = 50;
		temp["Self-walker Leashes"] = 60;
		temp["Smart-Balls"] = 75;
		temp["Power Collars"] = 80;
		temp["Automated Sun Beams"] = 100;
		
		return temp;
	}
};

static map<string, int> TRADEGOODS_PRICES = tradegoods_map::createMap(); // Contains map of tradegood base prices.
static const string TRADEGOODS_NAMES[9] = { "Robo-Rope Tugs", "Artificial Turfs", "Galactic Plush Toys",
			"Squeaky Cyber-Toys", "Space Dog Beds", "Self-walker Leashes", "Smart-Balls", "Power Collars",
			"Automated Sun Beams" }; // List of names of tradegoods.

namespace CSC234 {
	class SDTradePost
	{
	public:
		SDTradePost(); // Constructor.

		void printGoodsForSale(double tradeBonus); // Prints list of goods for sale.
		void printGoodsForPurchase(double tradeBonus); // Prints purchase prices of goods the post will buy.

		SDTradeGood buyGood(int purchasedGood, int quantity); // Player buys a good.
		int getGoodPrice(string good, double tradeBonus) { return goodsForSalePrices[good]; }; // Returns purchase price for a given good.
		int sellGood(SDTradeGood soldGood, double tradeBonus); // Player sells a good. Returns trade value.
		SDTradeGood* getGoodForSale(int index); // Returns pointer to a good for sale.
		int getGoodForSalePrice(string name); // Returns price for good for sale at this trade post.
		int getGoodForPurchasePrice(string name); // Returns price trade post will purchase a good at.
		int getNumGoodsForSale() { return goodsForSale.size(); }; // Returns size of goodsForSale.
		
	private:
		vector<SDTradeGood> goodsForSale; // List of goods for sale.
		map<string, int> goodsForSalePrices; // Adjusted prices for goods.
		map<string, int> goodsForPurchasePrices; // Prices offered for players to sell goods.

		void setRandomGoodsForSale(); // Sets up list of goods for sale and prices.
		void setGoodsForSalePrices(); // Sets list of prices for goods for sale.
		void setGoodsForPurchasePrices(); // Sets prices for goods for purchase.
	};
}