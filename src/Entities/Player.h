//
// Created by vanzante on 11/19/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"


class Player: public Entity {
public:
    Player(Room *room, Map *map);

    bool takeTurn() override;

private:
    int snowballCount;
    std::string actionRepeatPhrase;

    bool checkEnemies();
    bool playerMoveBy(int x, int y);
    std::string throwSnowball();

    bool actionInterface();

    static void help();
};



#endif //PLAYER_H
