#pragma once
#include "SDDog.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Dachsund player class for SpaceDogs game. Uses SDDog as parent class.
Functions changed by this class:
Public:
    +void specialAbility(): Uses special ability "Dig For Treasure" which
    adds a random tradeGood to ship's cargo hold.

Private:
    -void setTraits(): Sets traits for Dachshund class.
    -void setSpecialAbilityDescription(): Sets description for "Dig For Treasure" */

using namespace std;

namespace CSC234 {
    class SDDogDachshund :
        public SDDog
    {
    public:
        SDDogDachshund(string name, vector<SDTradeSystem*>& map); // Constructor.

        void specialAbility(); // Uses special ability "Dig For Treasure."
    private:
        void setTraits(); // Sets traits for Dachshund.
        void setSpecialAbilityDescription(); // Sets description for "Dig for Treasure."
    };
}