#include "Dish.h"
#include "Bill.h"

#include <iostream>
#include <iomanip>
#include <map>

std::map<Dish*, int> Bill::getBillList() const
{
    return bill_list;
}

Dish* Bill::getDish(const int& index) const
{
    auto it = bill_list.begin();
    std::advance(it, index);

    if (it == bill_list.end()) {
        throw std::invalid_argument("Error...\nDish not found\n");
    }

    return it->first;
}

int Bill::getDishAmount(const int& index) const
{
    auto it = bill_list.begin();
    std::advance(it, index);

    if (it == bill_list.end()) {
        throw std::invalid_argument("Error...\nDish not found\n");
    }

    return it->second;
}

bool Bill::getPayStatus() const
{
    return is_paid;
}

double Bill::getTotalPrice() const
{
    double total_price = 0;

    for (auto const& dish : bill_list) {
        total_price += dish.first->getPrice() * dish.second;
    }

    return total_price;
}

void Bill::addDish(Dish* dish)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    }

    if (bill_list.find(dish) == bill_list.end()) {
        bill_list.insert({dish, 1});
    } else {
        bill_list[dish]++;
    }
}

void Bill::addDishes(Dish* dish, const int& amount)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    }

    if (bill_list.find(dish) == bill_list.end()) {
        bill_list.insert({dish, amount});
    } else {
        bill_list[dish] += amount;
    }
}

void Bill::removeDish(Dish* dish)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    }

    auto it = bill_list.find(dish);

    if (it == bill_list.end()) {
        throw std::invalid_argument("Dish not found");
    }

    if (it->second > 1) {
        it->second--;
    } else {
        bill_list.erase(it);
    }
}

void Bill::removeDishes(Dish* dish, const int& amount)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    }

    auto it = bill_list.find(dish);

    if (it == bill_list.end()) {
        throw std::invalid_argument("Dish not found");
    }

    if (it->second < amount) {
        throw std::invalid_argument("Error..\nNumber of dishes less than requested amount");
    }

    if (it->second == amount) {
        bill_list.erase(it);
    } else {
        bill_list[dish] -= amount ;
    }
}

void Bill::changePayStatus()
{
    this->is_paid = !is_paid;
}

std::ostream& operator << (std::ostream& out, const Bill& bill) {
    out << std::endl << '+' << std::string(48, '=') << '+' << std::endl
        << std::left << '|' << std::string(1, ' ') << std::setw(2) << 'N' << '|'
        << std::left << std::string(7, ' ') << std::setw(12) << "Title" << '|'
        << std::left << std::string(2, ' ') << std::setw(8) << "Weight" << '|'
        << std::left << std::string(4, ' ') << std::setw(9) << "Price" << '|'
        << std::endl << '+' << std::string(48, '=') << '+' << std::endl;

    for (auto dish : bill.getBillList()) {
        out << std::left << std::string(2, ' ') << std::setw(5) << dish.second << *dish.first;
    }

    return out;
}
