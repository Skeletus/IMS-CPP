#pragma once
#include<string>
using namespace std;
class Vendedor
{
private:
	int 	codigo;
	string	nombre;
	int numTelefono;
	int DNI;

public:
	Vendedor()
	{

	}

	~Vendedor()
	{

	}

	void	setCodigo(int cod)
	{
		codigo = cod;
	}

	void	setNombre(string nom)
	{
		nombre = nom;
	}

	void	setNumeroTelefono(int num)
	{
		numTelefono = num;
	}

	void	setDNI(int deenei)
	{
		DNI = deenei;
	}

	// ======== GETTERS

	int 	getCodigo()
	{
		return this->codigo;
	}

	string 	getNombre()
	{
		return this->nombre;
	}

	int 	getNumeroTelefono()
	{
		return this->numTelefono;
	}

	int 	getDNI()
	{
		return this->DNI;
	}
};
