#ifndef MUMMY_H
#define MUMMY_H
#include "player.h"
#include "character.h"
#include <string>

class mummy: public Character{

public:
    mummy();
    QString getImage();
    int move(int x);
};
#endif // MUMMY_H
