#include "TotalBill.h"

TotalBill::~TotalBill()
{
    for (auto dish : billList) {
        delete dish;
    }
}

void TotalBill::addDish(Dish* dish)
{
    billList.push_back(dish);
}

void TotalBill::removeDish(int index)
{
    billList.erase(billList.begin() + index);
}

double TotalBill::getTotalPrice() const
{
    double totalPrice = 0;

    for (auto dish : billList) {
        totalPrice += dish->getPrice();
    }

    return totalPrice;
}

double TotalBill::getTotalWeight() const
{
    double totalWeight = 0;

    for (auto dish : billList) {
        totalWeight += dish->getWeight();
    }

    return totalWeight;
}

std::vector<Dish*> TotalBill::getBillList() const
{
    return billList;
}

std::ostream& operator << (std::ostream& out, const TotalBill& totalBill) {
    out << "Totalbill\n";

    for (Dish* dish : totalBill.getBillList()) {
        out << *dish;
    }

    return out;
}
