#include "GreedSeller.h"
#include "Seller.h"

GreedSeller::GreedSeller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const Menu& menu,
        const double& own_funds, const double& cash_money) :
        Seller(first_name, second_name, last_name, "seller", menu, own_funds, cash_money)
{}