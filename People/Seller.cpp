#include "Seller.h"

Seller::Seller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization) :
        Human(first_name, second_name, last_name, organization, "seller")
{}