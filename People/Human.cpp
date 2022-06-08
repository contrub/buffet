#include "Human.h"

#include <stdexcept>

Human::Human(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        const std::string& organization, const std::string& post
        ) :
        fullName{ first_name, second_name, last_name }, organization(organization), post(post)
{
    if (first_name.empty()) {
        throw std::invalid_argument("Error..\nFirst name cannot be empty");
    }

    if (second_name.empty()) {
        throw std::invalid_argument("Error..\nSecond name cannot be empty");
    }

    if (last_name.empty()) {
        throw std::invalid_argument("Error..\nLast name cannot be empty");
    }

    if (organization.empty()) {
        throw std::invalid_argument("Error..\nOrganization title cannot be empty");
    }

    if (post.empty()) {
        throw std::invalid_argument("Error..\nPost title cannot be empty");
    }
}