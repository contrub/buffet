#ifndef BUFFET_DISH_H
#define BUFFET_DISH_H

#include <string>

class Dish
{
public:
    Dish(const std::string& title, const double& price, const double& weight);
    Dish() = default;
    virtual ~Dish() = default;

    std::string getTile() const;
    double getWeight() const;
    double getPrice() const;

    virtual std::string getAmountString() const;

    void setTitle(const std::string& new_title);
    void setWeight(const double& new_weight);
    void setPrice(const double& new_price);

    static bool checkInfo(const std::string& title, const double& weight, const double& price);

    friend std::istream& operator >> (std::istream& is, Dish& dish);
    friend std::ostream& operator << (std::ostream& os, const Dish& dish);
private:
    std::string title;
    std::string weight_units = "pcs";
    double weight = 0;
    double price = 0;
};

#endif //BUFFET_DISH_H
