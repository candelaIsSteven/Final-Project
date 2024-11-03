#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Factura {
private:
    int idFactura;
    string fechaFactura;
    string horaFactura;
    string tipoFactura;
    int idEmpleado;
    int idCliente;
    int idProveedor;

public:
    Factura(int id, string fecha, string hora, string tipo, int idEmp, int idCli, int idProv)
        : idFactura(id), fechaFactura(fecha), horaFactura(hora), tipoFactura(tipo), 
          idEmpleado(idEmp), idCliente(idCli), idProveedor(idProv) {}

    void guardarFactura(ofstream &archivo) const {
        archivo << idFactura << "," << fechaFactura << "," << horaFactura << "," 
                << tipoFactura << "," << idEmpleado << "," << idCliente << "," 
                << idProveedor << "\n";
    }

    static Factura cargarFactura(const string &linea) {
        stringstream ss(linea);
        string idStr, fecha, hora, tipo, idEmpStr, idCliStr, idProvStr;

        getline(ss, idStr, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, tipo, ',');
        getline(ss, idEmpStr, ',');
        getline(ss, idCliStr, ',');
        getline(ss, idProvStr, ',');

        int id = stoi(idStr);
        int idEmp = stoi(idEmpStr);
        int idCli = stoi(idCliStr);
        int idProv = stoi(idProvStr);

        return Factura(id, fecha, hora, tipo, idEmp, idCli, idProv);
    }

    void mostrar() const {
        cout << "ID Factura: " << idFactura << ", Fecha: " << fechaFactura 
             << ", Hora: " << horaFactura << ", Tipo: " << tipoFactura 
             << ", ID Empleado: " << idEmpleado << ", ID Cliente: " 
             << idCliente << ", ID Proveedor: " << idProveedor << endl;
    }
};