#ifndef BUFFET_SALAD_H
#define BUFFET_SALAD_H

#include "Dish.h"

class Salad : public Dish
{
public:
    Salad(const std::string& title, const double& price, const double& weight);
};


#endif //BUFFET_SALAD_H
