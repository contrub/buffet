#include "Inspector.h"
#include "Visitor.h"
#include "Seller.h"
#include "GreedSeller.h"
#include "InattentiveSeller.h"

#include "Dish.h"
#include "Cake.h"
#include "Pizza.h"
#include "Salad.h"
#include "Cola.h"
#include "Tea.h"
#include "Coffee.h"

#include "Menu.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <algorithm>

int getVariant(const int& count)
{
    int variant;
    std::string s;
    getline(std::cin, s);

    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        std::cout << "Incorrect input. Try again: ";
        getline(std::cin, s);
    }

    return variant;
}
void displayPossibleActions()
{
    std::cout << std::string(50, '\n')
              << "1. Print menu\n"
              << "2. Add dish\n"
              << "3. Remove dish\n"
              << "4. Check own funds\n"
              << "5. Get complete bill\n"
              << "6. Pay for bill\n"
              << "7. Leave buffet" << "\n";
}

void parseMenu(const std::string& file_name, Menu& menu)
{
    std::vector<std::string> dishTypes { "Cake", "Coffee", "Cola", "Pizza", "Salad", "Tea" };
    std::ifstream file(file_name);
    std::string line;

    if (file.fail()) {
        std::cerr << "Unable to open the file " << file_name << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream lineStream(line);

        if (line.empty()) return;

        std::string cell;
        Dish* dish;
        std::string dish_type, dish_title, tmp_dish_price, tmp_dish_weight, tmp_add_field;
        double tmp_double_add_field;

        std::getline(lineStream, dish_type, ',');
        std::getline(lineStream, dish_title, ',');
        std::getline(lineStream, tmp_dish_price, ',');
        std::getline(lineStream, tmp_dish_weight, ',');
        std::getline(lineStream, tmp_add_field, ',');

        double dish_price = std::stod(tmp_dish_price);
        double dish_weight = std::stod(tmp_dish_weight);

        auto it = find(dishTypes.begin(), dishTypes.end(), dish_type);
        int index = it - dishTypes.begin();

        if (index > 0 && index < 5) {
            tmp_double_add_field = std::stod(tmp_add_field);
        }

        switch (index) {
            case 0:
                dish = new Cake(dish_title, dish_price, dish_weight, tmp_add_field);
                break;
            case 1:
                dish = new Coffee(dish_title, dish_price, dish_weight, tmp_double_add_field);
                break;
            case 2:
                dish = new Cola(dish_title, dish_price, dish_weight, tmp_double_add_field);
                break;
            case 3:
                dish = new Pizza(dish_title, dish_price, dish_weight, tmp_double_add_field);
                break;
            case 4:
                dish = new Salad(dish_title, dish_price, dish_weight, tmp_double_add_field);
                break;
            case 5:
                dish = new Tea(dish_title, dish_price, dish_weight, tmp_add_field);
                break;
            default:
                dish = new Dish();
                break;
        }

        if (dish->getTile().empty()) continue;
        menu.addDish(dish);
    }
}

Seller* callSeller(const int& visitor_number, std::vector<Seller*> sellers_list) {
    if (visitor_number % 2 == 0) return sellers_list[1];
    if (visitor_number % 3 == 0) return sellers_list[2];

    return sellers_list[0];
}

int main() {
    Menu buffetMenu;
    parseMenu("menu.csv", buffetMenu);

    srand(time(nullptr));

    int visitorsNumber;
    std::vector<Visitor*> visitorsList;
    std::vector<Seller*> sellersList = {
            new Seller("Eduard", "Natanovich", "Luk in", "Buffet", buffetMenu, 134),
            new GreedSeller("Timofei", "Petrovich", "Abram", "Buffet", buffetMenu, 234),
            new InattentiveSeller("Anton", "Grigoriev", "Korolyov", "Buffet", buffetMenu, 42)
    };

    std::cout << "Input visitor number\n";
    std::cin >> visitorsNumber;
    std::cin.ignore();

    for (int i = 0; i < visitorsNumber; i++) {
        std::cout << "Visitor #" << i + 1 << std::endl;
        try {
            auto* new_visitor = new Visitor();
            new_visitor->init();
            visitorsList.push_back(new_visitor);
            if (i != visitorsNumber - 1) getchar();
        } catch (const std::exception& ex) {
            std::cout << ex.what();
            sleep(2);
        }
    }

    Visitor* visitor;
    Seller* seller;

    Inspector* inspector;
    inspector = new Inspector("Harrington", "Mikhailovich", "Elise", "Inspector Business", 124);
    int variant;
    getchar();

    for (int i = 0; i < visitorsList.size(); i++) {
        visitor = visitorsList[i];
        seller = callSeller(i + 1, sellersList);

        inspector->commitCash(seller);
        seller->greetVisitor(visitor);
        seller->createBill();

        do
        {
            displayPossibleActions();
            variant = getVariant(7);

            switch (variant) {
                case 1:
                    seller->informMenu();
                    break;
                case 2:
                    seller->completeBill();
                    break;
                case 3:
                    seller->removeFromBill();
                    break;
                case 4:
                    visitor->informOwnFunds();
                    break;
                case 5:
                    seller->informBill();
                    break;
                case 6:
                    seller->payBill(visitor);
                    inspector->checkPayment(seller);
                    seller->createBill();
                    break;
                default:
                    break;
            }
        } while (variant != 7);

        seller->sayGoodBye(visitor);
    }

    return 0;
}
