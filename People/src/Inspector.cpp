#include "Inspector.h"

#include <unistd.h>

Inspector::Inspector(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const double& own_funds) :
        Human(first_name, second_name, last_name, organization, "inspector", own_funds)
{}

void Inspector::commitCash(Seller* seller)
{
    this->seller_cash = seller->cash_money;
}

void Inspector::checkPayment(Seller* seller)
{
    if (seller->bills[seller->current_bill_number - 1]->getTotalPrice() == 0) return;
    if (!seller->bills[seller->current_bill_number - 1]->getPayStatus()) return;

    double current_cash = seller->cash_money;
    double excepted_cash = seller_cash;

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

        std::stringstream stream1;
        stream1 << std::fixed << std::setprecision(2) << (excepted_cash - current_cash);

        response = "Taken money back (" + stream1.str() + ")\n";
    } else {
        response = "Successfully verification!\n";
    }

    char display_response;

    std::cout << response << "Display verified bills ? (y/n)\n";
    std::cin >> display_response;

    double total_bills_price = 0;
    int i = 0;

    for (auto bill: seller->bills) {
        total_bills_price += bill->getTotalPrice();
    }
    std::stringstream stream2;
    stream2 << std::fixed << std::setprecision(2) << (total_bills_price);

    switch (display_response) {
        case 'y':
            for (auto bill: seller->bills) {
                std::cout << "Bill #" << ++i << *bill
                          << "\nTotal bill price - " << bill->getTotalPrice() << std::string(2, '\n');
                total_bills_price += bill->getTotalPrice();
            }

            response = "Total bills price - " + stream2.str() + "\n";

            seller->createBill();

            response += "For continue please press any key...";
            std::cout << response;
            getchar();

            break;
        case 'n':
            response = "Verified bills view skipped ...\n";

            seller->createBill();

            response += "For continue please press any key...";
            std::cout << response;
            getchar();

            break;
        default:
            response = "Error choice ...\n";

            seller->createBill();

            std::cout << response;
            std::cout.flush();
            sleep(3);
            break;
    }

    getchar();
}
