#ifndef BUFFET_GREEDSELLER_H
#define BUFFET_GREEDSELLER_H

#include "Seller.h"
#include "Menu.h"

class GreedSeller : public Seller
{
public:
    GreedSeller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const Menu& menu, const double& own_funds
    );
    GreedSeller() = default;

    void payBill(Visitor* visitor) override;
    double stealMoney();
};

#endif //BUFFET_GREEDSELLER_H
