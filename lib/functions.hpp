#include <iostream>
#include "structs.hpp"

string encrypt_password(string password);
string decrypt_password(string password);

order create_order();

void add_order();
void dispatch_order();
void cancel_order(bool is_admin);