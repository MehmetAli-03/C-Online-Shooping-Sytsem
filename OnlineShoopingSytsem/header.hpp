#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;
class User {
public:
    string username;
    string password;
    string email;

    void registerUser();
    bool loginUser(const vector<User>& users);
};


class Product {
public:
    int productId;
    string name;
    double price;
    string description;
    int stock;

    void displayProductDetails() const;
};


class Cart {
public:
    vector<Product> items;
    double totalPrice = 0.0;

    void addItem(const Product& product);
    void removeItem(int productId);
    void displayCart() const;
};
class Order {
public:
    int orderId;
    User user;
    vector<Product> items;
    double totalPrice;
    string status;

    void placeOrder();
    void displayOrderDetails() const;
};
void addProduct(vector<Product>& products);
void deleteProduct(vector<Product>& products, int productId);
void updateProduct(vector<Product>& products, int productId);


void saveDataToFile(const vector<User>& users, const vector<Product>& products);
void loadDataFromFile(vector<User>& users, vector<Product>& products);

void displayMenu();
#endif // HEADER_HPP

