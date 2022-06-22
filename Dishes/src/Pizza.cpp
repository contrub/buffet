#include "Pizza.h"

Pizza::Pizza(
        const std::string& title, const double& price, const double& weight,
        const double& meat_percentage, const std::string& weight_units
        ) :
        Dish(title, price, weight), meat_percentage(meat_percentage)
{
    setWeightUnits(weight_units);
}

double Pizza::getMeatPercentage() const
{
    return meat_percentage;
}

//std::string Pizza::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}