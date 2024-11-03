#include "Persona.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Empleado : public Persona {
private:
    double salario;
    string horario;

public:
    Empleado(int id, const string& nombre, const string& direccion, const string& telefono, 
             const string& email, double salario, const string& horario)
        : Persona(id, nombre, direccion, telefono, email), salario(salario), horario(horario) {}

    void guardarEmpleado(ofstream &archivo) const {
        archivo << id << "," << nombre << "," << direccion << "," << telefono << ","
                << email << "," << salario << "," << horario << "\n";
    }

    static Empleado cargarEmpleado(const string &linea) {
        stringstream ss(linea);
        string idStr, nombre, direccion, telefono, email, salarioStr, horario;

        getline(ss, idStr, ',');
        getline(ss, nombre, ',');
        getline(ss, direccion, ',');
        getline(ss, telefono, ',');
        getline(ss, email, ',');
        getline(ss, salarioStr, ',');
        getline(ss, horario, ',');

        int id = stoi(idStr);
        double salario = stod(salarioStr);
        return Empleado(id, nombre, direccion, telefono, email, salario, horario);
    }

    void mostrar() const override {
        Persona::mostrar();
        cout << "Salario: " << salario << ", Horario: " << horario << endl;
    }
};