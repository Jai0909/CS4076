#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <ghost.h>
#include <vampire.h>
#include <zombie.h>
#include <mummy.h>
#include <dragon.h>
#include <alien.h>
#include <pirate.h>
#include <monster.h>
#include <QSignalMapper>

MyTimer::MyTimer(Character * enemy, Player * p, Room* r)
{
    villian=enemy;

    room=r;
    play=p;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this, SLOT(villianSlot()));
    timer->start(1000);
    x=0;
}

MyTimer::~MyTimer()
{
    timer->deleteLater();
    room=nullptr;
    play=nullptr;
    villian=nullptr;
}

void MyTimer::stopTimer()
{
    timer->stop();
}

void MyTimer::villianSlot()
{
    villian->setPixmap(QPixmap(villian->getImage()));
    if(villian)
        health=villian->getHealth();
    if(health<=0){
        villian->setVisible(false);
        if(room->ghostInRoom()==true){
            room->setghost(false);
            room->setghostIsDead(true);
        }
        if(room->vampireInRoom()==true){
            room->setvampire(false);
            room->setvampireIsDead(true);
        }
        if(room->zombieInRoom()==true){
            room->setzombie(false);
            room->setzombieIsDead(true);
        }
        if(room->mummyInRoom()==true){
            room->setmummy(false);
            room->setmummyIsDead(true);
        }
        if(room->dragonInRoom()==true){
            room->setdragon(false);
            room->setdragonIsDead(true);
        }
        if(room->alienInRoom()==true){
            room->setalien(false);
            room->setalienIsDead(true);
        }
        if(room->pirateInRoom()==true){
            room->setpirate(false);
            room->setpirateIsDead(true);
        }
        if(room->monsterInRoom()==true){
            room->setmonster(false);
            room->setmonsterIsDead(true);
        }
        stopTimer();
        this->deleteLater();
    }
    else{
        x=villian->move(x);
    }
    if(-1==x)
        play->decreaseHealth();
}



