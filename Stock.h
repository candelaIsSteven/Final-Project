#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Stock {
private:
    int idStock;
    int idProducto;
    int existencias;
    int stockMinimo;

public:
    Stock(int id, int idProd, int exist, int minimo)
        : idStock(id), idProducto(idProd), existencias(exist), stockMinimo(minimo) {}

    void guardarStock(ofstream &archivo) const {
        archivo << idStock << "," << idProducto << "," << existencias << "," 
                << stockMinimo << "\n";
    }

    static Stock cargarStock(const string &linea) {
        stringstream ss(linea);
        string idStr, idProdStr, existStr, minimoStr;

        getline(ss, idStr, ',');
        getline(ss, idProdStr, ',');
        getline(ss, existStr, ',');
        getline(ss, minimoStr, ',');

        int id = stoi(idStr);
        int idProd = stoi(idProdStr);
        int exist = stoi(existStr);
        int minimo = stoi(minimoStr);

        return Stock(id, idProd, exist, minimo);
    }

    void mostrar() const {
        cout << "ID Stock: " << idStock << ", ID Producto: " << idProducto 
             << ", Existencias: " << existencias << ", Stock Mínimo: " 
             << stockMinimo << endl;
    }
};