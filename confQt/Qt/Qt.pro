#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T16:12:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Eurobusiness
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    ../../src/Board.cpp \
    ../../src/Cards.cpp \
    ../../src/City.cpp \
    ../../src/Dice.cpp \
    ../../src/Eurobusiness.cpp \
    ../../src/Field.cpp \
    ../../src/main.cpp \
    ../../src/OrdinaryCard.cpp \
    ../../src/Parking.cpp \
    ../../src/Player.cpp \
    ../../src/Property.cpp \
    ../../src/Railway.cpp \
    ../../src/Rec.cpp \
    ../../src/Roll.cpp \
    ../../src/StateCity.cpp \
    ../../src/WaterSupplyNetwork.cpp \
    ../../src/YouGoToPrison.cpp

HEADERS  += \
    ../../src/Board.hpp \
    ../../src/Cards.hpp \
    ../../src/City.hpp \
    ../../src/Dice.hpp \
    ../../src/Eurobusiness.hpp \
    ../../src/Field.hpp \
    ../../src/json.hpp \
    ../../src/OrdinaryCard.hpp \
    ../../src/Parking.hpp \
    ../../src/Player.hpp \
    ../../src/Property.hpp \
    ../../src/Railway.hpp \
    ../../src/Rect.hpp \
    ../../src/Roll.hpp \
    ../../src/State.hpp \
    ../../src/StateCity.hpp \
    ../../src/StatePlayer.hpp \
    ../../src/StateRailway.hpp \
    ../../src/StateWaterSNAndNuclearPP.hpp \
    ../../src/WaterSupplyNetwork.hpp \
    ../../src/YouGoToPrison.hpp

FORMS    += mainwindow.ui
