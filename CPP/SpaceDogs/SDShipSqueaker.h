#pragma once
#include "SDShip.h"

/* Author: Irene Zaugg
Class: CSC234
Instructor: Robert Gilanyi

Subclass ship type for SpaceDogs game.
Uses SDShip as parent class.
Sets stats for Squeaker ship. */

namespace CSC234 {
    class SDShipSqueaker :
        public SDShip
    {
    public:
        SDShipSqueaker();
    };
}

