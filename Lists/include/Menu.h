#ifndef BUFFET_MENU_H
#define BUFFET_MENU_H

#include "Dish.h"

#include <vector>
#include <iostream>

class Menu
{
public:
    Menu() = default;
    ~Menu();

    std::vector<Dish*> getMenu() const;

    Dish* getDish(const int& index) const;
    void addDish(Dish*);
    void removeDish(Dish* dish);

    friend std::ostream& operator << (std::ostream& out, const Menu& menu);
private:
    std::vector<Dish*> menu;
};

#endif //BUFFET_MENU_H
