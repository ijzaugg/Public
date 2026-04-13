#pragma once
#include <string>

/* Author: Irene Zaugg
* Class: CSC234
* Instructor: Robert Gilanyi

TradeGoods parent class for SpaceDogs game in Wolf Casino.
Trade goods are traded by Dogs and Cats to accumulate Treats.
Each TradeSystem sells a random selection of goods, which will have
some variance in price depending on the average price of the good
and the size of the System.

Goods in this object are treated as a collection of things, the
cumulative total of which gives the object its total price and 
weight.

Private Fields:
	-string name: Name of good.
	-int weight: Weight of an individual good.
	-int quantity: Quantity of items in this object.
	-int value: Value of individual good.
	-int totalWeight: Total weight of all goods in this object.
	-int totalValue: Total value of all goods in this object.
	
Functions:
Public:
	+void toString(): Prints formatted information on good.
	+string getName(): Returns name.
	+int getQuantity: Returns quantity.
	+int getWeight(): Returns totalWeight.
	+int getValue(): Returns totalValue.
	+int getIndividualWeight(): Returns weight.
	+int getIndivudalValue(): Returns value.
	+void addOrRemoveGoods(int numGoods): Adds number of goods to
	this object (can be negative).
	
Private:
	-void setValue(): Sets value for individual good.
	-void setWeight(): Sets weight for individual good.
	good_type nameHash(): Hashes name of good for use with enum. */

using namespace std;

enum good_type {
	ropes,
	turfs,
	plushes,
	squeaks,
	beds,
	leashes,
	balls,
	collars,
	sun
};

namespace CSC234 {
	class SDTradeGood
	{
	public:
		SDTradeGood() { name = "Sold Out"; quantity = 0; value = 0; totalValue = 0; totalWeight = 0; }; // Default constructor.
		SDTradeGood(string name, int quantity); // Constructor.

		void toString(); // Prints formatted information on good.
		string getName() { return name; }; // Returns name.
		int getQuantity() { return quantity; }; // Returns quantity.
		int getWeight() { return totalWeight; }; // Returns weight.
		int getValue() { return totalValue; }; // Returns averagePrice.
		int getIndividualWeight() { return weight; }; // Returns weight of an individual good.
		int getIndividualValue() { return value; }; // Returns value of an individual good.

		void addOrRemoveGoods(int numGoods); // Removes some number of goods from this object.

	private:
		string name; // Name of good.
		int weight, quantity; // Basic statistics for each type of good.
		int value; // Base-line price of good.

		int totalWeight, totalValue; // Total cumulative totals of stats based on quantity.
		// These are largely used as shorthand for other classes to be able to retrieve
		// this information quickly.

		void setValue(); // Sets price for individual good.
		void setWeight(); // Sets weight for individual good.

		good_type nameHash(); // Hashes string type for good name for other functions.
	};
}
