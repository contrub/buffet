#include "Visitor.h"

Visitor::Visitor(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const std::string& post, const double& own_funds
) :
        Human(first_name, second_name, last_name, organization, post, own_funds)
{}

void Visitor::informOwnFunds()
{
    std::cout << std::string(50, '\n')
              << "My funds - " << getOwnFunds() << "\n";

    std::cout << "For continue please press any key...";
    getchar();
}

std::istream& operator>>(std::istream& is, Visitor& visitor) {
    is >> static_cast<Human&>(visitor);

    return is;
}