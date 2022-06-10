#ifndef BUFFET_VISITOR_H
#define BUFFET_VISITOR_H

#include "include/Human.h"

#include "../Dishes/include/Dish.h"
#include "../Bill.h"

class Visitor : public Human
{
public:
    Visitor(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const std::string& post, const double& own_funds
            );

    void checkOwnFunds() const;
};


#endif //BUFFET_VISITOR_H
