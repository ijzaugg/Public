#pragma once
#include "SDShip.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Subclass ship type for SpaceDogs game.
Uses SDShip as parent class.
Sets stats for Dog House 9K ship. */

namespace CSC234 {
    class SDShipDogHouse9K :
        public SDShip
    {
    public:
        SDShipDogHouse9K();
    };
}