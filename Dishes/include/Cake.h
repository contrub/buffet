#ifndef BUFFET_CAKE_H
#define BUFFET_CAKE_H

#include "Dish.h"

class Cake : public Dish
{
public:
    Cake(const std::string& title, const double& price, const double& weight);
};


#endif //BUFFET_CAKE_H
