#ifndef ENTITY_H
#define ENTITY_H

#include "map.h"
#include <string>

class Map;
class Room;

struct xy {
	int x;
	int y;

	bool operator==(const xy& other) const {
		return x == other.x && y == other.y;
	}
};

class Entity {
public:
	Entity(Room *room, Map *map);

	bool moveBy(int x, int y);

	bool moveTo(int x, int y);
	bool moveTo(Room *target);

	xy getPos();
	Room* getRoom();

	virtual bool takeTurn();
	virtual std::string recieveSnowball();

protected:
	Room *room;
	Map *map;
};

#endif
