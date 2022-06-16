#ifndef BUFFET_CAKE_H
#define BUFFET_CAKE_H

#include "Dish.h"

class Cake : public Dish
{
public:
    Cake(const std::string& title, const double& price, const double& weight);
    Cake() = default;

    std::string getAmountString() const override;
protected:
    std::string weight_units = "g";
};


#endif //BUFFET_CAKE_H
