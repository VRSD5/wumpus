//
// Created by resig on 11/21/2024.
//

#ifndef VORTEX_H
#define VORTEX_H
#include "Feature.h"


class Room;

class Vortex : public Feature {
public:
  Vortex(Room* target);

  std::string recieveSnowball() override;
  std::string sound() override;

  bool interact(Entity *entity) override;

private:
  Room* target;
};



#endif //VORTEX_H
