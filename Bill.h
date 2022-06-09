#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

#include "Dishes/Dish.h"

class Bill
{
public:
    Bill() = default;
    ~Bill();

    void addDish(Dish* dish);
    void removeDish(int index);

    double getTotalWeight() const;
    double getTotalPrice() const;
    std::vector<Dish*> getBillList() const;
private:
    std::vector<Dish*> billList;
};

std::ostream& operator << (std::ostream& out, const Bill& totalBill);

#endif //UNTITLED_MENU_H
