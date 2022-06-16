#include "Tea.h"

#include <iostream>
#include <iomanip>

Tea::Tea(const std::string& title, const double& price, const double& weight) :
        Dish(title, price, weight)
{}

std::string Tea::getAmountString() const
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << (int)getWeight();
    return stream.str() + " " + weight_units;
}