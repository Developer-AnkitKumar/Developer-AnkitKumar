#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;

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

int main() {
    Menu menu;
    menu.addItem("Coffee", 2.5);
    menu.addItem("Tea", 1.5);
    menu.addItem("Sandwich", 5.0);
    menu.addItem("Cake", 3.0);

    int choice;
    Order order;
    
    do {
        cout << "1. Display Menu\n";
        cout << "2. Add Item to Order\n";
        cout << "3. Display Order\n";
        cout << "4. Get Total Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                menu.displayMenu();
                break;
            case 2: {
                string itemName;
                cout << "Enter item name to add: ";
                cin >> itemName;
                MenuItem* item = menu.getItem(itemName);
                if (item) {
                    order.addItem(*item);
                    cout << "Item added to order.\n";
                } else {
                    cout << "Item not found.\n";
                }
                break;
            }
            case 3:
                order.displayOrder();
                break;
            case 4:
                cout << "Total Bill: $" << order.getTotal() << "\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}