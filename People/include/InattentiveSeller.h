#ifndef BUFFET_INATTENTIVESELLER_H
#define BUFFET_INATTENTIVESELLER_H

#include "Seller.h"

class InattentiveSeller : public Seller
{
public:
    InattentiveSeller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const Menu& menu, const double& own_funds
    );
    InattentiveSeller() = default;

    void payBill(Visitor* visitor) override;
    void loseMoney();
};

#endif //BUFFET_INATTENTIVESELLER_H
