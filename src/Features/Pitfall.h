//
// Created by resig on 11/20/2024.
//

#ifndef PITFALL_H
#define PITFALL_H
#include <Feature.h>
#include <string>


class Entity;
class Map;

class Pitfall : public Feature {
public:
    Pitfall(Map* map);

    std::string recieveSnowball() override;
    std::string sound() override;

    bool interact(Entity *entity) override;
private:
    Map* map;
};



#endif //PITFALL_H
