#include "Dish.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

Dish::Dish(const std::string& title, const double& price, const double& weight) :
    title(title), price(price), weight(weight)
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

std::string Dish::getTile() const
{
    return title;
}

double Dish::getWeight() const
{
    return weight;
}

double Dish::getPrice() const
{
    return price;
}

std::string Dish::getAmountString() const
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << (int)weight;
    return stream.str() + " " + weight_units;
}

void Dish::setTitle(const std::string& new_title)
{
    this->title = new_title;
}

void Dish::setWeightUnits(const std::string &new_weight_units) {
    this->weight_units = new_weight_units;
}


void Dish::setWeight(const double& new_weight)
{
    this->weight = new_weight;
}

void Dish::setPrice(const double& new_price)
{
    this->price = new_price;
}

bool Dish::checkInfo(const std::string& title, const double& weight, const double& price)
{
    if (title.empty()) return false;
    if (weight < 0 || price < 0) return false;

    return true;
}

std::istream& operator >> (std::istream& is, Dish& dish)
{
    std::string tmp_title;
    double tmp_weight, tmp_price;

    is >> tmp_title >> tmp_weight >> tmp_price;

    if (!Dish::checkInfo(tmp_title, tmp_weight, tmp_price)) {
        throw std::invalid_argument("Dish validation error");
    }

    dish.title = tmp_title;
    dish.weight = tmp_weight;
    dish.price = tmp_price;

    return is;
}

std::ostream& operator << (std::ostream& os, const Dish& dish) {
    os << std::left << ' ' << std::setw(18) << dish.getTile()
        << std::left << ' ' << std::setw(12) << dish.getAmountString()
        << std::left << ' ' << std::setw(12) << dish.getPrice()
        << std::endl;

    return os;
}
