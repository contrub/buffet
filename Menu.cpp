#include "Menu.h"

Menu::~Menu()
{
    for (auto dish : menu) {
        delete dish;
    }
}

std::vector<Dish*> Menu::getMenu() const
{
    return menu;
}


void Menu::addDish(Dish* dish)
{
    menu.push_back(dish);
}

std::ostream& operator << (std::ostream& out, const Menu& menu) {
    out << "Menu\n";

    for (Dish* dish : menu.getMenu()) {
        out << *dish;
    }

    return out;
}
