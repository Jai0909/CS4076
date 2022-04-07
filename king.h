#ifndef KING_H
#define KING_H
#include "player.h"
#include "character.h"
#include <string>

class king: public Character{

public:
    king();
    QString getImage();
    int move(int x);
};
#endif // KING_H
