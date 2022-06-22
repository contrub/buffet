#include "Salad.h"

Salad::Salad(
        const std::string& title, const double& price, const double& weight,
        const double& green_percentage, const std::string& weight_units
        ) :
        Dish(title, price, weight), green_percentage(green_percentage)
{
    setWeightUnits(weight_units);
}

double Salad::getGreenPercentage() const
{
    return green_percentage;
}

//std::string Salad::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}