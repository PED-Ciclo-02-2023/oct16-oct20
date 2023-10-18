#include <iostream>
#include "lib/functions.hpp"

using namespace std;

bool log_in(string username, string password);
bool log_out(bool session_status);

const string USERS_FILE = "db/users.txt";
const string ADMINS_FILE = "db/admins.txt";

int main() {
    bool is_admin = false;
    bool is_logged_in = false;
    float total_sales = 0;
    queue<order> pizza_orders;
    string username;

    while (true) {
        // Initial login process
        while (!is_logged_in) {
            cout << "Login" << endl;
            cout << "Enter your username: ";
            cin >> username;
            string password;
            cout << "Enter your password: ";
            cin >> password;

            is_logged_in = log_in(username, password);

            if (!is_logged_in) {
                cout << "\nLogin failed. Please try again." << endl;
            }
        }

        // Once logged in, display the main menu
        while (is_logged_in) {
            cout << "Main Menu" << endl;
            cout << "1. Add order" << endl;
            cout << "2. Dispatch order" << endl;
            cout << "3. Cancel Order" << endl;
            cout << "4. Calculate Sales" << endl;
            cout << "5. Log Out" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    add_order(pizza_orders);
                    break;
                
                case 2:
                    total_sales += calculate_order_total(pizza_orders.front());
                    dispatch_order(pizza_orders);
                    break;
                
                case 3:
                    cancel_order(pizza_orders, is_admin);
                    break;

                case 4:
                    cout << "\nTotal en ventas de la sesión: $" << total_sales;
                    break;

                case 5:
                    is_logged_in = log_out(is_logged_in);
                    is_admin = false;
                    cout << "Logged out." << endl;
                    break;

                case 6:
                    cout << "Exiting the application." << endl;
                    return 0;

                default:
                    cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
    }

    return 0;
}

bool log_in(string username, string password)
{
    string password_in_db = get_password_for_username(username, USERS_FILE);

    if (password_in_db == "U404")
        password_in_db = get_password_for_username(username, ADMINS_FILE);

    if (password_in_db == "F404"){
        cout << "Problems finding the file..." << endl;
        return false;
    }

    if (password_in_db == "U404"){
        cout << "User not found..." << endl;
        return false;
    }

    if (encrypt_password(password) != password_in_db){
        cout << "Wrong password." << endl;
        return false;
    }

    return true;
}

bool log_out(bool session_status){
    return !session_status;
}
