#include "Seller.h"

#include <iostream>

Seller::Seller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu) :
        Human(first_name, second_name, last_name, organization, "seller"), menu(menu)
{}

void Seller::getMenu()
{
    std::cout << std::string(50, '\n') << menu;

    std::cout << "For continue please press any key...";
    getchar();
}

void Seller::completeBill(Visitor* visitor, Dish* dish)
{
    if (dish->getTile() == "Unknown") return;

    visitor->completeBill(dish);

    std::cout << "For continue please press any key...";
    getchar();
    std::cout << std::string(50, '\n');
}

void Seller::getBill(Visitor* visitor)
{
    std::cout << std::string(50, '\n');

    std::cout << visitor->getBill();

    std::cout << "For continue please press any key...";
    getchar();
}