#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

class Player{

public:
    Player();
    ~Player();
    int getHealth();
    void decreaseHealth();
    void increaseHealth(const int x);
    int getDamage();
    void setDamage(const int damage);

private:
    int health;
    int damage;
    QMessageBox msgBox;
};

#endif // PLAYER_H
