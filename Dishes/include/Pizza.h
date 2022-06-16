#ifndef BUFFET_PIZZA_H
#define BUFFET_PIZZA_H

#include "Dish.h"

class Pizza : public Dish
{
public:
    Pizza(const std::string& title, const double& price, const double& weight);
    Pizza() = default;

    std::string getAmountString() const override;
protected:
    std::string weight_units = "cm";
};


#endif //BUFFET_PIZZA_H
