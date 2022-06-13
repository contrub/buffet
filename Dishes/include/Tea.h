#ifndef BUFFET_TEA_H
#define BUFFET_TEA_H

#include "Dish.h"

class Tea : public Dish
{
public:
    Tea(const std::string& title, const double& price, const double& weight);
};


#endif //BUFFET_TEA_H
