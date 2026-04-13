#pragma once
#include "SDDog.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Corgi player class for SpaceDogs game. Uses SDDog as parent class.
Functions changed by this class:
Public:
    +void specialAbility(): Uses special ability "Happy Smile" which
    adds either a trade post or ship depot to the current system (if
    the system's size allows it).
    
Private:
    -void setTraits(): Sets traits for Corgi class.
    -void setSpecialAbilityDescription(): Sets description for "Happy Smile." */

namespace CSC234 {
	class SDDogCorgi : public SDDog
	{
    public:
        SDDogCorgi(string name, vector<SDTradeSystem*>& map); // Constructor.

        void specialAbility(); // Uses special ability "Happy Smile."
    private:
        void setTraits(); // Sets traits for Corgi.
        void setSpecialAbilityDescription(); // Sets description for "Happy Smile."
	};
}