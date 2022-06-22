#include "InattentiveSeller.h"

#include <unistd.h>

InattentiveSeller::InattentiveSeller(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const Menu& menu, const double& own_funds) :
        Seller(first_name, second_name, last_name, organization, menu, own_funds)
{}

void InattentiveSeller::payBill(Visitor* visitor)
{
    std::string response;

    try {
        if (isBillEmpty()) throw std::invalid_argument("Total bill is empty");
        if (!isAbleToPay(visitor)) throw std::invalid_argument("Payment cancelled\nInsufficient funds");

        takePayment(visitor);
        loseMoney();

        response += "Successfully paid!";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n')
              << response << "\n";

    std::cout.flush();
    sleep(2);
}

void InattentiveSeller::loseMoney()
{
    double bill_total_price = bills[current_bill_number - 1]->getTotalPrice();
    double lost_money = ((bill_total_price / 4) * ((double)rand() / (double)RAND_MAX));

    cash_money -= lost_money;
}