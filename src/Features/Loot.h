//
// Created by resig on 11/20/2024.
//

#ifndef LOOT_H
#define LOOT_H
#include <string>


#include "map.h"


class Loot : public Feature {
    public:
        Loot(Map* map);

        std::string recieveSnowball() override;
        std::string sound() override;

        bool interact(Entity *entity) override;
};



#endif //LOOT_H
