//define  the structure of order
#include <iostream>
#include <vector>

using std::vector;
using std::string;
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

class Order {
private:
    vector<MenuItem> items;
public:
    void addItem(MenuItem item);
    void displayOrder();
    double getTotal();
};

void Order::addItem(MenuItem item) {
    items.push_back(item);
}

void Order::displayOrder() {
    cout << "Order:\n";
    for (const auto& item : items) {
        cout << item.name << " - $" << item.price << "\n";
    }
}

double Order::getTotal() {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.price;
    }
    return total;
}