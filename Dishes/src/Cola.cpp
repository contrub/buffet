#include "Cola.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Cola::Cola(const std::string& title, const double& price, const double& weight) :
    Dish(title, price, weight)
{}

std::string Cola::getAmountString() const
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << (int)getWeight();
    return stream.str() + " " + weight_units;
}
