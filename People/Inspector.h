#ifndef BUFFET_INSPECTOR_H
#define BUFFET_INSPECTOR_H

#include <string>

#include "Human.h"
#include "Visitor.h"

#include "../Dishes/Dish.h"

#include "../Menu.h"

class Inspector : public Human
{
public:
    Inspector(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization
            );

    Dish* chooseDish(const Menu&);

    double checkPayment(Visitor*);
};


#endif //BUFFET_INSPECTOR_H
