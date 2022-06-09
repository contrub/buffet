#include "People/Inspector.h"
#include "People/Visitor.h"
#include "People/Seller.h"

#include "Dishes/Dish.h"
#include "Dishes/Cake.h"
#include "Dishes/Pizza.h"
#include "Dishes/Salad.h"

#include "Menu.h"

#include <iostream>
#include <vector>

int get_variant(int count) {
    int variant;
    std::string s;
    getline(std::cin, s);

    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        std::cout << "Incorrect input. Try again: ";
        getline(std::cin, s);
    }

    return variant;
}
void print_menu() {
    std::cout << std::string(50, '\n');
    std::cout << "1. Print menu\n";
    std::cout << "2. Add dish\n";
    std::cout << "3. Remove dish\n";
    std::cout << "4. Pay for bill\n";
    std::cout << "5. Get complete bill\n";
    std::cout << "6. EXIT" << "\n";
}

int main() {
    Menu buffetMenu;

    buffetMenu.addDish(new Cake("Muffin", 23, 0.120));
    buffetMenu.addDish(new Cake("Cupcake", 38, 0.110));
    buffetMenu.addDish(new Cake("Mini Cupcake", 21, 0.74));
    buffetMenu.addDish(new Cake("Pound Cake", 165, 0.411));

    buffetMenu.addDish(new Pizza("Sicilian Pizza", 123, 1.23));
    buffetMenu.addDish(new Pizza("Chicago Pizza", 143, 1.04));
    buffetMenu.addDish(new Pizza("Detroit Pizza", 135, 0.907));
    buffetMenu.addDish(new Pizza("Greek Pizza", 129, 0.853));

    buffetMenu.addDish(new Salad("Caesar", 35, 0.08));
    buffetMenu.addDish(new Salad("Greek", 32, 0.105));
    buffetMenu.addDish(new Salad("Italian", 42, 0.240));
    buffetMenu.addDish(new Salad("Southwestern", 45, 0.1));

    int variant = 0;

    auto* seller = new Seller("test11", "test12", "test13", "buffet", buffetMenu);
    auto* inspector = new Inspector("test21", "test22", "test23", "buffet");
    auto* visitor = new Visitor("test31", "test32", "test33", "Office", "Office Worker");

    do
    {
        print_menu();
        variant = get_variant(6);

        switch (variant) {
            case 1:
                seller->getMenu();
                break;
            case 2:
                // seller->completeBill(visitor, inspector->chooseDish(buffetMenu));
                break;
            case 3:
                // seller->removeFromBill(visitor, inspector->chooseDish(buffetMenu));
                break;
            case 4:
                // seller->payBill(visitor, inspector->checkPayment(visitor));
                break;
            case 5:
                seller->getBill(visitor);
                break;
            default:
                break;
        }

    } while (variant != 6);

    return 0;
}
