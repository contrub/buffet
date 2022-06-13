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
            std::string  organization, std::string  job_post, const double& own_funds
            );
    Human() = default;
    ~Human() = default;

    FullName getFullName() const;
    std::string getOrganization() const;
    std::string getJobPost() const;
    double getOwnFunds() const;

    void init();

    void setFirstName(const std::string& new_first_name);
    void setLastName(const std::string& new_last_name);
    void setOrganization(const std::string& new_organization);
    void setJobPost(const std::string& new_job_post);
    void setOwnFunds(const double& funds);

    void changeFunds(const double& funds);

    static bool checkInfo(const std::string& first_name, const std::string& second_name, const std::string& last_name);

    friend std::istream& operator >> (std::istream& is, Human& human);
    friend std::ostream& operator << (std::ostream& os, const Human& human);
private:
    FullName full_name;
    std::string organization;
    std::string job_post;
    double own_funds = 0;
};

#endif //BUFFET_HUMAN_H
