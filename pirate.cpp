#include "pirate.h"
#include "spencermansion.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

pirate::pirate()
{
    this->setPixmap(QPixmap(":/Images/pirate.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(470,200);
    this->setZValue(2);
}


QString pirate::getImage()
{
    return ":/Images/pirate.png";
}

int pirate::move(int x){
    if(z==1)
        this->setPixmap(QPixmap(":/Images/pirate.png"));

    if(x==0)
    {
        this->setPos(490,200);
        x=1;
    }
    else if(x==1)
    {
       this->setPos(470,200);
       x=-1;
    }
    else if(x==-1)
    {
        this->setPos(450,200);
        x=2;
    }
    else if(x==2)
    {
        this->setPos(470,200);
        x=3;
    }
    else if(x==3)
    {
        this->setPos(470,220);
        x=4;
    }
    else if(x==4)
    {
        this->setPos(470,200);
        x=5;
    }
    else if(x==5)
    {
        this->setPos(470,180);
        x=6;
    }
    else if(x==6)
    {
        this->setPos(470,200);
        x=0;
    }
   return x;
}
