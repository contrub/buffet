#include "Pizza.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Pizza::Pizza(const std::string& title, const double& price, const double& weight) :
        Dish(title, price, weight)
{}

std::string Pizza::getAmountString() const
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << (int)getWeight();
    return stream.str() + " " + weight_units;
}