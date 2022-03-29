#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsRectItem>
#include "ghost.h"
#include "vampire.h"
#include "zombie.h"
#include "mummy.h"
#include "dragon.h"
#include "alien.h"
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
#include <QFont>
#include "zork.h"
#include <QMessageBox>

class Background : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Background(Zork* zork);
    ~Background();
    void setScene(const string direction);
    inline void refreshScene();
    void setRoomExits(Room * r);
    void createCave();
    void createTextBox();
    void createMapGUI();
    inline void addToScene();
    inline void clearBackground();
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
    QString inventoryString;
    QTextEdit * smallEditor;
    QTextEdit * inventoryEditor;
    Room * nextRoom;
    Player * player;
    int delB1=0;
    int delB2=0;
    int delB3=0;
    int delB4=0;
    int dell1=0;
    int dell2=0;
    int dell3=0;
    int dell4=0;
    int dell5=0;
    int dell6=0;
    int dell7=0;
    int dell8=0;
    QPushButton * button1;
    QPushButton * button2;
    QPushButton * button3;
    QPushButton * button4;
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QLabel * label6;
    QLabel * label7;
    QLabel * label8;
    MyTimer * timer;
    QGraphicsRectItem *RoomA,*RoomB,*RoomC,*RoomD,*RoomE,*RoomF,*RoomG,*RoomH,*RoomI,*RoomJ;
};

#endif // BACKGROUND_H
