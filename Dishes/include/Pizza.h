#ifndef BUFFET_PIZZA_H
#define BUFFET_PIZZA_H

#include "Dish.h"

class Pizza : public Dish
{
public:
    Pizza(
            const std::string& title, const double& price, const double& weight,
            const double& meat_percentage, const std::string& weight_units = "cm"
            );
    Pizza() = default;

    double getMeatPercentage() const;
private:
    double meat_percentage;

//    std::string getAmountString() const override;
//protected:
//    std::string weight_units = "cm";
};


#endif //BUFFET_PIZZA_H
