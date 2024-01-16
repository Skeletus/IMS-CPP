#pragma once
#include<iostream>
#include <stddef.h>
#include<vector>
#include<fstream>
#include"vendedor.h"
using std::stoi;
using namespace std;
class VendedorVector
{
private:
	vector<Vendedor> vectorVendedor;
public:
	VendedorVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<Vendedor> vectorVendedor;
	}
	int getCorrelativo()
	{
		if (vectorVendedor.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorVendedor[vectorVendedor.size() - 1].getCodigo() + 1;
		}
	}

	void add(Vendedor obj)/*Agrgar Objetos al Vector*/
	{
		vectorVendedor.push_back(obj);
	}

	Vendedor get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
	{
		return vectorVendedor[pos];
	}

	int rows()
	{
		return vectorVendedor.size();
	}


	Vendedor buscarPorCodigo(int codigo)
	{
		Vendedor objError;
		objError.setNombre("Error");

		for (Vendedor x : vectorVendedor)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorVendedor[-1];
	}
	Vendedor buscarPorCodigo2(int codigo)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (codigo == get(i).getCodigo())
			{
				return get(i);
			}
		}
	}

	int getPostArray(Vendedor obj)
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

	void remove(Vendedor obj)
	{
		vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));
	}


	bool modificar(Vendedor obj, string nom, int denei, int numbercel)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorVendedor[i].setNombre(nom);
				vectorVendedor[i].setDNI(denei);
				vectorVendedor[i].setNumeroTelefono(numbercel);
				return true;
			}
		}
		return false;
	}
	void grabarEnArchivo(Vendedor vendedor)
	{
		try
		{
			fstream archivoVendedor;
			archivoVendedor.open("vendedor5.csv", ios::app);
			if (archivoVendedor.is_open())
			{
				archivoVendedor << vendedor.getCodigo() << ";" << vendedor.getNombre() << ";" << vendedor.getDNI() << ";" << vendedor.getNumeroTelefono() << ";" << endl;

				archivoVendedor.close();
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
			fstream archivoVendedores;
			archivoVendedores.open("vendedor5.csv", ios::out);
			if (archivoVendedores.is_open())
			{
				for (Vendedor x : vectorVendedor)
				{
					archivoVendedores << x.getCodigo() << ";" << x.getNombre() << ";" << x.getDNI() << x.getNumeroTelefono() << ";" << "\n";

				}
				archivoVendedores.close();
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
			string temporal[4];//Cantidad de columnas
			fstream archivoVendedor;
			archivoVendedor.open("vendedor5.csv", ios::in);
			if (archivoVendedor.is_open())
			{
				while (!archivoVendedor.eof())
				{
					while (getline(archivoVendedor, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						Vendedor vendedor;
						vendedor.setCodigo(std::stoi(temporal[0]));
						vendedor.setNombre(temporal[1]);
						vendedor.setDNI(std::stoi(temporal[2])); //setNumeroTelefono
						vendedor.setNumeroTelefono(std::stoi(temporal[3]));
						add(vendedor);
					}
				}
			}
			archivoVendedor.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
};

