#include <iostream>
#include <stack>

using namespace std;

struct user
{
    string username;
    string password;
};

struct dish
{
    string name;
    float price;
};

struct drink
{
    string name;
    float price;
};

struct apt
{ // Appetizer
    string name;
    float price;
};

dish dishes[5] = {
    {"Spaghetti Carbonara", 12.99},
    {"Chicken Alfredo", 14.50},
    {"Margherita Pizza", 10.99},
    {"Grilled Salmon", 16.75},
    {"Steak Fajitas", 18.25}};

drink drinks[5] = {
    {"Coca-Cola", 2.50},
    {"Fresh Orange Juice", 3.25},
    {"Iced Tea", 2.00},
    {"Lemonade", 2.75},
    {"Mineral Water", 1.99}};

apt appetizers[5] = {
    {"Mozzarella Sticks", 5.99},
    {"Chicken Wings", 7.50},
    {"Bruschetta", 6.25},
    {"Spinach Artichoke Dip", 6.99},
    {"Onion Rings", 4.75}};

struct order{
    string client;
    string ID;
    stack<dish> dishes;
    stack<drink> drinks;
    stack<apt> apts;
    bool is_card_payment;
    bool is_delivery;
    string delivery_address;
}; typedef struct order Order;