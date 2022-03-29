#ifndef DRAGON_H
#define DRAGON_H
#include "player.h"
#include "character.h"
#include <string>

class dragon: public Character{

public:
    dragon();
    QString getImage();
    int move(int x);
};
#endif // DRAGON_H
