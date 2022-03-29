#include "Room.h"
#include <QDebug>

Room::Room(string description) {
    this->description = description;
    canEnter=true;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

void Room::setghost(bool ghos)
{
    if(ghos)
        ghost=true;
    else
        ghost=false;

}

void Room::setvampire(bool vamp)
{
    if(vamp)
        vampire=true;
    else
        vampire=false;

}

void Room::setzombie(bool zomb)
{
    if(zomb)
        zombie=true;
    else
        zombie=false;
}

void Room::setmummy(bool mumm)
{
    if(mumm)
        mummy=true;
    else
        mummy=false;
}
void Room::setdragon(bool drag)
{
    if(drag)
        dragon=true;
    else
        dragon=false;
}
vector<string> Room::exitString()
{
    vector<string> list;
    list.clear();
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        list.push_back(i->first);	// access the "first" element of the pair (direction as a string)
    return list;
}

bool Room::ghostInRoom()
{
    return ghost;
}

bool Room::vampireInRoom()
{
    return vampire;
}

bool Room::zombieInRoom()
{
    return zombie;
}

bool Room::mummyInRoom()
{
    return mummy;
}

bool Room::dragonInRoom()
{
    return dragon;
}

string Room::getDescription()
{
    return description;
}

vector<Room> Room::rooms()
{
    vector<Room> list;
    list.clear();
    map<string, Room*>::iterator i = exits.begin();
    while (i != exits.end())
    {
        list.push_back(i->first);// access the "first" element of the pair (direction as a string)
        i++;
    }
    return list;
}

Room* Room::nextRoom(string direction) {

    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
    {

        return NULL; // if exits.end() was returned, there's no room in that direction.
    }

    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

bool Room::getghostIsDead()
{
    return ghostIsDead;
}

void Room::setghostIsDead(bool dead)
{
    this->ghostIsDead=dead;
}

bool Room::getvampireIsDead()
{
    return vampireIsDead;
}

void Room::setvampireIsDead(bool dead)
{
    this->vampireIsDead=dead;
}

bool Room::getzombieIsDead()
{
    return zombieIsDead;
}

void Room::setzombieIsDead(bool dead)
{
    this->zombieIsDead=dead;
}

bool Room::getmummyIsDead()
{
    return mummyIsDead;
}

void Room::setmummyIsDead(bool dead)
{
    this->mummyIsDead=true;
}

bool Room::getdragonIsDead()
{
    return dragonIsDead;
}

void Room::setdragonIsDead(bool dead)
{
    this->dragonIsDead=true;
}

bool Room::getCanEnter()
{
    return canEnter;
}

void Room::setCanEnter(bool enter)
{
    this->canEnter=enter;
}

