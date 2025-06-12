cmake_minimum_required(VERSION 3.31)
project(TradingPlatform)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(my_app
        main.cpp
        order.cpp
        orderbook.cpp
        trader.cpp
        stock.cpp
)