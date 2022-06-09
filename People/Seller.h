#ifndef BUFFET_SELLER_H
#define BUFFET_SELLER_H

#include <string>

#include "Human.h"
#include "Visitor.h"

#include "../Dishes/Dish.h"
#include "../Menu.h"

class Seller : public Human
{
public:
    Seller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& post, const Menu& menu,
            const double& own_funds, const double& cash_money
            );

    void getMenu();
    void completeBill();
    void removeFromBill();
    void getBill();

protected:
    Bill totalBill;
    Menu menu;
    double own_funds;
    double cash_money;
};


#endif //BUFFET_SELLER_H
