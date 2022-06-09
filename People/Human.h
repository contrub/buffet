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
            const std::string& organization, const std::string& post
            );
protected:
    FullName fullName;
    std::string organization;
    std::string post;
};


#endif //BUFFET_HUMAN_H
