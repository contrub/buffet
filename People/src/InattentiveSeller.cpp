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
        if (bills[current_bill - 1]->getTotalPrice() == 0) {
            throw std::invalid_argument("Total bill is empty");
        }

        if (bills[current_bill - 1]->getTotalPrice() > visitor->getOwnFunds()) {
            throw std::invalid_argument("Payment cancelled\nInsufficient funds");
        }

        visitor->changeFunds(bills[current_bill - 1]->getTotalPrice());

        double bill_price = bills[current_bill - 1]->getTotalPrice();
        double lost_money = loseMoney(bill_price);

        cash_money += bills[current_bill - 1]->getTotalPrice() - lost_money;

        bills[current_bill - 1]->changePayStatus();
        response += "Successfully paid!";
    } catch (const std::exception& ex) {
        response = ex.what();
    }

    std::cout << std::string(50, '\n')
              << response << "\n";

    std::cout.flush();
    sleep(2);
}

double InattentiveSeller::loseMoney(const double& money)
{
    srand(time(nullptr));
    return ((money / 4) * ((double)rand() / (double)RAND_MAX));
}