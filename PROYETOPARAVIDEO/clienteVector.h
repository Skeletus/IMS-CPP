//class clienteVector
#pragma once
#include<iostream>
#include<stddef.h>
#include<vector>
#include<fstream>
#include<string>
#include"cliente.h"
using std::stoi;
using namespace std;
class ClienteVector
{
private:
	vector<Cliente> vectorCliente;
public:
	ClienteVector()
	{
		//V2cargarDatosDelArchivoAlVectorV2(nombreArchivo);
		cargarDatosDelArchivoAlVector();
		vector<Cliente> vectorCliente;
	}

	~ClienteVector()
	{

	}

	int getCorrelativo()
	{
		if (vectorCliente.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorCliente[vectorCliente.size() - 1].getCodigo() + 1;
		}
	}

	void add(Cliente obj) {
		vectorCliente.push_back(obj);
	}

	Cliente get(int pos)
	{
		return vectorCliente[pos];
	}

	int rows()
	{
		return vectorCliente.size();
	}

	Cliente buscarPorCodigo(int codigo)
	{
		Cliente objError;
		objError.setNombre("Error");

		for (Cliente x : vectorCliente)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorCliente[-1];
	}

	string buscarPorCodigoGettingNombre(int codigo)
	{
		Cliente objError;
		objError.setNombre("Error");

		for (Cliente x : vectorCliente)
		{
			if (codigo == x.getCodigo())
			{
				return x.getNombre();
			}
		}
		// no poner return NULL;
		//return vectorProducto[-1];
	}

	int getPostArray(Cliente obj)
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

	void remove(Cliente obj)
	{
		vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
	}

	bool modificarNombre(Cliente obj, string nom)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorCliente[i].setNombre(nom);
				return true;
			}
		}
		return false;
	}


	bool modificar(Cliente obj, string nom, long int ruk)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorCliente[i].setNombre(nom);
				vectorCliente[i].setRUC(ruk);
				return true;
			}
		}
		return false;
	}

	void grabarEnArchivo(Cliente cliente)
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("ListaClientesTest0.csv", ios::app);
			if (archivoCliente.is_open())
			{
				archivoCliente << cliente.getCodigo() << ";" << cliente.getNombre() << ";" << cliente.getRUC() << ";" << endl;
				archivoCliente.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	void grabarEnArchivoEntidad(Cliente cliente)
	{
		try
		{
			fstream archivoClienteEntidad;
			archivoClienteEntidad.open("ListClientesEntTest0.csv", ios::app);
			if (archivoClienteEntidad.is_open())
			{
				archivoClienteEntidad << cliente.getCodigo() << ";" << cliente.getNombre() << ";" << cliente.getRUC() << ";" << endl;
				archivoClienteEntidad.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	/*
	void V2grabarEnArchivoV2(Producto producto, string archivoNombre)
	{
		string elCeseV = ".csv";
		string concatenadoAmbos;

		concatenadoAmbos = archivoNombre + elCeseV;
		try
		{
			fstream archivoProductoV2;
			archivoProductoV2.open(concatenadoAmbos, ios::app);
			if (archivoProductoV2.is_open())
			{
				archivoProductoV2 << producto.getCodigo() << ";" << producto.getNombre() << ";" << producto.getCantidad() << ";" << producto.getPrecio() << ";" << endl;
				archivoProductoV2.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}
	*/

	void grabarModificarELiminarArchivo()
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("ListaClientesTest0.csv", ios::out);
			if (archivoCliente.is_open())
			{
				for (Cliente x : vectorCliente)
				{
					archivoCliente << x.getCodigo() << ";" << x.getNombre() << ";" << x.getRUC() << ";" << "\n";
				}
				archivoCliente.close();
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
			fstream archivoCliente;
			archivoCliente.open("ListaClientesTest0.csv", ios::in);
			if (archivoCliente.is_open())
			{
				while (!archivoCliente.eof())

				{
					while (getline(archivoCliente, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						Cliente cliente;

						cliente.setCodigo(std::stoi(temporal[0]));
						cliente.setNombre(temporal[1]);
						cliente.setRUC(std::stoi(temporal[2]));

						add(cliente);
					}
				}
			}
			archivoCliente.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	void cargarDatosDelArchivoAlVectorEntidad()
	{
		try
		{
			int i;
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[3];//Cantidad de columnas
			fstream archivoClienteEntidad;
			archivoClienteEntidad.open("ListClientesEntTest0.csv", ios::in);
			if (archivoClienteEntidad.is_open())
			{
				while (!archivoClienteEntidad.eof())

				{
					while (getline(archivoClienteEntidad, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						Cliente cliente;

						cliente.setCodigo(std::stoi(temporal[0]));
						cliente.setNombre(temporal[1]);
						cliente.setRUC(std::stoi(temporal[2]));

						add(cliente);
					}
				}
			}
			archivoClienteEntidad.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	/*
	void V2cargarDatosDelArchivoAlVectorV2(string archivoNombre)
	{
		string elCeseV = ".csv";
		string concatenadoAmbos;

		concatenadoAmbos = archivoNombre + elCeseV;
		try
		{
			int i;
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[4];//Cantidad de columnas
			fstream archivoProductoV2;
			archivoProductoV2.open(concatenadoAmbos, ios::in);
			if (archivoProductoV2.is_open())
			{
				while (!archivoProductoV2.eof())

				{
					while (getline(archivoProductoV2, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso ,
							i++;
						}
						//Asignando los valores al vector
						Producto producto;
						producto.setCodigo(std::stoi(temporal[0]));
						producto.setNombre(temporal[1]);
						producto.setCantidad(std::stoi(temporal[2]));
						producto.setPrecio(std::stoi(temporal[3]));
						add(producto);
					}
				}
			}
			archivoProductoV2.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}

	}
	*/
};

