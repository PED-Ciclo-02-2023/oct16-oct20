#include "lib/functions.hpp"

using namespace std;

// Función para agregar una orden a una cola de órdenes
void add_order(queue<order>& orders) {
    order newOrder = create_order();
    orders.push(newOrder); // Agregar la nueva orden al final de la cola
    cout << "Orden agregada exitosamente." << endl;
}

// Función para despachar una orden desde una cola de órdenes
void dispatch_order(queue<order>& orders) {
    if (!orders.empty()) {
        order dispatchedOrder = orders.front(); // Obtener la orden desde el frente de la cola
        orders.pop(); // Eliminar la orden desde el frente de la cola
        
        cout << "Orden despachada: " << dispatchedOrder.ID << endl;
    } else
        cout << "No hay órdenes para despachar." << endl;
}

// Función para cancelar una orden en una cola de órdenes (para administradores)
void cancel_order(queue<order>& orders, bool is_admin) {
    if (!is_admin) {
        cout << "Acceso denegado. Esta función es solo para administradores." << endl;
    } else if (orders.empty()) {
        cout << "No hay órdenes para cancelar." << endl;
    } else {
        order canceledOrder = orders.front();
        orders.pop();
        cout << "Orden cancelada: " << canceledOrder.ID << endl;
    }
}
