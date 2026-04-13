#pragma once
#include "SDDog.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Chihuahua player class for SpaceDogs game. Uses SDDog as parent.
Functions changed by this class:
Public:
    +void specialAbility(): Uses special ability "Mighty Bite."
    
Private:
    -void setTraits(): Sets traits for Chihuahua.
    -void setSpecialAbilityDescription(): Sets name and description
    for "Mighty Bite" */
using namespace std;

namespace CSC234 {
    class SDDogChihuahua :
        public SDDog
    {
    public:
        SDDogChihuahua(string name, vector<SDTradeSystem*>& map); // Constructor.

        void specialAbility(); // Uses special ability "Mighty Bite"
    private:
        void setTraits(); // Sets traits for Chihuahua.
        void setSpecialAbilityDescription(); // Sets description for "Mighty Bite."
    };
}