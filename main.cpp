#include <iostream>
#include <stack>
#include "lib/functions.hpp"

using namespace std;


int main () {
    string mensaje = "Hola mundo!";
    cout << encrypt_password(mensaje) << endl;
    cout << decrypt_password(encrypt_password(mensaje)) << endl;
}