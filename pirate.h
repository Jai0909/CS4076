#ifndef PIRATE_H
#define PIRATE_H
#include "player.h"
#include "character.h"
#include <string>

class pirate: public Character{

public:
    pirate();
    QString getImage();
    int move(int x);
};
#endif // PIRATE_H
