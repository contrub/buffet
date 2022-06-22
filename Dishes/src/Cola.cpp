#include "Cola.h"

Cola::Cola(
        const std::string& title, const double& price, const double& weight,
        const double& sugar_percent, const std::string& weight_units
        ) :
    Dish(title, price, weight), sugar_percent(sugar_percent)
{
    setWeightUnits(weight_units);
}

double Cola::getSugarPercent() const
{
    return sugar_percent;
}

//std::string Cola::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}
