#include "GreedSeller.h"

#include <unistd.h>

GreedSeller::GreedSeller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu, const double& own_funds) :
        Seller(first_name, second_name, last_name, organization, menu, own_funds)
{}

void GreedSeller::payBill(Visitor* visitor)
{
    std::string response;

    try {
        if (isBillEmpty()) throw std::invalid_argument("Total bill is empty");
        if (!isAbleToPay(visitor)) throw std::invalid_argument("Payment cancelled\nInsufficient funds");

        visitor->changeFunds(- bills[current_bill_number - 1]->getTotalPrice());

        takePayment(visitor);
        stealMoney();

        response += "Successfully paid!";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n')
              << response << "\n";

    std::cout.flush();
    sleep(3);
}

void GreedSeller::stealMoney()
{
    double stolen_money = bills[current_bill_number - 1]->getTotalPrice() * 0.03;
    changeFunds(stolen_money);

    cash_money -= stolen_money;
}