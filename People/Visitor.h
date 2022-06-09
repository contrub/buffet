#ifndef BUFFET_VISITOR_H
#define BUFFET_VISITOR_H

#include "Human.h"

#include "../Dishes/Dish.h"
#include "../Bill.h"

class Visitor : public Human
{
public:
    Visitor(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const std::string& post
            );

    Bill getBill() const;

    void completeBill(Dish* dish);
private:
    Bill totalBill;
};


#endif //BUFFET_VISITOR_H
