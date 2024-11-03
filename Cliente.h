#include "Persona.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Cliente : public Persona {
private:
    string rut;
    string profesion;
    string tipoCliente; // pensionado, empleado público, empresario, militar

public:
    Cliente(int id, const string& nombre, const string& direccion, const string& telefono, 
            const string& email, const string& rut, const string& profesion, const string& tipoCliente)
        : Persona(id, nombre, direccion, telefono, email), rut(rut), profesion(profesion), tipoCliente(tipoCliente) {}

    void guardarCliente(ofstream &archivo) const {
        archivo << id << "," << nombre << "," << direccion << "," << telefono << ","
                << email << "," << rut << "," << profesion << "," << tipoCliente << "\n";
    }

    static Cliente cargarCliente(const string &linea) {
        stringstream ss(linea);
        string idStr, nombre, direccion, telefono, email, rut, profesion, tipoCliente;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, direccion, ',');
        getline(ss, telefono, ',');
        getline(ss, email, ',');
        getline(ss, rut, ',');
        getline(ss, profesion, ',');
        getline(ss, tipoCliente, ',');

        int id = stoi(idStr);
        return Cliente(id, nombre, direccion, telefono, email, rut, profesion, tipoCliente);
    }

    void mostrar() const override {
        Persona::mostrar();
        cout << "RUT: " << rut << ", Profesión: " << profesion << ", Tipo Cliente: " << tipoCliente << endl;
    }
};