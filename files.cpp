#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Librería para la funcion trim
#include <cctype>    // Librería para la funcion trim
#include "lib/functions.hpp"

using namespace std;

// Function to trim leading and trailing whitespace from a string
string trim(const string& str) {
    // Se crea una copia de la cadena original.
    string result = str;

    // Elimina los espacios en blanco iniciales.
    result.erase(result.begin(), find_if(result.begin(), result.end(), [](int ch) {return !isspace(ch);}));

    // Elimina los espacios en blanco finales.
    result.erase(find_if(result.rbegin(), result.rend(), [](int ch) {return !isspace(ch);}).base(), result.end());

    /*
    begin: Devuelve un iterador al primer elemento del contenedor.
    end: Devuelve un iterador al elemento después del último elemento del contenedor.

    rbegin: Devuelve un iterador al último elemento del contenedor.
    rend: Devuelve un iterador al elemento antes del primer elemento del contenedor.
    */

    // Devuelve la cadena resultante sin espacios en blanco iniciales y finales.
    return result;
}

// Función para obtener la constraseña de un usuario a partir del nombre de usuario
string get_password_for_username(const string& username, const string& filename) {
    ifstream file(filename);
    string line;
    vector<user> users;

    if (file.is_open()) {
        user currentUser;
        bool isUsername = true;

        while (getline(file, line)) {
            line = trim(line); // Quitar los espacios en blanco
            if (isUsername) {
                currentUser.username = line;
            } else {
                currentUser.password = line;
                users.push_back(currentUser);  // Añadir el usuario a la lista
            }
            isUsername = !isUsername;
        }
        file.close();

        for (auto user : users) {
            if (user.username == username) {
                return user.password; // Devolver la contraseña si se encuentra al usuario
            }
        }

        return "U404";  // Si no encuentro al usuario
    } else {
        return "F404"; // Si el archivo no se pudo abrir
    }
}