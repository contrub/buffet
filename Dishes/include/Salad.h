#ifndef BUFFET_SALAD_H
#define BUFFET_SALAD_H

#include "Dish.h"

class Salad : public Dish
{
public:
    Salad(const std::string& title, const double& price, const double& weight);
    Salad() = default;

    std::string getAmountString() const override;
protected:
    std::string weight_units = "g";
};


#endif //BUFFET_SALAD_H
