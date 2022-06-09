#include "Inspector.h"

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization) :
        Human(first_name, second_name, last_name, organization, "inspector")
{}

Dish* Inspector::chooseDish(const Menu& menu)
{
    std::cout << "Choose dish from the list(enter number):\n";

    int i = 1;

    for (Dish* dish : menu.getMenu()) {
        std::cout << i++ << ". " << *dish;
    }

    int chosen;
    std::cin >> chosen;

    Dish* dish;

    try {
        dish = menu.getDish(chosen);
        std::cout << "Successfully added - " << *dish << std::endl;
    } catch (std::exception& ex) {
        dish = new Dish();
        std::cout << ex.what();
    }

    return dish;
}

double Inspector::checkPayment(Visitor* visitor)
{
    visitor;
}