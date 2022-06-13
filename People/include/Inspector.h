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
            const std::string& organization
            );

    void checkPayment(Seller* seller);
};


#endif //BUFFET_INSPECTOR_H
