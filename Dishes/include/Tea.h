#ifndef BUFFET_TEA_H
#define BUFFET_TEA_H

#include "Dish.h"

class Tea : public Dish
{
public:
    Tea(
            const std::string& title, const double& price, const double& weight,
            const std::string& grade, const std::string& weight_units = "ml"
            );
    Tea() = default;

    std::string getGrade() const;
private:
    std::string grade;

//    std::string getAmountString() const override;
//protected:
//    std::string weight_units = "ml";
};


#endif //BUFFET_TEA_H
