#ifndef BUFFET_COLA_H
#define BUFFET_COLA_H

#include "../Dish.h"

class Cola : public Dish
{
public:
    Cola(const std::string& title, const double& price, const double& weight);
};


#endif //BUFFET_COLA_H
