//
// Created by resig on 11/20/2024.
//

#include "Pitfall.h"

#include <string>

#include "Entities/Player.h"

class Map;

Pitfall::Pitfall(Map* map) {
    this->map = map;
}

std::string Pitfall::sound() {
    return "Set up a no sound system";
}

std::string Pitfall::recieveSnowball() {
    return "thump";
}

bool Pitfall::interact(Entity *entity) {
    if (dynamic_cast<Player*>(entity) == nullptr) {
        return true;
    }
    map->endGame();
    return false;
}