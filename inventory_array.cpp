#include <iostream>
using namespace std;

class Inventory {
private:
    int items[100];
    int count;

public:
    Inventory() {
        count = 0;
    }
    void insert(int value) {
        if (count < 100) {
            items[count] = value;
            count++;
            cout << "Item inserted successfully.\n";
        } else {
            cout << "Inventory is full!\n";
        }
    }

    void deleteItem(int position) {
        if (position >= 0 && position < count) {
            for (int i = position; i < count - 1; i++) {
                items[i] = items[i + 1];
            }
            count--;
            cout << "Item deleted successfully.\n";
        } else {
            cout << "Invalid position!\n";
        }
    }

    void update(int position, int newValue) {
        if (position >= 0 && position < count) {
            items[position] = newValue;
            cout << "Item updated successfully.\n";
        } else {
            cout << "Invalid position!\n";
        }
    }
    void display() {
        if (count == 0) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Inventory items: ";
        for (int i = 0; i < count; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Inventory inv;

    inv.insert(10);
    inv.insert(20);
    inv.insert(30);

    inv.display();

    inv.update(1, 25);
    inv.display();

    inv.deleteItem(0);
    inv.display();

    return 0;
}