#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Producto {
private:
    int idProducto;
    string descripcionProducto;
    int idMarca;
    double valorProducto;

public:
    Producto(int id, string desc, int idM, double valor)
        : idProducto(id), descripcionProducto(desc), idMarca(idM), valorProducto(valor) {}

    // Método para guardar un producto en el archivo
    void guardarProducto(ofstream &archivo) const {
        archivo << idProducto << "," << descripcionProducto << "," << idMarca << "," << valorProducto << "\n";
    }

    // Método estático para cargar un producto desde una línea de archivo
    static Producto cargarProducto(const string &linea) {
        stringstream ss(linea);
        string idStr, desc, idMarcaStr, valorStr;
        getline(ss, idStr, ',');
        getline(ss, desc, ',');
        getline(ss, idMarcaStr, ',');
        getline(ss, valorStr, ',');

        int id = stoi(idStr);
        int idMarca = stoi(idMarcaStr);
        double valor = stod(valorStr);

        return Producto(id, desc, idMarca, valor);
    }

    void mostrar() const {
        cout << "ID: " << idProducto << ", Descripción: " << descripcionProducto
             << ", ID Marca: " << idMarca << ", Valor: " << valorProducto << endl;
    }
};