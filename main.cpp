#include <iostream>
#include <stack>
#include "lib/functions.hpp"

using namespace std;

const string USERS_FILE = "db/users.txt";
const string ADMIN_FILE = "db/admins.txt";

int main () {
    cout << encrypt_password("admin") << endl;
}