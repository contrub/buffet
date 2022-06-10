#include "GreedSeller.h"
#include "Seller.h"

#include <unistd.h>

GreedSeller::GreedSeller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu,
        const double& own_funds, const double& cash_money) :
        Seller(first_name, second_name, last_name, organization, menu, own_funds, cash_money)
{}

void GreedSeller::payBill(Visitor* visitor)
{
    std::string response;

    try {
        if (bills[currentBillIndex]->getTotalPrice() == 0) {
            throw std::invalid_argument("Total bill is empty");
        }

        visitor->spendOwnFunds(bills[currentBillIndex]->getTotalPrice());
        cash_money += bills[currentBillIndex]->getTotalPrice() * 0.95;
        own_funds += bills[currentBillIndex]->getTotalPrice() * 0.5;

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