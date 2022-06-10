#include "../../Menu.h"

#include <iomanip>

Menu::~Menu()
{
//    for (Dish* dish : menu) {
//        delete dish;
//    }
}

std::vector<Dish*> Menu::getMenu() const
{
    return menu;
}


void Menu::addDish(Dish* dish)
{
    menu.push_back(dish);
}

Dish* Menu::getDish(const int& chosen) const
{
    if (chosen < 0 || chosen > getMenu().size()) {
        throw std::invalid_argument("Dish not found");
    }

    return menu[chosen];
}

std::ostream& operator << (std::ostream& out, const Menu& menu) {
    out << std::left << '|' << std::string(6, ' ') << std::setw(12) << "Title" << '|'
              << std::left << std::setw(8) << "Weight" << '|'
              << std::left << std::setw(8) << "Price" << '|'
              << std::endl << '+' << std::string(38, '=') << '+' << std::endl;

    for (Dish* dish : menu.getMenu()) {
        out << *dish;
    }

    return out;
}
