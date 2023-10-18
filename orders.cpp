#include <iostream>
#include <cstdlib>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;


dish dishes[5] = {
    {"Spaghetti Carbonara", 12.99},
    {"4 Chessee Pizza", 14.50},
    {"Pepperonni Pizza", 10.99},
    {"Margherita Pizza", 16.75},
    {"4 Seasons Pizza", 18.25}};

drink drinks[5] = {
    {"Coca-Cola", 2.50},
    {"Fresh Orange Juice", 3.25},
    {"Iced Tea", 2.00},
    {"Lemonade", 2.75},
    {"Mineral Water", 1.99}};

apt appetizers[5] = {
    {"Mozzarella Sticks", 5.99},
    {"Chicken Wings", 7.50},
    {"Bruschetta", 6.25},
    {"Spinach Artichoke Dip", 6.99},
    {"Onion Rings", 4.75}};


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

template <typename T>
double calculate_order_subtotal(const stack<T>& orderItems)
{
    double total = 0.0;

    // Recorrer la pila de elementos y suma los precios
    stack<T> tempStack = orderItems; // Copia de la pila original

    while (!tempStack.empty())
    {
        T item = tempStack.top();
        total += item.price;
        tempStack.pop();
    }

    return total;
}
// Funcion para calcular el total de una sola orden
double calculate_order_total(const order& order){
    return (calculate_order_subtotal(order.apts) + calculate_order_subtotal(order.dishes) + calculate_order_subtotal(order.drinks)); 
}


order create_order()
{
    order newOrder;

    // Solicitar información al cliente
    cout << "Nombre del cliente: ";
    cin.ignore(); // Limpiar el búfer de entrada
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
