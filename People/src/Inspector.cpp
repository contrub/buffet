#include "Inspector.h"

#include <unistd.h>

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization) :
        Human(first_name, second_name, last_name, organization, "inspector", 0)
{}

void Inspector::checkPayment(Seller* seller)
{
    if (seller->bills[seller->current_bill - 1]->getTotalPrice() == 0) return;
    if (!seller->bills[seller->current_bill - 1]->getPayStatus()) return;

    double current_cash = seller->cash_money;
    double excepted_cash = 0;

    for (const auto& bill : seller->bills) {
        excepted_cash += bill->getTotalPrice();
    }

    std::string response;

    if (excepted_cash == 0) return;

    std::cout << std::string(50, '\n')
              << "Seller's cash (" << seller->getFullName().first_name << " " << seller->getFullName().last_name << ") verification ...\n";
    std::cout.flush();
    sleep(3);

    if (current_cash != excepted_cash) {
        seller->changeFunds(-(excepted_cash - current_cash));
        response = "Taken money back (" + std::to_string(excepted_cash - current_cash) + ")";
    } else {
        response = "Successfully verification!";
    }

    seller->createBill();

    std::cout << response;
    std::cout.flush();
    sleep(3);
}
