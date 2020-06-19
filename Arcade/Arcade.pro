TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        enemy.cpp \
        gamemap.cpp \
        hero.cpp \
        main.cpp \
        maingame.cpp \
        physics.cpp

HEADERS += \
    enemy.h \
    gamemap.h \
    hero.h \
    maingame.h \
    physics.h
