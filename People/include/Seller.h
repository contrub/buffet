#ifndef BUFFET_SELLER_H
#define BUFFET_SELLER_H

#include "Human.h"
#include "Visitor.h"
#include "Menu.h"
#include "Bill.h"

#include <string>

class Seller : public Human
{
friend class Inspector;
public:
    Seller(
            const std::string& first_name, const std::string& second_name, const std::string& last_name,
            const std::string& organization, const Menu& menu, const double& own_funds
            );
    Seller() = default;
    ~Seller();

    void greetVisitor(Visitor* visitor);
    void sayGoodBye(Visitor* visitor);

    void informMenu();
    void informBill();

    void createBill();
    void completeBill();
    void removeFromBill();
    virtual void payBill(Visitor* visitor);

    friend std::istream& operator >> (std::istream& is, Human& human);
private:
    Menu menu;
protected:
    double cash_money = 0;
    std::vector<Bill*> bills;
    int current_bill_number = 0;
};


#endif //BUFFET_SELLER_H
