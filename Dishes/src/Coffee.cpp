#include "Coffee.h"

Coffee::Coffee(
        const std::string& title, const double& price, const double& weight,
        const double& bitterness, const std::string& weight_units
        ) :
        Dish(title, price, weight), bitterness(bitterness)
{
    setWeightUnits(weight_units);
}

double Coffee::getBitterness() const
{
    return bitterness;
}

//std::string Coffee::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}
