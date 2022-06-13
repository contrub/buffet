#ifndef BUFFET_BILL_H
#define BUFFET_BILL_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

class Bill
{
public:
    Bill() = default;
    ~Bill();

    std::map<Dish*, int> getBillList() const;
    Dish* getDish(const int& index);
    bool getPayStatus() const;
    double getTotalPrice() const;

    void addDish(Dish* dish);
    void addDishes(Dish* dish, const int& amount);
    void removeDish(Dish* dish);
    void removeDishes(Dish* dish, const int& amount);

    void changePayStatus();

    friend std::ostream& operator << (std::ostream& out, const Bill& bill);
private:
    std::map<Dish*, int> bill_list;
    bool is_paid = false;
 };


#endif //BUFFET_BILL_H
