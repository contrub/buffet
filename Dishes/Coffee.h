//
// Created by onufr on 10.06.2022.
//

#ifndef BUFFET_COFFE_H
#define BUFFET_COFFE_H


#include "Dish.h"

class Coffee : public Dish
{
public:
    Coffee(const std::string& title, const double& price, const double& weight);
};



#endif //BUFFET_COFFE_H
