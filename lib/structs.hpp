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