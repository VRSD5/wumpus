//
// Created by resig on 11/20/2024.
//

#include "Feature.h"

#include <string>

Feature::Feature() {

}



std::string Feature::recieveSnowball() {
    return "Generic Feature encountered";
}

std::string Feature::sound() {
    return "Generic Feature encountered";
}

bool Feature::interact(Entity *entity) {
    return true;
}


