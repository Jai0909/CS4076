#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    health=100;
    damage=25;
}

Player::~Player(){
}


int Player::getHealth()
{
    return health;
}

void Player::decreaseHealth()
{
    if(health>=1)
        health=health-5;
    else
    {
        msgBox.setText("You are dead. Game Over.");
        msgBox.setInformativeText("");
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Ok:
                exit(1);
                break;
            case QMessageBox::Cancel:
                exit(1);
                break;
            default:
                break;
        }
    }

}

void Player::increaseHealth(const int x)
{
    health+=x;
}

int Player::getDamage(){
    return damage;
}

void Player::setDamage(const int damage){
    this->damage=damage;
}




