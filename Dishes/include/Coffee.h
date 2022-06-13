#ifndef BUFFET_COFFEE_H
#define BUFFET_COFFEE_H

#include "Dish.h"

class Coffee : public Dish
{
public:
    Coffee(const std::string& title, const double& price, const double& weight);
};



#endif //BUFFET_COFFEE_H
