#ifndef BUFFET_GREEDSELLER_H
#define BUFFET_GREEDSELLER_H

#include "Seller.h"

class GreedSeller : public Seller
{
public:
    GreedSeller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const Menu& menu, const double& own_funds, const double& cash_money
    );
};

#endif //BUFFET_GREEDSELLER_H
