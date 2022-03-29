#ifndef GHOST_H
#define GHOST_H

#include "player.h"
#include "character.h"
#include <string>

class ghost: public Character{

public:
    ghost();
    QString getImage();
    int move(int x);
};
#endif // GHOST_H
