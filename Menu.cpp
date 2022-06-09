#include "Menu.h"

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
        throw std::invalid_argument("Error..\nIndex out of range ...");
    }

    return getMenu()[chosen];
}

std::ostream& operator << (std::ostream& out, const Menu& menu) {
    out << "Menu (title - weight - price)\n";

    for (Dish* dish : menu.getMenu()) {
        out << *dish;
    }

    return out;
}
