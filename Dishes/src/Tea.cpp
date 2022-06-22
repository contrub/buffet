#include "Tea.h"

Tea::Tea(
        const std::string& title, const double& price, const double& weight,
        const std::string& grade, const std::string& weight_units
         ) :
        Dish(title, price, weight), grade(grade)
{
    setWeightUnits(weight_units);
}

std::string Tea::getGrade() const
{
    return grade;
}

//std::string Tea::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}