QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    character.cpp \
    dragon.cpp \
    ghost.cpp \
    main.cpp \
    mainwindow.cpp \
    mummy.cpp \
    mytimer.cpp \
    player.cpp \
    room.cpp \
    vampire.cpp \
    zombie.cpp \
    zork.cpp

HEADERS += \
    background.h \
    character.h \
    dragon.h \
    ghost.h \
    mainwindow.h \
    mummy.h \
    mytimer.h \
    myvector.h \
    player.h \
    room.h \
    vampire.h \
    zombie.h \
    zork.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    zork1.pro

RESOURCES += \
    images.qrc

DISTFILES += \
    Treasure.jpeg \
    attack.png \
    dragon.png \
    dragonAttack.png \
    imgres.jpg \
    pic.jpg \
    sword.jpg \
    sword2.jpg \
    treasure.jpg \
    vampire.png \
    vampireAttacked.png \
    zork1.pro.user
