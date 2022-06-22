#ifndef BUFFET_COFFEE_H
#define BUFFET_COFFEE_H

#include "Dish.h"

class Coffee : public Dish
{
public:
    Coffee(
            const std::string& title, const double& price, const double& weight,
            const double& bitterness, const std::string& weight_units = "ml"
            );
    Coffee() = default;

    double getBitterness() const;
private:
    double bitterness;

//     std::string getAmountString() const override;
//protected:
//    std::string weight_units = "ml";
};

#endif //BUFFET_COFFEE_H
