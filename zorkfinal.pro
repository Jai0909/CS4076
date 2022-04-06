QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alien.cpp \
    background.cpp \
    character.cpp \
    dragon.cpp \
    ghost.cpp \
    main.cpp \
    mainwindow.cpp \
    monster.cpp \
    mummy.cpp \
    mytimer.cpp \
    pirate.cpp \
    player.cpp \
    room.cpp \
    vampire.cpp \
    zombie.cpp \
    zork.cpp

HEADERS += \
    alien.h \
    background.h \
    character.h \
    dragon.h \
    ghost.h \
    mainwindow.h \
    monster.h \
    mummy.h \
    mytimer.h \
    myvector.h \
    pirate.h \
    player.h \
    room.h \
    ui_mainwindow.h \
    vampire.h \
    zombie.h \
    zork.h

FORMS += \
    mainwindow.ui \
    wordle.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    zork2.pro

DISTFILES += \
    .gitignore \
    .qmake.stash \
    Makefile \
    Makefile.Debug \
    Makefile.Release \
    alien.png \
    alienattack.png \
    cave.jpg \
    dragon.jpg \
    dragonattack.jpg \
    ghost.png \
    ghostattack.png \
    monster.png \
    monsterattack.jpg \
    mummy.png \
    mummyattack.png \
    object_script.zork2.Debug \
    object_script.zork2.Release \
    pirate.png \
    pirateattack.png \
    vampire.jpg \
    vampireattack.jpg \
    zombie.jpg \
    zombieattack.jpg \
    zork2.pro.user \
    zorkfinal.pro.user

RESOURCES += \
    images.qrc
