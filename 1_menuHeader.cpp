//Main menu define the structure of menu
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;


class MenuItem {
public:
    string name;
    double price;
    MenuItem(string n, double p) : name(n), price(p) {}
};

class Menu {
private:
    vector<MenuItem> items;
public:
    void addItem(string name, double price);
    void displayMenu();
    MenuItem* getItem(string name);
};
//implement the Menu method
void Menu::addItem(string name, double price) {
    items.push_back(MenuItem(name, price));
}

void Menu::displayMenu() {
    cout << "Menu:\n";
    for (const auto& item : items) {
        cout << item.name << " - $" << item.price << "\n";
    }
}

MenuItem* Menu::getItem(string name) {
    for (auto& item : items) {
        if (item.name == name) {
            return &item;
        }
    }
    return nullptr;
}