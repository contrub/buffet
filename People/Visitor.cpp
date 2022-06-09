#include "Visitor.h"

Visitor::Visitor(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const std::string& post
) :
        Human(first_name, second_name, last_name, organization, post)
{}

Bill Visitor::getBill() const
{
    return totalBill;
}

void Visitor::completeBill(Dish* dish)
{
    totalBill.addDish(dish);
}