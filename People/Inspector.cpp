#include "Inspector.h"

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization) :
        Human(first_name, second_name, last_name, organization, "inspector")
{}

Dish* Inspector::chooseDish(const Menu& menu)
{
    std::cout << "Choose dish from the list (enter number):\n";

    int i = 1;

    std::cout << std::string(50, '\n');

    for (Dish* dish : menu.getMenu()) {
        std::cout << i++ << ". " << *dish;
    }

    Dish* dish;
    int chosen;
    std::cin >> chosen;

    try {
        dish = menu.getDish(chosen - 1);
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
    return 0;
}