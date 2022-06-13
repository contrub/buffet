#ifndef BUFFET_VISITOR_H
#define BUFFET_VISITOR_H

#include "Human.h"
#include "Dish.h"
#include "Bill.h"

class Visitor : public Human
{
public:
    Visitor(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const std::string& job_post, const double& own_funds
            );
    Visitor() = default;

    void checkOwnFunds() const;

    friend std::istream& operator>>(std::istream& is, Visitor& visitor);
};


#endif //BUFFET_VISITOR_H
