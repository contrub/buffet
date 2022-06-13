cmake_minimum_required(VERSION 3.21)
project(buffet)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        People/include People/src
        Dishes/include Dishes/src
        Lists/include Lists/src
)

add_executable(
        buffet main.cpp
        Dishes/include/Cake.h Dishes/src/Cake.cpp
        Dishes/include/Coffee.h Dishes/src/Coffee.cpp
        Dishes/include/Cola.h Dishes/src/Cola.cpp
        Dishes/include/Dish.h Dishes/src/Dish.cpp
        Dishes/include/Pizza.h Dishes/src/Pizza.cpp
        Dishes/include/Salad.h Dishes/src/Salad.cpp
        Dishes/include/Tea.h Dishes/src/Tea.cpp
        Lists/include/Bill.h Lists/src/Bill.cpp
        Lists/include/Menu.h Lists/src/Menu.cpp
        People/include/GreedSeller.h People/src/GreedSeller.cpp
        People/include/Human.h People/src/Human.cpp
        People/include/InattentiveSeller.h People/src/InattentiveSeller.cpp
        People/include/Inspector.h People/src/Inspector.cpp
        People/include/Seller.h People/src/Seller.cpp
        People/include/Visitor.h People/src/Visitor.cpp
)
