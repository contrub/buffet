cmake_minimum_required(VERSION 3.21)
project(buffet)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        buffet main.cpp
        Menu.h Menu.cpp
        Bill.h Bill.cpp
        People/Human.h People/Human.cpp
        People/Inspector.h People/Inspector.cpp
        People/Seller.h People/Seller.cpp
        People/GreedSeller.h People/GreedSeller.cpp
        People/Visitor.h People/Visitor.cpp
        Dishes/Dish.h Dishes/Dish.cpp
        Dishes/Cake.h Dishes/Cake.cpp
        Dishes/Pizza.h Dishes/Pizza.cpp
        Dishes/Salad.h Dishes/Salad.cpp
)
