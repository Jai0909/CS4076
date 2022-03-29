#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "player.h"
#include "character.h"
#include <string>

class zombie: public Character{

public:
    zombie();
    QString getImage();
    int move(int x);
};
#endif // ZOMBIE_H
