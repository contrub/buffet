#ifndef BUFFET_INSPECTOR_H
#define BUFFET_INSPECTOR_H

#include "Human.h"
#include "Visitor.h"
#include "Seller.h"
#include "Dish.h"
#include "Menu.h"

#include <string>

class Inspector : public Human
{
public:
    Inspector(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const double& own_funds
            );
    Inspector() = default;

    double calculateTotalPrice(Seller* seller);

    bool isWorthToCheck(Seller* seller);
    bool isCashConverge(Seller* seller);

    void informSeller(Seller* seller);
    void informVerifiedBills(Seller* seller);
    void requestVerifiedBills(Seller* seller);
    void informPayPenalty(const double& penalty);

    void commitCash(Seller* seller);
    void payPenalty(Seller* seller);
    void checkPayment(Seller* seller);
private:
    double seller_cash = 0;
};


#endif //BUFFET_INSPECTOR_H
