#ifndef BUFFET_CAKE_H
#define BUFFET_CAKE_H

#include "Dish.h"

class Cake : public Dish
{
public:
    Cake(
            const std::string& title, const double& price, const double& weight,
            const std::string& appearance_form, const std::string& weight_units = "g"
            );
    Cake() = default;

    std::string getAppearanceForm() const;
private:
    std::string appearance_form;

//    std::string getAmountString() const override;
//protected:
//    std::string weight_units = "g";
};


#endif //BUFFET_CAKE_H
