#pragma once
#include "SDShip.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Subclass ship type for SpaceDogs game.
Uses SDShip as parent class.
Sets stats for Kennel ship. */

namespace CSC234 {
    class SDShipKennel :
        public SDShip
    {
    public:
        SDShipKennel();
    };
}