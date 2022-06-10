#ifndef BUFFET_INSPECTOR_H
#define BUFFET_INSPECTOR_H

#include <string>

#include "Human.h"
#include "../Visitor.h"
#include "../Seller.h"

#include "../../Dishes/include/Dish.h"

#include "../../Menu.h"

class Inspector : public Human
{
public:
    Inspector(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization
            );

    void commitCashMoney(const double& money);
    double getCashMoney() const;

    void checkPayment(Seller* seller);
private:
    double cash_money;
};


#endif //BUFFET_INSPECTOR_H
