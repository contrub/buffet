#include "Human.h"

#include <stdexcept>
#include <iostream>
#include <utility>

Human::Human(
        const std::string& first_name, const std::string& second_name, const std::string& last_name,
        std::string organization, std::string job_post, const double& own_funds
        ) :
        full_name{ first_name, second_name, last_name }, organization(std::move(organization)), job_post(std::move(job_post)), own_funds(own_funds)
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
}

FullName Human::getFullName() const
{
    return full_name;
}

std::string Human::getOrganization() const
{
    return organization;
}

std::string Human::getJobPost() const
{
    return job_post;
}

double Human::getOwnFunds() const
{
    return own_funds;
}

void Human::init()
{
    std::string tmp_first_name, tmp_second_name, tmp_last_name, tmp_job_post, tmp_organization;
    double tmp_own_funds;
    std::cout << "Input first name\n";
    std::getline(std::cin, tmp_first_name);

    std::cout << "Input second name\n";
    std::getline(std::cin, tmp_second_name);

    std::cout << "Input last name\n";
    std::getline(std::cin, tmp_last_name);

    while(!(Human::checkInfo(tmp_first_name, tmp_second_name, tmp_last_name))) {
        std::cout << "First name & second name & last name cannot be empty!\n";
        std::cout << "Input first name\n";
        std::getline(std::cin, tmp_first_name);

        std::cout << "Input second name\n";
        std::getline(std::cin, tmp_second_name);

        std::cout << "Input last name\n";
        std::getline(std::cin, tmp_last_name);
    }

    std::cout << "Input organization\n";
    std::getline(std::cin, tmp_organization);

    std::cout << "Input job post\n";
    std::getline(std::cin, tmp_job_post);

    std::cout << "Input own funds\n";
    std::cin >> tmp_own_funds;

    full_name = {tmp_first_name, tmp_second_name, tmp_last_name};
    job_post = tmp_job_post;
    organization = tmp_organization;
    own_funds = tmp_own_funds;
}

void Human::setFirstName(const std::string& new_first_name)
{
    this->full_name.first_name = new_first_name;
}

void Human::setLastName(const std::string& new_last_name)
{
    this->full_name.last_name = new_last_name;
}

void Human::setOrganization(const std::string& new_organization)
{
    this->organization = new_organization;
}

void Human::setJobPost(const std::string& new_job_post)
{
    this->job_post = new_job_post;
}

void Human::setOwnFunds(const double& funds)
{
    this->own_funds = funds;
};

void Human::changeFunds(const double& funds)
{
    own_funds += funds;
}

bool Human::checkInfo(const std::string& first_name, const std::string& second_name, const std::string& last_name)
{
    if (first_name.empty() || second_name.empty() || last_name.empty()) {
        return false;
    }

    return true;
}

std::istream& operator >> (std::istream& is, Human& human)
{
    std::string tmp_first_name, tmp_second_name, tmp_last_name, tmp_job_post, tmp_organization;
    double own_funds;

    is >> tmp_first_name >> tmp_second_name >> tmp_last_name
       >> tmp_organization >> tmp_job_post >> own_funds;

    if (!Human::checkInfo(tmp_first_name, tmp_second_name, tmp_last_name)) {
        throw std::invalid_argument("Human validation error");
    }

    human.full_name = {tmp_first_name, tmp_second_name, tmp_last_name};
    human.organization = tmp_organization;
    human.job_post = tmp_job_post;
    human.own_funds = own_funds;

    return is;
}

std::ostream& operator << (std::ostream& os, const Human& human)
{
    FullName full_name = human.getFullName();

    os << "Full name - " << full_name.first_name << " " << full_name.second_name << " " << full_name.last_name << std::endl
       << "Organization - " << human.getOrganization() << std::endl
       << "Post - " << human.getOrganization() << std::endl
       << "Founds - " << human.getOwnFunds() << std::endl;

    return os;
}