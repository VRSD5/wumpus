//
// Created by resig on 11/21/2024.
//

#include "Vortex.h"

#include "entity.h"

Vortex::Vortex(Room *target) {
    this->target = target;
}

std::string Vortex::sound() {
    return "fwoosh";
}

std::string Vortex::recieveSnowball() {
    return "thump";
}

bool Vortex::interact(Entity *entity) {
    entity->moveTo(target);
    return true;
}


