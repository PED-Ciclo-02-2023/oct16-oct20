#include <iostream>
#include <cstdlib>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

void printMenu(string menuType, auto *items, int size)
{
    cout << "Menú de " << menuType << ":" << endl;
    for (int i = 0; i < size; i++)
        cout << items[i].name << " - $" << items[i].price << endl;
};

string generate_order_id()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    string order_id;
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int id_length = 9;

    for (int i = 0; i < id_length; i++)
    {
        int index = rand() % characters.size(); // Generar un índice aleatorio
        order_id += characters[index];          // Agregar un carácter aleatorio al ID
    }

    return order_id;
}

template <typename T>
stack<T> add_items(const T *menu, const string &itemType, int menuSize)
{
    stack<T> orderItems;
    int numItems;

    cout << "¿Cuántos " << itemType << " desea agregar a la orden? ";
    cin >> numItems;

    while (numItems > 0)
    {
        cout << "Seleccione un " << itemType << " (1-" << menuSize << "): ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= menuSize)
        {
            orderItems.push(menu[choice - 1]);
            numItems--;
        }
        else
            cout << "Opción no válida. Por favor, elija un número válido del menú." << endl;
    }

    return orderItems;
};

order create_order()
{
    order newOrder;

    // Solicitar información al cliente
    cout << "Nombre del cliente: ";
    getline(cin, newOrder.client);

    // Asignar ID
    newOrder.ID = generate_order_id();

    // Agregar platos, bebidas y aperitivos a la orden
    printMenu("Platos (Dishes)", dishes, 5);
    stack<dish> orderDishes = add_items(dishes, "platos", 5);

    printMenu("Bebidas (Drinks)", drinks, 5);
    stack<drink> orderDrinks = add_items(drinks, "bebidas", 5);

    printMenu("Aperitivos (Appetizers)", appetizers, 5);
    stack<apt> orderAppetizers = add_items(appetizers, "aperitivos", 5);

    newOrder.dishes = orderDishes;
    newOrder.drinks = orderDrinks;
    newOrder.apts = orderAppetizers;

    // Solicitar detalles de pago y entrega
    cout << "¿Pago con tarjeta? (1: Sí, 0: No): ";
    cin >> newOrder.is_card_payment;
    cout << "¿Entrega a domicilio? (1: Sí, 0: No): ";
    cin >> newOrder.is_delivery;
    if (newOrder.is_delivery)
    {
        cout << "Dirección de entrega: ";
        cin.ignore(); // Limpiar el búfer de entrada
        getline(cin, newOrder.delivery_address);
    }else
        newOrder.delivery_address = "-";

    return newOrder;
}
