#include "Cake.h"

Cake::Cake(
        const std::string& title, const double& price, const double& weight,
        const std::string& appearance_form, const std::string& weight_units
        ) :
    Dish(title, price, weight), appearance_form(appearance_form)
{
    setWeightUnits(weight_units);
}

std::string Cake::getAppearanceForm() const
{
    return appearance_form;
}

//std::string Cake::getAmountString() const
//{
//    std::stringstream stream;
//    stream << std::fixed << std::setprecision(2) << (int)getWeight();
//    return stream.str() + " " + weight_units;
//}
