#include "zork.h"
#include "player.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    createghost();
    createvampire();
    createzombie();
    createmummy();
    currentRoom=createRooms();
    createExits();
}

Zork::~Zork()
{
    delete player;
    delete vghost;
    delete vvampire;
    delete vzombie;
    delete vmummy;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
    delete j;
}

Player* Zork::play(){
    player = new Player();
    player->setDamage(25);
    return player;

}

void Zork::createghost(){
    vghost = new ghost();
}


void Zork::createvampire(){
    vvampire = new vampire();
}

void Zork::createzombie(){
    vzombie = new zombie();
}

void Zork::createmummy(){
    vmummy = new mummy();
}

Room * Zork::createRooms(){

    a= new Room("a");

    b= new Room("b");

    c= new Room("c");

    d= new Room("d");

    e= new Room("e");
    f= new Room("f");

    g= new Room("g");
    h= new Room("h");
    i= new Room("i");
    j= new Room("j");

    rooms+=a;
    rooms+=b;
    rooms+=c;
    rooms+=d;
    rooms+=e;
    rooms+=f;
    rooms+=g;
    rooms+=h;
    rooms+=i;
    rooms+=j;

    return j;
}

void Zork::createExits(){

    //         (N, E, S, W)
    a->setExits(NULL, NULL, NULL, NULL);
    a->setCanEnter(false);

    b->setExits(g, NULL, NULL, NULL);
    b->setmummy(true);
    b->setCanEnter(false);

    c->setExits(NULL, a, NULL, NULL);
    c->setCanEnter(false);

    d->setExits(NULL, e, NULL, NULL);
    d->setvampire(true);
    d->setCanEnter(false);

    e->setExits(b, NULL, NULL, NULL);
    e->setzombie(true);
    e->setCanEnter(false);

    f->setExits(NULL, NULL, NULL, h);
    f->setCanEnter(false);

    g->setExits(NULL, NULL, NULL, f);
    g->setCanEnter(false);

    h->setExits(NULL, NULL, c, NULL);
    h->setCanEnter(false);

    i->setExits(NULL, d, NULL, NULL);
    i->setghost(true);

    j->setExits(i, NULL, NULL, NULL);
}

