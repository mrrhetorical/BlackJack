cmake_minimum_required(VERSION 3.13)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)

include_directories(BlackJack)

add_executable(BlackJack
        BlackJack/Card.cpp
        BlackJack/Card.h
        BlackJack/CardManager.cpp
        BlackJack/CardManager.h
        BlackJack/Main.cpp BlackJack/Utils.cpp BlackJack/Delay.h)
