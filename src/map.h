#ifndef MAP_H
#define MAP_H

#include <entity.h>
#include <string>
#include <vector>

#include "Feature.h"

class Room;
class Entity;

struct xy;


class Map{
public:
    Map(int size, int startingLevel);

    ~Map();

    void display() const;

    void setup();
    void gameLoop();
    void endGame();

    Room* getRoomAt(int x, int y);

    int getSize() const;
private:
    int size;
    int level;
    Room*** rooms;
    std::vector<Entity*> entities;
    Entity* player;

    void generateMap(Room* playerRoom);
};

class Room{
public:
	Room(int posX, int posY);
    Room();

	int getX() const;
	int getY() const;

    xy getPos() const;

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    std::vector<Entity>* getEntities() const;

    void addFeature(Feature* feature);
    void clearFeatures();

    std::string recieveSnowball();
    std::string hearRoom();

	virtual std::string toString() const;
	~Room() = default;
private:
    int posX;
    int posY;
    std::vector<Entity*> entities;
    std::vector<Feature*> features;


};

#endif
