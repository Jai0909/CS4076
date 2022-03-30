#ifndef MONSTER_H
#define MONSTER_H
#include "player.h"
#include "character.h"
#include <string>

class monster: public Character{

public:
    monster();
    QString getImage();
    int move(int x);
};
#endif // MONSTER_H
