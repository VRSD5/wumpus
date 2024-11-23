//
// Created by vanzante on 11/19/2024.
//

#ifndef WUMPUS_H
#define WUMPUS_H
#include "entity.h"


class Wumpus: public Entity {
public:
    Wumpus(Entity *target, Room *room, Map *map);

    bool takeTurn() override;
    std::string recieveSnowball() override;
private:
    Entity *target;
};



#endif //WUMPUS_H
