#include <vector>
#include <string>
#include "Producto.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class GestorProductos {
public:
    // Función para guardar todos los productos en un archivo
    static void guardarProductosEnArchivo(const vector<Producto> &productos, const string &nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (const auto &producto : productos) {
                producto.guardarProducto(archivo);
            }
            archivo.close();
            cout << "Datos de productos guardados correctamente en " << nombreArchivo << endl;
        } else {
            cerr << "No se pudo abrir el archivo para guardar." << endl;
        }
    }

    // Función para cargar productos desde un archivo
    static vector<Producto> cargarProductosDesdeArchivo(const string &nombreArchivo) {
        vector<Producto> productos;
        ifstream archivo(nombreArchivo);
        string linea;

        if (archivo.is_open()) {
            while (getline(archivo, linea)) {
                productos.push_back(Producto::cargarProducto(linea));
            }
            archivo.close();
            cout << "Datos de productos cargados correctamente desde " << nombreArchivo << endl;
        } else {
            cerr << "No se pudo abrir el archivo para cargar." << endl;
        }
        return productos;
    }
};