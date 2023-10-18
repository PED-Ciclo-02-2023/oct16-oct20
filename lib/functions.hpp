#include <iostream>
#include "structs.hpp"

string encrypt_password(string password);
string decrypt_password(string password);

order create_order();

void add_order(stack<order>& orders);
void dispatch_order(stack<order>& orders);
void cancel_order(stack<order>& orders, bool is_admin);
