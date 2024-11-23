//
// Created by resig on 11/19/2024.
//


#include "entity.h"

#include <iostream>

Entity::Entity(Room *room, Map *map) {
    this->room = room;
    room->addEntity(this);
    this->map = map;

    //Probably make it so that map holds all the entities and runs through their turns
}

bool Entity::takeTurn() {
    int x, y;

    std::cout << "Current pos: " << this->room->getX() << " " << this->room->getY() << std::endl;
    std::cout << "room: " << this->room->toString() << std::endl;
    std::cin >> x >> y;
    moveBy(x, y);
    return false;
}

bool Entity::moveBy(int x, int y) {
    return this->moveTo(room->getX() + x, room->getY() + y);
}

bool Entity::moveTo(int x, int y) {
    //Check if movement can happen
    if (x >= map->getSize() || y >= map->getSize() || x < 0 || y < 0) {
        return false;
    }
    return this->moveTo(map->getRoomAt(x, y));
}

bool Entity::moveTo(Room *target) {
    this->room->removeEntity(this);
    this->room = target;
    this->room->addEntity(this);
    return true;
}

xy Entity::getPos() {
    return room->getPos();
}

Room* Entity::getRoom() {
    return room;
}

std::string Entity::recieveSnowball() {
    return "something that wasn't supposed to happen";
}




