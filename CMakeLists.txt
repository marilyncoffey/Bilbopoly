cmake_minimum_required(VERSION 3.14)
project(FinalForCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FinalForCpp
        Board.cpp
        Board.h
        BoardSpace.cpp
        BoardSpace.h
        card.cpp
        card.h
        cardMoney.cpp
        cardMoney.h
        cardMove.cpp
        cardMove.h
        ChanceSpace.h
        DrawSpace.cpp
        DrawSpace.h
        Game.cpp
        Game.h
        GoSpace.cpp
        GoSpace.h
        GoToJailCard.cpp
        GoToJailCard.h
        GoToJailSpace.cpp
        GoToJailSpace.h
        Header.h
        IncomeTaxSpace.cpp
        IncomeTaxSpace.h
        JailSpace.cpp
        JailSpace.h
        MonopolyApp.cpp
        NonProperty.cpp
        NonProperty.h
        Player.cpp
        Player.h
        Property.cpp
        Property.h
        RailRoadSpace.cpp
        RailRoadSpace.h
        TaxSpace.cpp
        TaxSpace.h
        UtilitySpace.cpp
        UtilitySpace.h cardgetoutofjail.h cardgetoutofjail.cpp)
