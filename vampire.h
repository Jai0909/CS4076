#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include "character.h"
#include <string>

class vampire: public Character{

public:
    vampire();
    QString getImage();
    int move(int x);
};
#endif // VAMPIRE_H
