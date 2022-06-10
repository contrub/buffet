#ifndef BUFFET_COFFE_H
#define BUFFET_COFFE_H


#include "../include/Dish.h"

class Coffee : public Dish
{
public:
    Coffee(const std::string& title, const double& price, const double& weight);
};



#endif //BUFFET_COFFE_H
