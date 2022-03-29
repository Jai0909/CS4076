#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ghost.h"
#include "player.h"
#include "myvector.h"
#include "room.h"
#include "vampire.h"
#include "zombie.h"
#include "mummy.h"

class Zork : public QGraphicsView
{
    friend class Background;
public:
    Zork(QWidget * parent=0);
    ~Zork();
    Player* play();
    Player* player;
    void createghost();
    void createvampire();
    void createzombie();
    void createmummy();
    void createExits();
    Room * createRooms();

private:
    ghost* vghost;
    vampire * vvampire;
    zombie * vzombie;
    mummy * vmummy;
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    Room *currentRoom;
    myVector<Room*> rooms;
};
#endif // ZORK_H
