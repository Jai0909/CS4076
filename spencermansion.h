#ifndef SPENCERMANSION_H
#define SPENCERMANSION_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsRectItem>
#include "ghost.h"
#include "vampire.h"
#include "zombie.h"
#include "mummy.h"
#include "dragon.h"
#include "alien.h"
#include "pirate.h"
#include "monster.h"
#include "king.h"
#include "room.h"
#include "mytimer.h"
#include "player.h"
#include <QtCore>
#include <string>
#include <QTextEdit>
#include "character.h"
#include <vector>
#include <QComboBox>
#include "myvector.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDebug>
#include <QObject>
#include <QLabel>
#include "zork.h"

class spencermansion : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit spencermansion(Zork* zork);
    ~spencermansion();
    void setScene(const string direction);
    inline void refreshScene();
    void setRoomExits(Room * r);
    void createCave();
    void createTextBox();
    void createMapGUI();
    inline void addToScene();
    inline void clearspencermansion();
    void addText();
    void keyPressEvent(QKeyEvent *event);
    void close();


public slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();

private:
    QMessageBox msgBox;
    QString inventoryContString;
    Zork* zork1;
    QGraphicsPixmapItem *cave;
    QTextEdit * smallEditor;
    Room * nextRoom;
    Player * player;
    int delB1=0;
    int delB2=0;
    int delB3=0;
    int delB4=0;
    int dellabel=0;
    QPushButton * button1;
    QPushButton * button2;
    QPushButton * button3;
    QPushButton * button4;
    QLabel * label;
    MyTimer * timer;
    QGraphicsRectItem *RoomA,*RoomB,*RoomC,*RoomD,*RoomE,*RoomF,*RoomG,*RoomH,*RoomI,*RoomJ;
};

#endif // SPENCERMANSION_H
