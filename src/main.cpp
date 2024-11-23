#include <iostream>
#include "map.h"
#include "entity.h"
#include "Entities/Player.h"
#include "Entities/wumpus.h"
using namespace std;

int main() {

  cout << "test" << endl;
  Map map = Map(10, 2);
  Entity *player = new Player(map.getRoomAt(5,5), &map);
  Entity *wumpus = new Wumpus(player, map.getRoomAt(5,0), &map);

  while (true) {
    player->takeTurn();
    wumpus->takeTurn();
  }
  return 0;
}