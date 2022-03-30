#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Room {

private:

    map<string, Room*> exits;
    bool ghost = false;
    bool vampire = false;
    bool zombie = false;
    bool mummy = false;
    bool dragon = false;
    bool alien = false;
    bool pirate = false;
    string description;
    bool ghostIsDead=false;
    bool vampireIsDead=false;
    bool zombieIsDead=false;
    bool mummyIsDead=false;
    bool dragonIsDead=false;
    bool alienIsDead=false;
    bool pirateIsDead=false;
    bool canEnter;

public:
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setghost(bool);
    void setvampire(bool);
    void setzombie(bool);
    void setmummy(bool);
    void setdragon(bool);
    void setalien(bool);
    void setpirate(bool);
    vector<string> exitString();
    string getDescription();
    bool ghostInRoom();
    bool vampireInRoom();
    bool zombieInRoom();
    bool mummyInRoom();
    bool dragonInRoom();
    bool alienInRoom();
    bool pirateInRoom();
    vector<Room> rooms();
    Room* nextRoom(string direction);
    bool getghostIsDead();
    void setghostIsDead(bool dead);
    bool getvampireIsDead();
    void setvampireIsDead(bool dead);
    bool getzombieIsDead();
    void setzombieIsDead(bool dead);
    bool getmummyIsDead();
    void setmummyIsDead(bool dead);
    bool getdragonIsDead();
    void setdragonIsDead(bool dead);
    bool getalienIsDead();
    void setalienIsDead(bool dead);
    bool getpirateIsDead();
    void setpirateIsDead(bool dead);
    bool getCanEnter();
    void setCanEnter(bool);
};

#endif // ROOM_H