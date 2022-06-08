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

int main() {
    Menu buffetMenu;

    buffetMenu.addDish(new Cake("Muffin", 23, 0.120));
    buffetMenu.addDish(new Cake("Cupcake", 38, 0.110));
    buffetMenu.addDish(new Cake("Mini Cupcake", 21, 0.74));
    buffetMenu.addDish(new Cake("Pound Cake", 165, 0.411));

    buffetMenu.addDish(new Pizza("Muffin", 23, 0.120));
    buffetMenu.addDish(new Pizza("Muffin", 23, 0.120));
    buffetMenu.addDish(new Pizza("Muffin", 23, 0.120));
    buffetMenu.addDish(new Pizza("Muffin", 23, 0.120));

    buffetMenu.addDish(new Salad("Muffin", 23, 0.120));
    buffetMenu.addDish(new Salad("Muffin", 23, 0.120));
    buffetMenu.addDish(new Salad("Muffin", 23, 0.120));
    buffetMenu.addDish(new Salad("Muffin", 23, 0.120));


    std::cout << buffetMenu << std::endl;
    return 0;
}
