#ifndef BUFFET_DISH_H
#define BUFFET_DISH_H

#include <string>

class Dish
{
public:
    Dish(const std::string& title, const double& price, const double& weight);

    std::string getTile() const;
    double getWeight() const;
    double getPrice() const;

    void setTitle(const std::string& new_title);
    void setWeight(const double& new_weight);
    void setPrice(const double& new_price);
private:
    std::string title = "Unknown";
    double weight;
    double price;
};

std::ostream& operator << (std::ostream& out, const Dish& dish);

#endif //BUFFET_DISH_H
