#include "Seller.h"

#include <iostream>
#include <unistd.h>
#include <string>

Seller::Seller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu,
        const double& own_funds, const double& cash_money) :
        Human(first_name, second_name, last_name, organization, "seller", own_funds),
        menu(menu), cash_money(cash_money)
{}

void Seller::getMenu()
{
    std::cout << std::string(50, '\n') << menu;

    std::cout << "For continue please press any key...";
    getchar();
}

void Seller::completeBill()
{
    int i = 1;

    std::cout << std::string(50, '\n')
              << "Choose dish from the list (enter number):\n";

    for (Dish* dish : menu.getMenu()) {
        std::cout << i++ << ". " << *dish;
    }

    std::cout << "Enter number: ";

    std::string response;
    int chosen;
    std::cin >> chosen;

    try {
        Dish* dish = menu.getDish(chosen - 1);

        if (currentBillIndex > bills.size() - 2) {
            bills.push_back(new Bill());
            currentBillIndex++;
        }

        bills[currentBillIndex]->addDish(dish);
        response = "Successfully added " + dish->getTile() + "\n";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    sleep(2);
    getchar();
}

void Seller::removeFromBill()
{
    if (currentBillIndex > bills.size() - 2 || bills[currentBillIndex]->getBillList().empty()) {
        std::cout << std::string(50, '\n') << "Bill list is empty\n";
        std::cout.flush();
        sleep(2);
        return;
    }

    std::cout << "Choose dish from the bill (enter number):\n";

    int i = 1;

    std::cout << std::string(50, '\n');

    for (Dish* dish : (bills[currentBillIndex ]->getBillList())) {
        std::cout << i++ << ". " << *dish;
    }

    std::string response;
    int chosen;
    std::cin >> chosen;

    if (chosen > 0 && chosen <= menu.getMenu().size()) {
        Dish* dish = bills[currentBillIndex]->getDish(chosen - 1);
        bills[currentBillIndex]->removeDish(chosen - 1);
        response = "Successfully removed " + dish->getTile() + "\n";
    } else {
        response = "Dish undefined\n";
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    sleep(2);
}

void Seller::payBill(Visitor* visitor)
{
    std::string response;

    try {
        if (bills[currentBillIndex]->getTotalPrice() == 0) {
            throw std::invalid_argument("Total bill is empty");
        }

        visitor->spendOwnFunds(bills[currentBillIndex]->getTotalPrice());
        cash_money+=bills[currentBillIndex]->getTotalPrice();

        std::cout << bills[currentBillIndex]->getTotalPrice();

        response += "Successfully paid!";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n')
              << response << "\n";

    std::cout.flush();
    sleep(2);
}


void Seller::getBill()
{
    std::cout << std::string(50, '\n');

    std::cout << *bills[currentBillIndex];

    std::cout << "For continue please press any key...";
    getchar();
}

double Seller::getCashMoney() const
{
    return cash_money;
}