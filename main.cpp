#include <QApplication>
#include <QGraphicsScene>
#include "zork.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QDebug>
#include "spencermansion.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Zork *zork1=new Zork();
    spencermansion *bg = new spencermansion(zork1);
    zork1->setScene(bg);
    zork1->show();
    return app.exec();
}
