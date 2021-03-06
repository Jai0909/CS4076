#ifndef MYTIMER_H
#define MYTIMER_H
#include "ghost.h"
#include "vampire.h"
#include "zombie.h"
#include "mummy.h"
#include "dragon.h"
#include "alien.h"
#include "pirate.h"
#include "monster.h"
#include "king.h"
#include "player.h"
#include "room.h"
#include "character.h"
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Character * enemy, Player * p, Room* r);
    ~MyTimer();
    void stopTimer();

public slots:
    void villianSlot();

private:
    QTimer * timer;
    Player * play;
    Character * villian;
    ghost * vghost;
    vampire * vvampire;
    zombie * vzombie;
    mummy * vmummy;
    dragon * vdragon;
    alien * valien;
    pirate * vpirate;
    monster * vmonster;
    king * vking;
    Room * room;
    int x=0;
    int health=0;
};

#endif // MYTIMER_H
