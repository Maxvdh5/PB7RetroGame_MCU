TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        block.cpp \
        game.cpp \
        gamelevel.cpp \
        main.cpp \
        moveableblock.cpp

HEADERS += \
    block.h \
    config.h \
    game.h \
    gamelevel.h \
    leveldata.h \
    moveableblock.h
