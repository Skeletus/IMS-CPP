//class UsuarioVersion2Vector
#pragma once
#include<iostream>
#include <stddef.h>
#include<vector>
#include<fstream>
#include"UsuarioVersion2.h"
using std::stoi;
using namespace std;
class UsuarioVersion2Vector
{
private:
	vector<UsuarioVersion2> vectorUsuarioVer2;
public:
	UsuarioVersion2Vector()
	{
		cargarDatosDelArchivoAlVector();
		vector<UsuarioVersion2> vectorUsuarioVer2;
	}
	int getCorrelativo()
	{
		if (vectorUsuarioVer2.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorUsuarioVer2[vectorUsuarioVer2.size() - 1].getCodigo() + 1;
		}
	}

	void add(UsuarioVersion2 obj)/*Agrgar Objetos al Vector*/
	{
		vectorUsuarioVer2.push_back(obj);
	}

	UsuarioVersion2 get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
	{
		return vectorUsuarioVer2[pos];
	}

	int rows()
	{
		return vectorUsuarioVer2.size();
	}


	UsuarioVersion2 buscarPorCodigo(int codigo)
	{
		UsuarioVersion2 objError;
		objError.setNombreUsuario("Error");

		for (UsuarioVersion2 x : vectorUsuarioVer2)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorUsuarioVer2[-1];
	}

	UsuarioVersion2 buscarPorNombre(string nam)
	{
		UsuarioVersion2 objError;
		objError.setNombreUsuario("Error");

		for (UsuarioVersion2 x : vectorUsuarioVer2)
		{
			if (nam == x.getNombreUsuario())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorUsuarioVer2[-1];
	}

	UsuarioVersion2 buscarPorCodigo2(int codigo)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (codigo == get(i).getCodigo())
			{
				return get(i);
			}
		}
	}

	int getPostArray(UsuarioVersion2 obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(UsuarioVersion2 obj)
	{
		vectorUsuarioVer2.erase(vectorUsuarioVer2.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(UsuarioVersion2 user)
	{
		try
		{
			fstream archivoUsuariosVER2;
			archivoUsuariosVER2.open("UserfilesVER20.bin", ios::app);
			if (archivoUsuariosVER2.is_open())
			{
				archivoUsuariosVER2 << user.getCodigo() << ";" << user.getNombreUsuario() << ";" << user.getPassword() << ";" << endl;

				archivoUsuariosVER2.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!" << "\n";
		}
	}

	void grabarModificarEliminarArchivo()
	{
		try
		{
			fstream archivoUsuariosVER2;
			archivoUsuariosVER2.open("UserfilesVER20.bin", ios::out);
			if (archivoUsuariosVER2.is_open())
			{
				for (UsuarioVersion2 x : vectorUsuarioVer2)
				{
					archivoUsuariosVER2 << x.getCodigo() << ";" << x.getNombreUsuario() << ";" << x.getPassword() << ";" << "\n";

				}
				archivoUsuariosVER2.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo";
		}
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[3];//Cantidad de columnas
			fstream archivoUsuariosVER2;
			archivoUsuariosVER2.open("UserfilesVER20.bin", ios::in);
			if (archivoUsuariosVER2.is_open())
			{
				while (!archivoUsuariosVER2.eof())
				{
					while (getline(archivoUsuariosVER2, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						UsuarioVersion2 user;

						user.setCodigo(std::stoi(temporal[0]));
						user.setNombreUsuario(temporal[1]);
						user.setPassword(temporal[2]);

						add(user);
					}
				}
			}
			archivoUsuariosVER2.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
};