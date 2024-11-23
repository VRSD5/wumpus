//
// Created by vanzante on 11/19/2024.
//

#include "Player.h"


#include <iostream>
using namespace std;

Player::Player(Room *room, Map *map) : Entity(room, map) {
    snowballCount = 3;
}


bool Player::takeTurn() {


    std::cout << "Current pos: " << this->room->getX() << " " << this->room->getY() << std::endl;
    std::cout << "Room noise: " << this->room->hearRoom() << endl;
    std::cout << "room: " << this->room->toString() << std::endl;


    //Player interface
    //Check for enemies nearby
    if (checkEnemies()) {
        cout << "You hear the crunching of snow." << endl;
    } else {
        cout << "You only hear the sound of your own footsteps." << endl;
    }
    //Option Menu
    while (!actionInterface()) {
        cout << actionRepeatPhrase << endl;
    }
    //Deal with events caused from action (room features)
    return true;
}

bool Player::actionInterface() {
    cout << "Action: N)orth, S)outh, E)ast, W)est, T)hrow Snowball, M)ake Snowballs, H)elp, Q)uit:" << endl;
    char a;
    cin >> a;
    bool success;

    switch(a) {
        case 'N':
        case 'n':
            success = playerMoveBy(0, -1);
            break;
        case 'S':
        case 's':
            success = playerMoveBy(0, 1);
            break;
        case 'E':
        case 'e':
            success = playerMoveBy(1, 0);
            break;
        case 'W':
        case 'w':
            success = playerMoveBy(-1, 0);
            break;
        case 'T':
        case 't':
            throwSnowball();
            success = false;

            break;
        case 'M':
        case 'm':
            snowballCount = 3;
            success = true;
            break;
        case 'H':
        case 'h':
            help();
            success = false;
            break;
        case 'Q':
        case 'q':
            cout << "goodbye" << endl;
            exit(0);
        default:
            actionRepeatPhrase = "Error command not recognized";
            success = false;
            break;
    }

    return success;
}

std::string Player::throwSnowball() {
    if (snowballCount == 0) {
        actionRepeatPhrase = "You are out of snowballs";
        return "I need to remove these at some point";
    }
    cout << "Direction: N)orth, S)outh, E)ast, W)est, C)ancel: " << endl;
    char a;
    cin >> a;

    xy targetPos;
    string sound;

    switch(a) {
        case 'N':
        case 'n':
            targetPos = {this->room->getX(), this->room->getY() - 1};
            break;
        case 'S':
        case 's':
            targetPos = {this->room->getX(), this->room->getY() + 1};
            break;
        case 'E':
        case 'e':
            targetPos = {this->room->getX() + 1, this->room->getY()};
            break;
        case 'W':
        case 'w':
            targetPos = {this->room->getX() - 1, this->room->getY()};
            break;
        default:
            actionRepeatPhrase = "Canceled Snowball throw";
            return "didn't do anything";
    }
    snowballCount--;
    if (targetPos.x >= map->getSize() || targetPos.y >= map->getSize() || targetPos.x < 0 || targetPos.y < 0) {
        sound = "thunk";
;    } else {
        sound = map->getRoomAt(targetPos.x, targetPos.y)->recieveSnowball();
    }
    actionRepeatPhrase = "You hear " + sound + " from the darkness";

    return "whoops i shouldn't have made this return something and i dont feel like doing anything about this right now";
}


bool Player::playerMoveBy(int x, int y) {
    bool moved = moveBy(x, y);

    actionRepeatPhrase = "Failed to move try again.";
    return moved;
}

bool Player::checkEnemies() {
    return false;
}

void Player::help() {
    cout << "idk help menu stuff" << endl;;
}
