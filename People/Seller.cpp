#include "Seller.h"

#include <iostream>
#include <unistd.h>

Seller::Seller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu,
        const double& own_funds, const double& cash_money) :
        Human(first_name, second_name, last_name, organization, "seller"),
        menu(menu), own_funds(own_funds), cash_money(cash_money)
{}

void Seller::getMenu()
{
    std::cout << std::string(50, '\n') << menu;

    std::cout << "For continue please press any key...";
    getchar();
}

void Seller::completeBill()
{
    std::cout << "Choose dish from the list (enter number):\n";

    int i = 1;

    std::cout << std::string(50, '\n');

    for (Dish* dish : menu.getMenu()) {
        std::cout << i++ << ". " << *dish;
    }

    std::string response;
    int chosen;
    std::cin >> chosen;

    if (chosen > 0 && chosen <= menu.getMenu().size()) {
        Dish* dish = menu.getDish(chosen - 1);
        response = "Successfully added " + dish->getTile() + "\n";
        totalBill.addDish(dish);
    } else {
        response = "Dish undefined\n";
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    sleep(2);
    getchar();
}

void Seller::removeFromBill()
{
    if (totalBill.getBillList().empty()) {
        std::cout << std::string(50, '\n') << "Bill list is empty\n";
        std::cout.flush();
        sleep(2);
        return;
    }

    std::cout << "Choose dish from the bill (enter number):\n";

    int i = 1;

    std::cout << std::string(50, '\n');

    for (Dish* dish : totalBill.getBillList()) {
        std::cout << i++ << ". " << *dish;
    }

    std::string response;
    int chosen;
    std::cin >> chosen;

    if (chosen > 0 && chosen <= menu.getMenu().size()) {
        Dish* dish = totalBill.getDish(chosen - 1);
        totalBill.removeDish(chosen - 1);
        response = "Successfully removed " + dish->getTile() + "\n";
    } else {
        response = "Dish undefined\n";
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    sleep(2);
}

void Seller::getBill()
{
    std::cout << std::string(50, '\n');

    std::cout << totalBill;

    std::cout << "For continue please press any key...";
    getchar();
}