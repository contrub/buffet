#include "Menu.h"

#include <iomanip>
#include <algorithm>

Menu::~Menu()
{
    for (auto* dish : menu) {
        delete dish;
    }

    // menu.clear();
}

std::vector<Dish*> Menu::getMenu() const
{
    return menu;
}

Dish* Menu::getDish(const int& index) const
{
    if (index < 0 || index > menu.size() - 1) {
        throw std::invalid_argument("Error...\nDish not found");
    }

    return menu[index];
}

void Menu::addDish(Dish* dish)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    };

    menu.push_back(dish);
}

void Menu::removeDish(Dish* dish)
{
    if (dish == nullptr) {
        throw std::invalid_argument("Error...\nDish is empty");
    }

    auto it = std::find(menu.begin(), menu.end(), dish);

    if (it == menu.end()) {
        throw std::invalid_argument("Dish not found");
    }

    delete dish;
    menu.erase(it);
}

std::ostream& operator << (std::ostream& out, const Menu& menu) {
    out << std::endl << '+' << std::string(42, '=') << '+' << std::endl
              << std::left << '|' << std::string(5, ' ') << std::setw(10) << "Title" << '|'
              << std::left << std::string(2, ' ') << std::setw(8) << "Weight" << '|'
              << std::left << std::string(5, ' ') << std::setw(10) << "Price" << '|'
              << std::endl << '+' << std::string(42, '=') << '+' << std::endl;

    for (Dish* dish : menu.getMenu()) {
        out << *dish;
    }

    return out;
}
