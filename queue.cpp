#include "lib/functions.hpp"

using namespace std;

// Función para agregar una orden a un stack de órdenes
void add_order(stack<order>& orders) {
    order newOrder = create_order();
    orders.push(newOrder); // Agregar la nueva orden al stack
    cout << "Orden agregada exitosamente." << endl;
}

// Función para despachar una orden de un stack de órdenes
void dispatch_order(stack<order>& orders) {
    if (!orders.empty()) {
        order dispatchedOrder = orders.top(); // Obtener la orden del tope del stack
        orders.pop(); // Eliminar la orden del tope del stack
        
        cout << "Orden despachada: " << dispatchedOrder.ID << endl;
    } else
        cout << "No hay órdenes para despachar." << endl;
}

// Función para cancelar una orden en un stack de órdenes (para administradores)
void cancel_order(stack<order>& orders, bool is_admin) {
    if (!is_admin) {
        cout << "Acceso denegado. Esta función es solo para administradores." << endl;
    } else if (orders.empty()) {
        cout << "No hay órdenes para cancelar." << endl;
    } else {
        order canceledOrder = orders.top();
        orders.pop();
        cout << "Orden cancelada: " << canceledOrder.ID << endl;
    }
}
