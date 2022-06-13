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
void printMenu()
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

void getMenu(const std::string& file_name, Menu& menu)
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
        std::string dish_type, dish_title, tmp_dish_price, tmp_dish_weight;

        std::getline(lineStream, dish_type, ',');
        std::getline(lineStream, dish_title, ',');
        std::getline(lineStream, tmp_dish_price, ',');
        std::getline(lineStream, tmp_dish_weight, ',');

        double dish_price = std::stod(tmp_dish_price);
        double dish_weight = std::stod(tmp_dish_weight);

        auto it = find(dishTypes.begin(), dishTypes.end(), dish_type);
        int index = it - dishTypes.begin();

        switch (index) {
            case 0:
                dish = new Cake(dish_title, dish_price, dish_weight);
                break;
            case 1:
                dish = new Coffee(dish_title, dish_price, dish_weight);
                break;
            case 2:
                dish = new Cola(dish_title, dish_price, dish_weight);
                break;
            case 3:
                dish = new Pizza(dish_title, dish_price, dish_weight);
                break;
            case 4:
                dish = new Salad(dish_title, dish_price, dish_weight);
                break;
            case 5:
                dish = new Tea(dish_title, dish_price, dish_weight);
                break;
            default:
                dish = new Dish();
                break;
        }

        if (dish->getTile().empty()) continue;
        menu.addDish(dish);
    }
}

Seller* callSeller(const int& visitor_number, std::vector<Seller*> sellersList) {
    if (visitor_number % 2 == 0) return sellersList[1];
    if (visitor_number % 3 == 0) return sellersList[2];

    return sellersList[0];
}

class Menu;

int main() {
    Menu buffetMenu;
    getMenu("menu.csv", buffetMenu);

    int visitorsNumber;
    std::vector<Visitor*> visitorsList;
    std::vector<Seller*> sellersList = {
            new Seller("Eduard", "Anatolievich", "Lukin", "Buffet", buffetMenu, 132),
            new GreedSeller("Timofey", "Petrovich", "Abramov", "Buffet", buffetMenu, 234),
            new InattentiveSeller("Anton", "Grigorievich", "Korolev", "Buffet", buffetMenu, 42)
    };

    std::cout << "Input visitor number\n";
    std::cin >> visitorsNumber;

    for (int i = 0; i < visitorsNumber; i++) {
        std::cout << "Visitor #" << i + 1 << std::endl;
        try {
            auto* new_visitor = new Visitor();
            new_visitor->init();
            visitorsList.push_back(new_visitor);
        } catch (const std::exception& ex) {
            std::cout << ex.what();
            sleep(2);
        }
    }

    Inspector* inspector;
    Visitor* visitor;
    Seller* seller;

    inspector = new Inspector("Khariton", "Mikhailovich", "Eliseev", "Inspector Business");
    int variant;
    getchar();

    for (int i = 0; i < visitorsList.size(); i++) {
        visitor = visitorsList[i];
        seller = callSeller(i + 1, sellersList);

        seller->greetVisitor(visitor);
        seller->createBill();

        do
        {
            printMenu();
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
                    visitor->checkOwnFunds();
                    break;
                case 5:
                    seller->informBill();
                    break;
                case 6:
                    seller->payBill(visitor);
                    inspector->checkPayment(seller);
                    break;
                default:
                    break;
            }
        } while (variant != 7);

        seller->sayGoodBye(visitor);
    }

    return 0;
}
