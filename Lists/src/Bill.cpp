#include "../include/Bill.h"

Bill::~Bill()
{
    for (auto dish : billList) {
        delete dish;
    }
}

void Bill::addDish(Dish* dish)
{
    billList.push_back(dish);
}

Dish* Bill::getDish(const int& index)
{
    return billList[index];
}

void Bill::removeDish(const int& index)
{
    billList.erase(billList.begin() + index);
}

double Bill::getTotalPrice() const
{
    double totalPrice = 0;

    for (auto dish : billList) {
        totalPrice += dish->getPrice();
    }

    return totalPrice;
}

double Bill::getTotalWeight() const
{
    double totalWeight = 0;

    for (auto dish : billList) {
        totalWeight += dish->getWeight();
    }

    return totalWeight;
}

std::vector<Dish*> Bill::getBillList() const
{
    return billList;
}

std::ostream& operator << (std::ostream& out, const Bill& totalBill) {
    out << "Total bill (title - weight - price)\n";

    int i = 1;

    for (Dish* dish : totalBill.getBillList()) {
        out << i++ << ". " << *dish;
    }

    out << "Total price is " << totalBill.getTotalPrice() << std::endl;

    return out;
}
