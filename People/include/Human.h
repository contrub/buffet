#ifndef BUFFET_HUMAN_H
#define BUFFET_HUMAN_H

#include <string>

struct FullName {
    std::string first_name;
    std::string second_name;
    std::string last_name;
};


class Human
{
public:
    Human(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const std::string& post, const double& own_funds
            );

    double getOwnFunds() const;
    void spendOwnFunds(const double& funds);
protected:
    FullName fullName;
    std::string organization;
    std::string post;
    double own_funds;
};


#endif //BUFFET_HUMAN_H
