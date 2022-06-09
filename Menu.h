#ifndef BUFFET_MENU_H
#define BUFFET_MENU_H

#include "Dishes/Dish.h"

#include <vector>
#include <iostream>

class Menu
{
public:
    Menu() = default;
    ~Menu();

    std::vector<Dish*> getMenu() const;

    void addDish(Dish*);
    Dish* getDish(const int&) const;
private:
    std::vector<Dish*> menu;
};

std::ostream& operator << (std::ostream& out, const Menu& menu);

#endif //BUFFET_MENU_H
