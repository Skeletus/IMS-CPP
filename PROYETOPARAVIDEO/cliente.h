//class cliente
#pragma once
#include <string>
using namespace std;
class Cliente
{
private:
    int         codigo;
    string      nombre;
    int    RUC;
public:
    Cliente(int _codigo, string _nombre, int _RUC)
    {
        codigo = _codigo;
        nombre = _nombre;
        RUC = _RUC;
    }

    Cliente()
    {

    }

    ~Cliente()
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

    void setRUC(int ruc)
    {
        RUC = ruc;
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

    int   getRUC()
    {
        return this->RUC;
    }

};


