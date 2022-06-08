#include "Pizza.h"
#include "Dish.h"

Pizza::Pizza(const std::string& title, const double& price, const double& weight) :
        Dish(title, price, weight)
{}