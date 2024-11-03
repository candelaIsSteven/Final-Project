#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Empleado.h"
#include "Proveedor.h"

using namespace std;

int main() {
    // Crear objetos de Cliente, Empleado y Proveedor
    Cliente cliente(1, "Juan Perez", "Calle Falsa 123", "123456789", "juan@example.com", "12345678-9", "Ingeniero", "Empleado público");
    Empleado empleado(2, "Maria Gomez", "Calle Verdadera 456", "987654321", "maria@example.com", 1500.00, "9am - 5pm");
    Proveedor proveedor(3, "Proveedor S.A.", "Avenida Central 789", "456123789", "proveedor@example.com", "98765432-1", "Banco XYZ", "123456", "corriente");

    // Mostrar los datos de cada objeto
    cout << "Datos del Cliente:" << endl;
    cliente.mostrar();
    cout << endl;

    cout << "Datos del Empleado:" << endl;
    empleado.mostrar();
    cout << endl;

    cout << "Datos del Proveedor:" << endl;
    proveedor.mostrar();
    cout << endl;

    // Guardar en archivos
    ofstream archivoClientes("clientes.txt", ios::app);
    cliente.guardarCliente(archivoClientes);
    archivoClientes.close();

    ofstream archivoEmpleados("empleados.txt", ios::app);
    empleado.guardarEmpleado(archivoEmpleados);
    archivoEmpleados.close();

    ofstream archivoProveedores("proveedores.txt", ios::app);
    proveedor.guardarProveedor(archivoProveedores);
    archivoProveedores.close();

    // Cargar desde archivos y mostrar
    cout << "Cargando clientes desde archivo..." << endl;
    ifstream archivoC("clientes.txt");
    string linea;
    while (getline(archivoC, linea)) {
        Cliente c = Cliente::cargarCliente(linea);
        c.mostrar();
    }
    archivoC.close();

    cout << "Cargando empleados desde archivo..." << endl;
    ifstream archivoE("empleados.txt");
    while (getline(archivoE, linea)) {
        Empleado e = Empleado::cargarEmpleado(linea);
        e.mostrar();
    }
    archivoE.close();

    cout << "Cargando proveedores desde archivo..." << endl;
    ifstream archivoP("proveedores.txt");
    while (getline(archivoP, linea)) {
        Proveedor p = Proveedor::cargarProveedor(linea);
        p.mostrar();
    }
    archivoP.close();

    return 0;
}
