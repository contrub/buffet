#include "include/Dish.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>

Dish::Dish(const std::string& title, const double& weight, const double& price) :
    title(title), weight(weight), price(price)
{
    if (title.empty()) {
        throw std::invalid_argument("Error..\nTitle cannot be empty");
    }

    if (weight < 0) {
        throw std::invalid_argument("Error..\nWeight cannot be less than 0");
    }

    if (price < 0) {
        throw std::invalid_argument("Error..\nPrice cannot be less than 0");
    }
}

Dish::Dish()  :
    title("Unknown"), weight(0), price(0)
{}

std::string Dish::getTile() const
{
    return title;
}

double Dish::getPrice() const
{
    return price;
}

double Dish::getWeight() const
{
    return weight;
}

void Dish::setTitle(const std::string& new_title)
{
    this->title = new_title;
}

void Dish::setWeight(const double& new_weight)
{
    this->weight = new_weight;
}

void Dish::setPrice(const double& new_price)
{
    this->price = new_price;
}
std::ostream& operator << (std::ostream& out, const Dish& dish) {
    out << std::left << ' ' << std::setw(18) << dish.getTile()
        << std::left << ' ' << std::setw(8) << dish.getWeight()
        << std::left << ' ' << std::setw(8) << dish.getPrice()
        << std::endl;

    return out;
}