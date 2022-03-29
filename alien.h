#ifndef ALIEN_H
#define ALIEN_H
#include "player.h"
#include "character.h"
#include <string>

class alien: public Character{

public:
    alien();
    QString getImage();
    int move(int x);
};
#endif // ALIEN_H
