#ifndef BUFFET_SELLER_H
#define BUFFET_SELLER_H

#include <string>

#include "include/Human.h"
#include "Visitor.h"

#include "../Dishes/include/Dish.h"
#include "../Menu.h"

class Seller : public Human
{
friend class Inspector;
public:
    Seller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const Menu& menu, const double& own_funds, const double& cash_money
            );

    void getMenu();
    void completeBill();
    void removeFromBill();
    void getBill();
    virtual void payBill(Visitor* visitor);
    double getCashMoney() const;

protected:
    int currentBillIndex = -1;
    std::vector<Bill*> bills;
    Menu menu;
    double cash_money;
};


#endif //BUFFET_SELLER_H
