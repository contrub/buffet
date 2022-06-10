#include "Inspector.h"

#include <unistd.h>

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization) :
        Human(first_name, second_name, last_name, organization, "inspector", 0)
{}

void Inspector::checkPayment(Seller* seller)
{
    double finishCashMoney = seller->cash_money;
    double startCashMoney = getCashMoney();

    double totalBillPrice = 0;

    for (Bill* bill : seller->bills) {
        totalBillPrice += bill->getTotalPrice();
    }

    std::string response;

    if (totalBillPrice == 0) return;

    std::cout << std::string(50, '\n')
              << "Checking ...\n";
    std::cout.flush();
    sleep(3);

    if (startCashMoney + totalBillPrice != finishCashMoney) {
        seller->spendOwnFunds(finishCashMoney - totalBillPrice);
        response = "Taken money back";
    } else {
        response = "Successfully check!";
    }

    std::cout << response;
    std::cout.flush();
    sleep(2);
}

void Inspector::commitCashMoney(const double& money)
{
    this->cash_money = money;
}

double Inspector::getCashMoney() const
{
    return cash_money;
}
