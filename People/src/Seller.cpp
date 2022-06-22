#include "Menu.h"
#include "Seller.h"
#include "Bill.h"

#include <iostream>
#include <unistd.h>
#include <string>
#include <iomanip>

Seller::Seller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu, const double& own_funds) :
        Human(first_name, second_name, last_name, organization, "seller", own_funds), menu(menu)
{}

Seller::~Seller()
{
    for (auto bill : bills) {
        delete bill;
    }
}

void Seller::greetVisitor(Visitor* visitor)
{
    std::string first_name = visitor->getFullName().first_name;
    std::string last_name = visitor->getFullName().last_name;

    std::cout << std::string(50, '\n')
              << "Welcome, " << first_name << " " << last_name << " !";

    sleep(3);
}

void Seller::sayGoodBye(Visitor *visitor)
{
    std::string first_name = visitor->getFullName().first_name;
    std::string last_name = visitor->getFullName().last_name;

    std::cout << std::string(50, '\n')
              << "Good bye, " << first_name << " " << last_name << "\n"
              << "Come again later !";

    sleep(3);
}

void Seller::informMenu()
{
    std::cout << std::string(50, '\n') << menu;

    std::cout << "For continue please press any key...";
    getchar();
}

void Seller::informBill()
{
    std::cout << std::string(50, '\n');

    if (bills[current_bill_number - 1]->getTotalPrice() == 0) {
        std::cout << "Bill is empty\n";
    } else {
        std::cout << *bills[current_bill_number - 1]
                  << "Total price - " << bills[current_bill_number - 1]->getTotalPrice() << "\n";
    }

    std::cout << "For continue please press any key...";
    getchar();
}

void Seller::informNumberedMenu()
{
    std::cout << std::string(50, '\n') << std::endl
              << std::endl << '+' << std::string(46, '=') << '+' << std::endl
              << std::left << '|' << std::string(1, ' ') << std::setw(2) << '#' << '|'
              << std::left << std::string(7, ' ') << std::setw(12) << "Title" << '|'
              << std::left << std::string(2, ' ') << std::setw(8) << "Weight" << '|'
              << std::left << std::string(3, ' ') << std::setw(8) << "Price" << '|'
              << std::endl << '+' << std::string(46, '=') << '+' << std::endl;

    int i = 1;
    for (auto dish : menu.getMenu()) {
        std::cout << std::left << std::string(2, ' ') << std::setw(5) << i++ << *dish;
    }
}

void Seller::informNumberedBill()
{
    std::cout << std::string(50, '\n') << std::endl
              << std::endl << '+' << std::string(53, '=') << '+' << std::endl
              << std::left << '|' << std::string(2, ' ') << std::setw(2) << '#' << '|'
              << std::left << std::string(2, ' ') << std::setw(3) << 'N' << '|'
              << std::left << std::string(5, ' ') << std::setw(10) << "Title" << '|'
              << std::left << std::string(2, ' ') << std::setw(8) << "Weight" << '|'
              << std::left << std::string(5, ' ') << std::setw(10) << "Price" << '|'
              << std::endl << '+' << std::string(53, '=') << '+' << std::endl;

    int i = 1;
    for (auto dish : (bills[current_bill_number - 1 ]->getBillList())) {
        std::cout << std::left << std::string(2, ' ') << std::setw(5) << i++ << dish.second << "  " << *dish.first;
    }
}

bool Seller::isBillEmpty()
{
    if (bills[current_bill_number - 1]->getTotalPrice() == 0) return true;
    return false;
}

bool Seller::isAbleToPay(Visitor* visitor)
{
    if (bills[current_bill_number - 1]->getTotalPrice() <= visitor->getOwnFunds()) return true;
    return false;
}

void Seller::createBill()
{
    if (isBillEmpty()) return;

    bills.push_back(new Bill());
    current_bill_number++;
}

void Seller::completeBill()
{
    informNumberedMenu();

    std::cout << "Choose dish from the list (enter number)\n";

    std::string response;
    int dish_number;
    std::cin >> dish_number;

    try {
        Dish* dish = menu.getDish(dish_number - 1);

        int amount;

        std::cout << "Enter dish amount\n";

        std::cin >> amount;

        if (amount < 0) {
            throw std::invalid_argument("Error\nDishes amount cannot be less than 0");
        }

        if (amount > 1) {
            bills[current_bill_number - 1]->addDishes(dish, amount);
            response = "Successfully added " + dish->getTile()
                     + " (" + std::to_string(amount) + " pieces)\n";
        } else if (amount == 1) {
            bills[current_bill_number - 1]->addDish(dish);
            response = "Successfully added " + dish->getTile() + "\n";
        } else {
            response = "Nothing added\n";
        }
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    getchar();
    sleep(2);
}

void Seller::removeFromBill()
{
    if (isBillEmpty()) {
        std::cout << std::string(50, '\n') << "Bill list is empty\n";
        std::cout.flush();
        sleep(2);
        return;
    }

    informNumberedBill();

    std::cout << "Choose dish from the list (enter number)\n";

    std::string response;
    int chosen;
    std::cin >> chosen;

    try {
        Dish* dish = bills[current_bill_number - 1]->getDish(chosen - 1);

        int amount;

        std::cout << "Enter dish amount\n";

        std::cin >> amount;

        if (amount > 1) {
            bills[current_bill_number - 1]->removeDishes(dish, amount);
            response = "Successfully removed " + dish->getTile()
                     + " (" + std::to_string(amount) + " pieces)\n";
        } else if (amount == 1) {
            bills[current_bill_number - 1]->removeDish(dish);
            response = "Successfully removed " + dish->getTile() + "\n";
        } else {
            response = "Nothing removed\n";
        }
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n') << response;
    std::cout.flush();
    getchar();
    sleep(2);
}

void Seller::takePayment(Visitor *visitor)
{
    visitor->changeFunds(- bills[current_bill_number - 1]->getTotalPrice());
    cash_money += bills[current_bill_number - 1]->getTotalPrice();
    bills[current_bill_number - 1]->changePayStatus();
}

void Seller::payBill(Visitor* visitor)
{
    std::string response;

    try {
        if (isBillEmpty()) throw std::invalid_argument("Total bill is empty");
        if (!isAbleToPay(visitor)) throw std::invalid_argument("Payment cancelled\nInsufficient funds");

        takePayment(visitor);

        response += "Successfully paid!";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n')
              << response << "\n";

    std::cout.flush();
    sleep(3);
}

std::istream& operator >> (std::istream& is, Seller& seller) {
    is >> static_cast<Human&>(seller);
    return is;
}