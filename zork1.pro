QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    boss.cpp \
    character.cpp \
    inventory.cpp \
    item.cpp \
    key.cpp \
    main.cpp \
    mainwindow.cpp \
    monster.cpp \
    mytimer.cpp \
    player.cpp \
    potion.cpp \
    princess.cpp \
    room.cpp \
    teleporter.cpp \
    weapon.cpp \
    zork.cpp

HEADERS += \
    background.h \
    boss.h \
    character.h \
    inventory.h \
    item.h \
    key.h \
    mainwindow.h \
    monster.h \
    mytimer.h \
    myvector.h \
    player.h \
    potion.h \
    princess.h \
    room.h \
    teleporter.h \
    weapon.h \
    zork.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    Treasure.jpeg \
    attack.png \
    cave.jpg \
    dragon.jpg \
    dragon.png \
    dragon.xcf \
    dragonAttack.png \
    imgres.jpg \
    key.png \
    pic.jpg \
    potion.jpg \
    princess.jpg \
    princess.xcf \
    sword.jpg \
    sword2.jpg \
    teleporter.png \
    treasure.jpg \
    vampire.png \
    vampireAttacked.png \
    zork1.pro.user
