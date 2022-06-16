#ifndef BUFFET_COFFEE_H
#define BUFFET_COFFEE_H

#include "Dish.h"

class Coffee : public Dish
{
public:
    Coffee(const std::string& title, const double& price,const double& weight);
    Coffee() = default;

     std::string getAmountString() const override;
protected:
    std::string weight_units = "ml";
};



#endif //BUFFET_COFFEE_H
