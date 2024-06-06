#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    int unidades;
    double precio_unitario;
    string estado;
    double total_factura;
};

void generarFactura(Cliente clientes[], int cantidad_clientes) {
    for (int i = 0; i < cantidad_clientes; i++) {
        cout << "Ingrese el nombre del cliente " << i + 1 << ": ";
        cin >> clientes[i].nombre;
        cout << "Ingrese el numero de unidades solicitadas por " << clientes[i].nombre << ": ";
        cin >> clientes[i].unidades;
        cout << "Ingrese el precio unitario para " << clientes[i].nombre << ": ";
        cin >> clientes[i].precio_unitario;
        cout << "Ingrese el estado del cliente (moroso, atrasado, pagado) para " << clientes[i].nombre << ": ";
        cin >> clientes[i].estado;
        clientes[i].total_factura = clientes[i].unidades * clientes[i].precio_unitario;
    }
}

void listarClientesMorosos(const Cliente clientes[], int cantidad_clientes) {
    cout << "\nClientes en estado moroso:" << endl;
    for (int i = 0; i < cantidad_clientes; i++) {
        if (clientes[i].estado == "moroso") {
            cout << clientes[i].nombre << " - Total Factura: " << clientes[i].total_factura << endl;
        }
    }
}

void listarClientesPagadosConFacturaMayorA(const Cliente clientes[], int cantidad_clientes, double cantidad) {
    cout << "\nClientes en estado pagado con factura mayor a " << cantidad << ":" << endl;
    for (int i = 0; i < cantidad_clientes; i++) {
        if (clientes[i].estado == "pagado" && clientes[i].total_factura > cantidad) {
            cout << clientes[i].nombre << " - Total Factura: " << clientes[i].total_factura << endl;
        }
    }
}

double calcularPromedioFacturas(const Cliente clientes[], int cantidad_clientes) {
    double suma_total_facturas = 0.0;
    for (int i = 0; i < cantidad_clientes; i++) {
        suma_total_facturas += clientes[i].total_factura;
    }
    return (cantidad_clientes > 0) ? (suma_total_facturas / cantidad_clientes) : 0.0;
}

int main() {
    int cantidad_clientes;
    cout << "Ingrese el numero de clientes: ";
    cin >> cantidad_clientes;

    Cliente clientes[cantidad_clientes];
    generarFactura(clientes, cantidad_clientes);

    listarClientesMorosos(clientes, cantidad_clientes);

    double cantidad;
    cout << "\nIngrese la cantidad para listar clientes pagados con factura mayor a: ";
    cin >> cantidad;
    listarClientesPagadosConFacturaMayorA(clientes, cantidad_clientes, cantidad);

    double promedio_facturas = calcularPromedioFacturas(clientes, cantidad_clientes);
    cout << "\nEl promedio de todas las facturas es: " << promedio_facturas << endl;

    return 0;
}
