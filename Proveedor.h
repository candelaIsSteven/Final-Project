#include "Persona.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Proveedor : public Persona {
private:
    string rut;
    string banco;
    string nroCuenta;
    string tipoCuenta; // ahorros, corriente

public:
    Proveedor(int id, const string& nombre, const string& direccion, const string& telefono, 
              const string& email, const string& rut, const string& banco, 
              const string& nroCuenta, const string& tipoCuenta)
        : Persona(id, nombre, direccion, telefono, email), rut(rut), banco(banco), 
          nroCuenta(nroCuenta), tipoCuenta(tipoCuenta) {}

    void guardarProveedor(ofstream &archivo) const {
        archivo << id << "," << nombre << "," << direccion << "," << telefono << ","
                << email << "," << rut << "," << banco << "," << nroCuenta << "," 
                << tipoCuenta << "\n";
    }

    static Proveedor cargarProveedor(const string &linea) {
        stringstream ss(linea);
        string idStr, nombre, direccion, telefono, email, rut, banco, nroCuenta, tipoCuenta;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, direccion, ',');
        getline(ss, telefono, ',');
        getline(ss, email, ',');
        getline(ss, rut, ',');
        getline(ss, banco, ',');
        getline(ss, nroCuenta, ',');
        getline(ss, tipoCuenta, ',');

        int id = stoi(idStr);
        return Proveedor(id, nombre, direccion, telefono, email, rut, banco, nroCuenta, tipoCuenta);
    }

    void mostrar() const override {
        Persona::mostrar();
        cout << "RUT: " << rut << ", Banco: " << banco << ", Número de Cuenta: " 
             << nroCuenta << ", Tipo de Cuenta: " << tipoCuenta << endl;
    }
};