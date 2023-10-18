#include <iostream>
#include <queue>
#include "structs.hpp"

// Login Utils

string encrypt_password(string password);
string decrypt_password(string password);

// Files

string get_password_for_username(const string& username, const string& filename);

// Orders

order create_order();
double calculate_order_total(const order& order);

// Stack

void add_order(queue<order>& orders);
void dispatch_order(queue<order>& orders);
void cancel_order(queue<order>& orders, bool is_admin);
