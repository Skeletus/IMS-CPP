//class UsuarioVersion2
#pragma once
#include<string>
using namespace std;
class UsuarioVersion2
{
private:
	int		codigo;
	string	nombreUsuario;
	string	password;
public:
	UsuarioVersion2()
	{

	}

	~UsuarioVersion2()
	{

	}

	void	setCodigo(int cod)
	{
		codigo = cod;
	}

	void	setNombreUsuario(string nom)
	{
		nombreUsuario = nom;
	}

	void	setPassword(string nom)
	{
		password = nom;
	}

	// ======== GETTERS

	int 	getCodigo()
	{
		return this->codigo;
	}

	string	getNombreUsuario()
	{
		return this->nombreUsuario;
	}

	string	getPassword()
	{
		return this->password;
	}

};