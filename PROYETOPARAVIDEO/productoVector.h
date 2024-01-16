#pragma once
#include<iostream>
#include<stddef.h>
#include<vector>
#include<fstream>
#include<string>
#include"producto.h"
using std::stoi;
using namespace std;
class ProductoVector
{
private:
	vector<Producto> vectorProducto;
public:
	ProductoVector()
	{
		//V2cargarDatosDelArchivoAlVectorV2(nombreArchivo);
		cargarDatosDelArchivoAlVector();
		vector<Producto> vectorProducto;
	}

	~ProductoVector()
	{

	}

	int getCorrelativo()
	{
		if (vectorProducto.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorProducto[vectorProducto.size() - 1].getCodigo() + 1;
		}
	}

	void add(Producto obj) {
		vectorProducto.push_back(obj);
	}

	Producto get(int pos)
	{
		return vectorProducto[pos];
	}

	int rows()
	{
		return vectorProducto.size();
	}

	Producto buscarPorCodigo(int codigo)
	{
		Producto objError;
		objError.setNombre("Error");

		for (Producto x : vectorProducto)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorProducto[-1];
	}

	string buscarPorCodigoGettingNombre(int codigo)
	{
		Producto objError;
		objError.setNombre("Error");

		for (Producto x : vectorProducto)
		{
			if (codigo == x.getCodigo())
			{
				return x.getNombre();
			}
		}
		// no poner return NULL;
		//return vectorProducto[-1];
	}

	int getPostArray(Producto obj)
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

	void remove(Producto obj)
	{
		vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
	}

	bool modificarNombre(Producto obj, string nom)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setNombre(nom);
				return true;
			}
		}
		return false;
	}

	bool modificarCantidadStockYPRECIO(Producto obj, int cant, int price)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setCantidad(cant);
				vectorProducto[i].setPrecio(price);
				return true;
			}
		}
		return false;
	}

	bool modificarCantidadStock(Producto obj, int cant)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setCantidad(cant);
				return true;
			}
		}
		return false;
	}

	bool modificarPrecio(Producto obj, int price)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setPrecio(price);
				return true;
			}
		}
		return false;
	}

	bool modificar(Producto obj, string nom, int price, int cant)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setNombre(nom);
				vectorProducto[i].setPrecio(price);
				vectorProducto[i].setCantidad(cant);
				return true;
			}
		}
		return false;
	}

	void grabarEnArchivo(Producto producto)
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("ListaProductosTest02.csv", ios::app);
			if (archivoProducto.is_open())
			{
				archivoProducto << producto.getCodigo() << ";" << producto.getNombre() << ";" << producto.getProveedor() << ";" << producto.getCantidad() << ";" << producto.getPrecio() << ";" << endl;
				archivoProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

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

	void grabarModificarELiminarArchivo()
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("ListaProductosTest02.csv", ios::out);
			if (archivoProducto.is_open())
			{
				for (Producto x : vectorProducto)
				{
					archivoProducto << x.getCodigo() << ";" << x.getNombre() << ";" << x.getProveedor() << ";" << x.getCantidad() << ";" << x.getPrecio() << ";" << "\n";
				}
				archivoProducto.close();
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
			string temporal[5];//Cantidad de columnas
			fstream archivoProducto;
			archivoProducto.open("ListaProductosTest02.csv", ios::in);
			if (archivoProducto.is_open())
			{
				while (!archivoProducto.eof())

				{
					while (getline(archivoProducto, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						Producto producto;
						producto.setCodigo(std::stoi(temporal[0]));
						producto.setNombre(temporal[1]);
						producto.setProveedor(temporal[2]);
						producto.setCantidad(std::stoi(temporal[3]));
						producto.setPrecio(std::stoi(temporal[4]));
						add(producto);
					}
				}
			}
			archivoProducto.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

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
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
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
};
