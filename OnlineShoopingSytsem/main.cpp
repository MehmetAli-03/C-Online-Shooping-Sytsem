#include "header.hpp"

int main() {
    vector<User> users;
    vector<Product> products;


    products = {
        {1, "Laptop", 15000.0, "16GB RAM, 512GB SSD", 10},
        {2, "Phone", 7000.0, "128GB SSD, 6GB RAM", 20},
        {3, "Tablet", 5000.0, "64GB SSD, 4GB RAM", 15},
        {4, "Headphone", 500.0, "Bluetooth, Microphone", 50},
        {5, "Monitor", 2000.0, "27 inc, 144Hz", 25}
    };

    User currentUser;
    Cart cart;
    Order order;

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            currentUser.registerUser();
            users.push_back(currentUser);
            break;
        case 2:
            if (currentUser.loginUser(users)) {
                cout << "You have successfully logged in.\n";
                cout << "-----------------------------------\n";
            } else {
                cout << "Login failed.\n";
                cout << "-----------------------------------\n";
            }
            break;
        case 3:
            for (const auto& product : products) {
                product.displayProductDetails();
                cout << "-----------------------------------\n";
            }
            break;
        case 4: {
            int productId;
            cout << "Enter the ID of the product you want to add to the cart: ";
            cin >> productId;
            auto it = find_if(products.begin(), products.end(), [productId](Product& product) {
                return product.productId == productId;
            });
            if (it != products.end()) {
                cart.addItem(*it);
                cout << "-----------------------------------\n";
            } else {
                cout << "Product not found.\n";
                cout << "-----------------------------------\n";
            }
            break;
        }
        case 5: {
            int productId;
            cout << "Enter the ID of the product you want to remove from the cart: ";
            cin >> productId;
            cart.removeItem(productId);
            break;
            cout << "-----------------------------------\n";
        }
        case 6:
            cart.displayCart();
            break;
        case 7:
            order.items = cart.items;
            order.totalPrice = cart.totalPrice;
            order.placeOrder();
            break;
        case 8:
            saveDataToFile(users, products);
            cout << "logging out...\n";
            return 0;
            cout << "-----------------------------------\n";
        default:
            cout << "Invalid selection. Try again.\n";
            break;
        }
    }

    return 0;
}

