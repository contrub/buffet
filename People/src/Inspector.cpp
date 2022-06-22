#include "Inspector.h"

#include <unistd.h>
#include <iostream>

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const double& own_funds) :
        Human(first_name, second_name, last_name, organization, "inspector", own_funds)
{}

double Inspector::calculateTotalPrice(Seller *seller)
{
    double total_price = 0;

    for (const auto& bill : seller->bills) {
        total_price += bill->getTotalPrice();
    }

    return total_price;
}

bool Inspector::isWorthToCheck(Seller *seller)
{
    // if (!seller->cash_money) return false;
    if (seller->bills[seller->current_bill_number - 1]->getTotalPrice() == 0) return false;
    else if (!seller->bills[seller->current_bill_number - 1]->getPayStatus()) return false;

    return true;
}

bool Inspector::isCashConverge(Seller *seller)
{
    double current_cash = seller->cash_money;
    double excepted_cash = calculateTotalPrice(seller);

    if (current_cash != excepted_cash) return false;

    return true;
}

void Inspector::informSeller(Seller *seller)
{
    std::cout << std::string(50, '\n')
              << "Seller's cash (" << seller->getFullName().first_name << " " << seller->getFullName().last_name << ") verification ...\n";
    std::cout.flush();
    sleep(3);
}

void Inspector::informVerifiedBills(Seller *seller)
{
    double total_bills_price = 0;
    std::stringstream stream;
    int i = 0;

    for (auto bill: seller->bills) {
        std::cout << "Bill #" << ++i << *bill
                  << "\nTotal bill price - " << bill->getTotalPrice() << std::string(2, '\n');
        total_bills_price += bill->getTotalPrice();
    }

    stream << std::fixed << std::setprecision(2) << (total_bills_price);
    std::cout << "Total bills price - " << stream.str() << std::endl;
}

void Inspector::requestVerifiedBills(Seller *seller)
{
    int display_response;

    std::cout << "Display verified bills ? (1 - Yes, 2 - No)\n";
    std::cin >> display_response;
    std::cin.ignore(1000,'\n');

    switch (display_response) {
        case 1:
            informVerifiedBills(seller);
            std::cout << "For continue please press any key...";
            getchar();
            break;
        case 2:
            std::cout << "Verified bills view skipped ...\n";
            std::cout.flush();
            sleep(3);
            break;
        default:
            std::cout << "Error choice ...\n";
            std::cout.flush();
            sleep(3);
            break;
    }
}

void Inspector::informPayPenalty(const double& penalty)
{
    std::stringstream stream;

    stream << std::fixed << std::setprecision(2) << penalty;
    std::cout << "Taken money back (" + stream.str() + ")\n";
}

void Inspector::commitCash(Seller* seller)
{
    this->seller_cash = seller->cash_money;
}

void Inspector::payPenalty(Seller *seller)
{
    double current_cash = seller->cash_money;
    double excepted_cash = calculateTotalPrice(seller);
    double penalty = excepted_cash - current_cash;

    seller->changeFunds(-(penalty));
    informPayPenalty(penalty);
}

void Inspector::checkPayment(Seller* seller)
{
    if (!isWorthToCheck(seller)) return;

    informSeller(seller);

    if (!isCashConverge(seller)) {
        payPenalty(seller);
    }

    requestVerifiedBills(seller);
}