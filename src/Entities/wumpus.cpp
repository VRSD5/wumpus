//
// Created by vanzante on 11/19/2024.
//

#include "wumpus.h"

#include <iostream>

Wumpus::Wumpus(Entity *target, Room *room, Map *map) : Entity(room, map) {
    this->target = target;
}

bool Wumpus::takeTurn() {
    xy tPos = target->getPos();
    xy pos = getPos();

    int xDiff = pos.x != tPos.x ? (tPos.x - pos.x) / abs(tPos.x - pos.x) : 0;
    int yDiff = pos.y != tPos.y ? (tPos.y - pos.y) / abs(tPos.y - pos.y) : 0;

    if (abs(xDiff) + abs(yDiff) > 1) {
        moveBy(xDiff, 0);
    } else {
        moveBy(xDiff, yDiff);
    }

    std::cout << "wumpus: " << getPos().x << ", " << getPos().y << std::endl;
    if (tPos == getPos()) {
        std::cout << "Wumpus found target" << std::endl;
    }
    return true;
}

std::string Wumpus::recieveSnowball() {
    //todo implement stun
    return "thwack";
}

