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

    void payBill(Visitor* visitor) override;
    double loseMoney(const double& money);
};

#endif //BUFFET_INATTENTIVESELLER_H
