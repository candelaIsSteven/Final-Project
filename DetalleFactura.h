#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class DetalleFactura {
private:
    int idDetalleFactura;
    int idFactura;
    int cantidadProductos;
    int idProducto;
    double valorProducto;

public:
    DetalleFactura(int idDetalle, int idFac, int cant, int idProd, double valor)
        : idDetalleFactura(idDetalle), idFactura(idFac), cantidadProductos(cant),
          idProducto(idProd), valorProducto(valor) {}

    void guardarDetalle(ofstream &archivo) const {
        archivo << idDetalleFactura << "," << idFactura << "," << cantidadProductos 
                << "," << idProducto << "," << valorProducto << "\n";
    }

    static DetalleFactura cargarDetalle(const string &linea) {
        stringstream ss(linea);
        string idDetalleStr, idFacStr, cantStr, idProdStr, valorStr;

        getline(ss, idDetalleStr, ',');
        getline(ss, idFacStr, ',');
        getline(ss, cantStr, ',');
        getline(ss, idProdStr, ',');
        getline(ss, valorStr, ',');

        int idDetalle = stoi(idDetalleStr);
        int idFac = stoi(idFacStr);
        int cant = stoi(cantStr);
        int idProd = stoi(idProdStr);
        double valor = stod(valorStr);

        return DetalleFactura(idDetalle, idFac, cant, idProd, valor);
    }

    void mostrar() const {
        cout << "ID Detalle Factura: " << idDetalleFactura << ", ID Factura: " 
             << idFactura << ", Cantidad Productos: " << cantidadProductos 
             << ", ID Producto: " << idProducto << ", Valor Producto: " 
             << valorProducto << endl;
    }
};