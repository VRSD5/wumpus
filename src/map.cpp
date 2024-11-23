//
// Created by resig on 11/19/2024.
//

#include <algorithm>
#include "map.h"

#include "Entities/Player.h"
#include "Features/Pitfall.h"
#include "Features/Vortex.h"

Map::Map(int size, int startingLevel) {
    this->size = size;

    rooms = new Room**[size];
    for (int y = 0; y < size; y++) {
        rooms[y] = new Room*[size];
        for (int x = 0; x < size; x++) {
            this->rooms[y][x] = new Room(x, y);
        }
    }

    level = startingLevel;
    player = new Player(rooms[size / 2][size / 2], this);

    generateMap(player->getRoom());
}

Map::~Map() {
    for (int y = 0; y < size; y++) {
        delete[] rooms[y];
    }
    delete[] rooms;
}

int Map::getSize() const {
    return size;
}


Room* Map::getRoomAt(int x, int y) {
    return this->rooms[y][x];
}

Room::Room() {
    return;
}

Room::Room(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}

void Room::addEntity(Entity *entity) {
    entities.push_back(entity);
}

void Room::removeEntity(Entity *entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

int Room::getX() const {
    return posX;
}

int Room::getY() const {
    return posY;
}

std::string Room::toString() const {
    return "x" + std::to_string(posX) + " y" + std::to_string(posY);
}

xy Room::getPos() const {
    return {posX, posY};
}

std::string Room::recieveSnowball() {
    if (!entities.empty()) {
        //Currently only have wumpus but figure out some noise priority for multiple entity types
        return entities.at(0)->recieveSnowball();
    }
    if (!features.empty()) {
        return features.at(0)->recieveSnowball();
    }
    return "crunch";
}

std::string Room::hearRoom() {
    if (!entities.empty()) {
        //Currently only have wumpus but figure out some noise priority for multiple entity types
        //return entities.at(0)->sound();
    }
    if (!features.empty()) {
        return features.at(0)->sound();
    }
    return "Empty room noises";
}


void Map::gameLoop() {


}

void Map::generateMap(Room* playerRoom) {
    xy pos = playerRoom->getPos();
    xy lootPos;
    while (lootPos == pos) {
        lootPos = {rand() * size, rand() * size};
    }
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            rooms[y][x]->clearFeatures();
            if ((pos.x != x || pos.y != y) && (lootPos.x != x || lootPos.y != y)) {
                //Add random feature
                if (rand() % 20 < 100) {
                    if (rand() % 20 >= 15) {
                        //todo remove softlock
                        rooms[y][x]->addFeature(new Vortex(rooms[rand() % size][rand() % size]));
                    } else {
                        rooms[y][x]->addFeature(new Pitfall(this));
                    }
                }

            }
        }
    }
}

void Room::addFeature(Feature *feature) {
    features.push_back(feature);
}

void Map::endGame() {
    //todo figure this out
    return;
}



void Room::clearFeatures() {
    features.erase(features.begin(), features.end());
}
