#ifndef BUFFET_SELLER_H
#define BUFFET_SELLER_H

#include <string>

#include "Human.h"
#include "Visitor.h"

#include "../Dishes/Dish.h"
#include "../Menu.h"

class Seller : public Human
{
public:
    Seller(const std::string&, const std::string&, const std::string&, const std::string&, const Menu& menu);

    void getMenu();
    void completeBill(Visitor*, Dish*);
    void getBill(Visitor*);
private:
    Menu menu;
};


#endif //BUFFET_SELLER_H
