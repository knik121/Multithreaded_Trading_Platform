cmake_minimum_required(VERSION 3.31)
project(TradingPlatform)

set(CMAKE_CXX_STANDARD 20)

add_executable(TradingPlatform main.cpp
        order.h
        orderbook.h)
