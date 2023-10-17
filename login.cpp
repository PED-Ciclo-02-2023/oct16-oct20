#include <iostream>
#include <sstream>
#include "lib/functions.hpp"

using namespace std;


bool login(string username, string password){
    return true;
}

string encrypt_password(string password){
    string encryptedPassword;

    // for (<Tipo de variable> <nombre dentro del for> : <iterable>)
    for (char c : password) {
        int asciiValue = static_cast<int>(c);
        encryptedPassword += to_string(asciiValue) + "$"; // Usamos "$" como separador
    }

    return encryptedPassword;

}

string decrypt_password(string password){
    string decryptedPassword;
    istringstream iss(password);

    while (true) {
        int asciiValue;
        char separator; // Para leer el carácter de separación "$"
        iss >> asciiValue >> separator;
        if (iss.eof()) {
            break;
        }
        decryptedPassword += static_cast<char>(asciiValue);
    }

    return decryptedPassword;
}