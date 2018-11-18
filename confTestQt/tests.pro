include(gtest_dependency.pri)

QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Eurobusiness-test
TEMPLATE = app
QT += core

CONFIG += c++11


HEADERS += \
    ../src/Board.hpp \
    ../src/Cards.hpp \
    ../src/City.hpp \
    ../src/Dice.hpp \
    ../src/Eurobusiness.hpp \
    ../src/Field.hpp \
    ../src/json.hpp \
    ../src/OrdinaryCard.hpp \
    ../src/Parking.hpp \
    ../src/Player.hpp \
    ../src/Property.hpp \
    ../src/Railway.hpp \
    ../src/Rect.hpp \
    ../src/Roll.hpp \
    ../src/State.hpp \
    ../src/StateCity.hpp \
    ../src/StatePlayer.hpp \
    ../src/StateRailway.hpp \
    ../src/StateWaterSNAndNuclearPP.hpp \
    ../src/WaterSupplyNetwork.hpp \
    ../src/YouGoToPrison.hpp


SOURCES += \
    ../src/Board.cpp \
    ../src/Cards.cpp \
    ../src/City.cpp \
    ../src/Dice.cpp \
    ../src/Eurobusiness.cpp \
    ../src/Field.cpp \
    ../src/OrdinaryCard.cpp \
    ../src/Parking.cpp \
    ../src/Player.cpp \
    ../src/Property.cpp \
    ../src/Railway.cpp \
    ../src/Rec.cpp \
    ../src/Roll.cpp \
    ../src/StateCity.cpp \
    ../src/WaterSupplyNetwork.cpp \
    ../src/YouGoToPrison.cpp \
    ../test/BoardTests.cpp \
    ../test/CityTests.cpp \
    ../test/DiceTests.cpp \
    ../test/EurobusinessTests.cpp \
    ../test/ParkingTests.cpp \
    ../test/PlayerTests.cpp \
    ../test/PropertyTests.cpp \
    ../test/RailwayTests.cpp \
    ../test/RollTests.cpp \
    ../test/test_main.cpp \
    ../test/WaterSupplyNetworkTests.cpp \
    ../test/YouGoToPrisonTests.cpp \
    ../test/CardsTests.cpp
