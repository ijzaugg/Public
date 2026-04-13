#pragma once
#include "SDDog.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Beagle player class for SpaceDogs game. Uses SDDog as parent.
Functions changed by this class:
Public:
    + specialAbility(): Uses special ability, "BaROOO!", which adds
    a pirate to the current location.
    
Private:
    -void setTraits(): Sets traits specifically for Beagle.
    -void setSpecialAbilityDescription(): Sets name and description for
    Beagle ability "BaROOO!" */

namespace CSC234 {
    class SDDogBeagle :
        public SDDog
    {
    public:
        SDDogBeagle(string name, vector<SDTradeSystem*>& map); // Constructor.

        void specialAbility(); // Uses special ability.
    private:
        void setTraits(); // Sets traits for Beagle class.
        void setSpecialAbilityDescription(); // Sets name and description for special ability.
    };
}