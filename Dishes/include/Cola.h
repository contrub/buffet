#ifndef BUFFET_COLA_H
#define BUFFET_COLA_H

#include "Dish.h"

class Cola : public Dish
{
public:
    Cola(const std::string& title, const double& price, const double& weight);
    Cola() = default;

    std::string getAmountString() const override;
protected:
    std::string weight_units = "ml";
};


#endif //BUFFET_COLA_H
