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
    createdragon();
    createalien();
    createpirate();
    createmonster();
    createking();
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
    delete vdragon;
    delete valien;
    delete vpirate;
    delete vmonster;
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

void Zork::createdragon(){
    vdragon = new dragon();
}

void Zork::createalien(){
    valien = new alien();
}

void Zork::createpirate(){
    vpirate = new pirate();
}

void Zork::createmonster(){
    vmonster = new monster();
}

void Zork::createking(){
    vking = new king();
}
Room * Zork::createRooms(){

    a= new Room("KING");

    b= new Room("MUMMY");

    c= new Room("MONSTER");

    d= new Room("VAMPIRE");

    e= new Room("ZOMBIE");
    f= new Room("ALIEN");

    g= new Room("DRAGON");
    h= new Room("PIRATE");
    i= new Room("GHOST");
    j= new Room("ZORK");

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
    a->setking(true);
    a->setCanEnter(false);

    b->setExits(g, NULL, NULL, NULL);
    b->setmummy(true);
    b->setCanEnter(false);

    c->setExits(NULL, a, NULL, NULL);
    c->setmonster(true);
    c->setCanEnter(false);

    d->setExits(NULL, e, NULL, NULL);
    d->setvampire(true);
    d->setCanEnter(false);

    e->setExits(b, NULL, NULL, NULL);
    e->setzombie(true);
    e->setCanEnter(false);

    f->setExits(NULL, NULL, NULL, h);
    f->setalien(true);
    f->setCanEnter(false);

    g->setExits(NULL, NULL, NULL, f);
    g->setdragon(true);
    g->setCanEnter(false);

    h->setExits(NULL, NULL, c, NULL);
    h->setpirate(true);
    h->setCanEnter(false);

    i->setExits(NULL, d, NULL, NULL);
    i->setghost(true);

    j->setExits(i, NULL, NULL, NULL);
}

