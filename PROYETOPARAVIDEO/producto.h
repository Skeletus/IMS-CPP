#pragma once
#include <string>
using namespace std;
class Producto
{
private:
    int codigo;
    string nombre;
    string proveedor;
    int cantidad;
    int precio;

public:
    Producto(int _codigo, string _nombre, string _proveedor, int _cantidad, int _precio)
    {
        codigo = _codigo;
        nombre = _nombre;
        proveedor = _proveedor;
        cantidad = _cantidad;
        precio = _precio;
    }

    Producto()
    {

    }

    ~Producto()
    {

    }
    //SET
    void setCodigo(int code)
    {
        codigo = code;
    }

    void setNombre(std::string name)
    {
        nombre = name;
    }

    void setProveedor(std::string name)
    {
        proveedor = name;
    }

    void setCantidad(int n)
    {
        cantidad = n;
    }

    void setPrecio(int p)
    {
        precio = p;
    }

    //GET
    int getCodigo()
    {
        return this->codigo;
    }

    std::string getNombre()
    {
        return this->nombre;
    }

    std::string getProveedor()
    {
        return this->proveedor;
    }

    int getCantidad()
    {
        return this->cantidad;
    }

    int getPrecio()
    {
        return this->precio;
    }

};
