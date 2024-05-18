#include "header.hpp"
void User::registerUser() {
    cout << "User Name: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Email: ";
    cin >> email;
    cout << "Registration Successful!\n";
    cout << "-----------------------------------\n";
}
bool User::loginUser(const vector<User>& users) {
    string inputUsername, inputPassword;
    cout << "User Name: ";
    cin >> inputUsername;
    cout << "Password: ";
    cin >> inputPassword;

    for (const auto& user : users) {
        if (user.username == inputUsername && user.password == inputPassword) {
            return true;
        }
    }
    return false;
}
void Product::displayProductDetails() const {
    cout << "Product ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Explanation: " << description << endl;
    cout << "Stok: " << stock << endl;
}
void Cart::addItem(const Product& product) {
    if (items.size() < 5) {
        items.push_back(product);
        totalPrice += product.price;
        cout << product.name << " added to cart.\n";
        cout << "-----------------------------------\n";
    } else {
        cout << "The basket can contain a maximum of 5 items.\n";
        cout << "-----------------------------------\n";
    }
}
void Cart::removeItem(int productId) {
    auto it = remove_if(items.begin(), items.end(), [productId](const Product& product) {
        return product.productId == productId;
    });
    if (it != items.end()) {
        totalPrice -= it->price;
        items.erase(it, items.end());
        cout << "product removed from cart.\n";
        cout << "-----------------------------------\n";
    } else {
        cout << "The product was not found in your cart.\n";
        cout << "-----------------------------------\n";
    }
}
void Cart::displayCart() const {
    for (const auto& item : items) {
        cout << "Product ID: " << item.productId << ", Name: " << item.name << ", Price: " << item.price << endl;
    }
    cout << "Total of price: " << totalPrice << endl;
    cout << "-----------------------------------\n";
}
void Order::placeOrder() {
    cout << "Order Created Successfully!\n";
    cout << "-----------------------------------\n";
}
void Order::displayOrderDetails() const {
    cout << " Order ID: " << orderId << endl;
    cout << "Result: " << status << endl;
    cout << "Products:\n";
    for (const auto& item : items) {
        cout << "Product ID: " << item.productId << ", Name: " << item.name << ", Product: " << item.price << endl;
    }
    cout << "Total of Product: " << totalPrice << endl;
    cout << "-----------------------------------\n";
}
void addProduct(vector<Product>& products) {
    Product newProduct;
    cout << "Product ID: ";
    cin >> newProduct.productId;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newProduct.name);
    cout << "Product: ";
    cin >> newProduct.price;
    cout << "Explation: ";
    cin.ignore();
    getline(cin, newProduct.description);
    cout << "Stock: ";
    cin >> newProduct.stock;
    products.push_back(newProduct);
}
void deleteProduct(vector<Product>& products, int productId) {
    auto it = remove_if(products.begin(), products.end(), [productId](Product& product) {
        return product.productId == productId;
    });
    if (it != products.end()) {
        products.erase(it, products.end());
    }
}
void updateProduct(vector<Product>& products, int productId) {
    for (auto& product : products) {
        if (product.productId == productId) {
            cout << "New Name: ";
            cin.ignore();
            getline(cin, product.name);
            cout << "New Price: ";
            cin >> product.price;
            cout << "New Explation: ";
            cin.ignore();
            getline(cin, product.description);
            cout << "New Stock: ";
            cin >> product.stock;
        }
    }
}
void saveDataToFile(const vector<User>& users, const vector<Product>& products) {
    ofstream outFile("C:\\Users\\HP\\Desktop\\products.txt");
    outFile << "[Users]\n";
    for (const auto& user : users) {
        outFile << user.username << "\n";
        outFile << user.password << "\n";
        outFile << user.email << "\n";
    }
    outFile << "[Products]\n";
    for (const auto& product : products) {
        outFile << product.productId << "\n";
        outFile << product.name << "\n";
        outFile << product.price << "\n";
        outFile << product.description << "\n";
        outFile << product.stock << "\n";
    }
outFile.close();
}
void loadDataFromFile(vector<User>& users, vector<Product>& products) {
    ifstream inFile("C:\\Users\\HP\\Desktop\\products.txt");
    string line;
    bool isUserSection = false;
    bool isProductSection = false;
    while (getline(inFile, line)) {
        if (line == "[Users]") {
            isUserSection = true;
            isProductSection = false;
        } else if (line == "[Products]") {
            isUserSection = false;
            isProductSection = true;
        } else if (isUserSection) {
            User user;
            user.username = line;
            getline(inFile, user.password);
            getline(inFile, user.email);
            users.push_back(user);
        } else if (isProductSection) {
            Product product;
            product.productId = stoi(line);
            getline(inFile, product.name);
            getline(inFile, line);
            product.price = stod(line);
            getline(inFile, product.description);
            getline(inFile, line);
            product.stock = stoi(line);
            products.push_back(product);
        }
    }

    inFile.close();
}
void displayMenu() {
cout << "1. User Registration\n";
cout << "2. Login\n";
cout << "3. List Products\n";
cout << "4. Add Product to Cart\n";
cout << "5. Remove Product from Cart\n";
cout << "6. View Cart\n";
cout << "7. Place Order\n";
cout << "8. Exit\n";
cout << "Make your choice: ";
}

