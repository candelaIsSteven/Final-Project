#ifndef PERSONA_H  // Comienza con una macro de preprocesador
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    int id;
    string nombre;
    string direccion;
    string telefono;
    string email;

public:
    Persona(int id, const string& nombre, const string& direccion, const string& telefono, const string& email)
        : id(id), nombre(nombre), direccion(direccion), telefono(telefono), email(email) {}

    virtual void mostrar() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Dirección: " << direccion 
             << ", Teléfono: " << telefono << ", Email: " << email << endl;
    }

    virtual ~Persona() {} // Destructor virtual
};

#endif // PERSONA_H  // Termina con la misma macro
