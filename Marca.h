#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Marca {
private:
    int idMarca;
    string nombreMarca;

public:
    Marca(int id, string nombre) : idMarca(id), nombreMarca(nombre) {}

    // Método para guardar una marca en el archivo
    void guardarMarca(ofstream &archivo) const {
        archivo << idMarca << "," << nombreMarca << "\n";
    }

    // Método estático para cargar una marca desde una línea de archivo
    static Marca cargarMarca(const string &linea) {
        stringstream ss(linea);
        string idStr, nombre;
        getline(ss, idStr, ',');
        getline(ss, nombre, ',');

        int id = stoi(idStr);
        return Marca(id, nombre);
    }

    void mostrar() const {
        cout << "ID Marca: " << idMarca << ", Nombre: " << nombreMarca << endl;
    }
};