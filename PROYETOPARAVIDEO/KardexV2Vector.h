//class KardexV2Vector
#pragma once
#include<iostream>
#include <stddef.h>
#include<vector>
#include<fstream>
#include"KardexV2.h"
using std::stoi;
using namespace std;
class KardexV2Vector
{
private:
	vector<KardexV2> vectorKardexV2;
public:
	/*
	KardexV2Vector()
	{
		//cargarDatosDelArchivoAlVector();
		vector<KardexV2> vectorKardexV2;
	}
	*/

	KardexV2Vector()
	{

	}

	~KardexV2Vector()
	{

	}
	int getCorrelativo()
	{
		if (vectorKardexV2.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorKardexV2[vectorKardexV2.size() - 1].getCodigo() + 1;
		}
	}

	void add(KardexV2 obj)/*Agrgar Objetos al Vector*/
	{
		vectorKardexV2.push_back(obj);
	}

	KardexV2 get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
	{
		return vectorKardexV2[pos];
	}

	int rows()
	{
		return vectorKardexV2.size();
	}


	KardexV2 buscarPorCodigo(int codigo)
	{
		KardexV2 objError;
		objError.setTipoCompra("Error");

		for (KardexV2 x : vectorKardexV2)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		// no poner return NULL;
		return vectorKardexV2[-1];
	}

	string buscarPorCodigoGettingNombrexD(int codigo)
	{
		KardexV2 objError;
		objError.setTipoCompra("Error");

		for (KardexV2 x : vectorKardexV2)
		{
			if (codigo == x.getCodigo())
			{
				return x.getNombre();
			}
		}
		// no poner return NULL;
		// return vectorKardexV2[-1];
	}

	KardexV2 buscarPorCodigo2(int codigo)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (codigo == get(i).getCodigo())
			{
				return get(i);
			}
		}
	}

	int getPostArray(KardexV2 obj)
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

	void remove(KardexV2 obj)
	{
		vectorKardexV2.erase(vectorKardexV2.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(KardexV2 cardex)
	{
		string testeoxd = "xd.csv";
		try
		{
			fstream archivoKardexV2;
			//archivoKardexV2.open("KArdexVTwo0.csv", ios::app);
			archivoKardexV2.open(testeoxd, ios::app);
			if (archivoKardexV2.is_open())
			{
				archivoKardexV2 << cardex.getCodigo() << ";" << cardex.getTipoCompra() << ";" << cardex.getValorUnitario() << ";" << cardex.getprecioProduct() << ";" << cardex.getEntradaCant() << ";" << cardex.getEntradaValor() << ";" << cardex.getSalidaCant() << ";" << cardex.getSalidaValor() << ";" << cardex.getSaldoCant() << ";" << cardex.getSaldoValor() << ";" << endl;

				archivoKardexV2.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!" << "\n";
		}
	}

	void V2grabarEnArchivoV2(KardexV2 cardex, string archivoNombre)
	{
		string elceseV = "KV2.csv";
		string concatenadosAmbos;

		concatenadosAmbos = archivoNombre + elceseV;
		try
		{
			fstream archivoKardexV2;
			//archivoKardexV2.open("KArdexVTwo0.csv", ios::app);
			archivoKardexV2.open(concatenadosAmbos, ios::app);
			if (archivoKardexV2.is_open())
			{
				// fecha - tipo de documento - tipo de operacion - codigo - descripcion - valor unitario - precio producto (ingresa) - entrada cantidad - entrada valor - salida cantidad - salida cantidad - saldo cantidad - saldo valor 
				archivoKardexV2 << cardex.getFecha() << ";" << cardex.getTipoDocumento() << ";" << cardex.getTipoOperacion() << ";" << cardex.getCodigo() << ";" << cardex.getTipoCompra() << ";" << cardex.getValorUnitario() << ";" << cardex.getprecioProduct() << ";" << cardex.getEntradaCant() << ";" << cardex.getEntradaValor() << ";" << cardex.getSalidaCant() << ";" << cardex.getSalidaValor() << ";" << cardex.getSaldoCant() << ";" << cardex.getSaldoValor() << ";" << endl;

				archivoKardexV2.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!" << "\n";
		}
	}

	void grabarModificarEliminarArchivo()
	{
		string testeoxd = "xd.csv";
		try
		{
			fstream archivoKardexV2;
			//archivoKardexV2.open("KArdexVTwo0.csv", ios::out);
			archivoKardexV2.open(testeoxd, ios::out);
			if (archivoKardexV2.is_open())
			{
				for (KardexV2 x : vectorKardexV2)
				{
					archivoKardexV2 << x.getCodigo() << ";" << x.getTipoCompra() << ";" << x.getValorUnitario() << ";" << x.getprecioProduct() << ";" << x.getEntradaCant() << ";" << x.getEntradaValor() << ";" << x.getSalidaCant() << ";" << x.getSalidaValor() << ";" << x.getSaldoCant() << ";" << x.getSaldoValor() << ";" << "\n";

				}
				archivoKardexV2.close();
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
			string testeoxd = "xd.csv";
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[10];//Cantidad de columnas
			fstream archivoKardexV2;
			//archivoKardexV2.open("KArdexVTwo0.csv", ios::in);
			archivoKardexV2.open(testeoxd, ios::in);
			if (archivoKardexV2.is_open())
			{
				while (!archivoKardexV2.eof())
				{
					while (getline(archivoKardexV2, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						KardexV2 kardexv2;

						kardexv2.setCodigo(std::stoi(temporal[0]));
						kardexv2.setTipoCompra(temporal[1]);
						kardexv2.setValorUnitario(std::stoi(temporal[2]));
						kardexv2.setprecioProduct(std::stoi(temporal[3]));
						kardexv2.setEntradaCant(std::stoi(temporal[4]));
						kardexv2.setEntradaValor(std::stoi(temporal[5]));
						kardexv2.setSalidaCant(std::stoi(temporal[6]));
						kardexv2.setSalidaValor(std::stoi(temporal[7]));
						kardexv2.setSaldoCant(std::stoi(temporal[8]));
						kardexv2.setSaldoValor(std::stoi(temporal[9]));

						add(kardexv2);
					}
				}
			}
			archivoKardexV2.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	void V2cargarDatosDelArchivoAlVectorV2(string archivoNombre)
	{
		string elCeseV = "KV2.csv";
		string concatenadoAmbos;

		concatenadoAmbos = archivoNombre + elCeseV;
		try
		{
			int i;
			//string testeoxd = "xd.csv";
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[13];//Cantidad de columnas
			fstream archivoKardexV2;
			//archivoKardexV2.open("KArdexVTwo0.csv", ios::in);
			archivoKardexV2.open(concatenadoAmbos, ios::in);
			if (archivoKardexV2.is_open())
			{
				while (!archivoKardexV2.eof())
				{
					while (getline(archivoKardexV2, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						KardexV2 kardexv2;
						// fecha - tipo de documento - tipo de operacion - codigo - descripcion
						//  - valor unitario - precio producto (ingresa) - entrada cantidad
						//  - entrada valor - salida cantidad - salida cantidad - saldo cantidad
						//  - saldo valor 
						kardexv2.setFecha(temporal[0]);
						kardexv2.setTipoDocumento(temporal[1]);
						kardexv2.setTipoOperacion(temporal[2]);
						kardexv2.setCodigo(std::stoi(temporal[3]));
						kardexv2.setTipoCompra(temporal[4]);
						kardexv2.setValorUnitario(std::stoi(temporal[5]));
						kardexv2.setprecioProduct(std::stoi(temporal[6]));
						kardexv2.setEntradaCant(std::stoi(temporal[7]));
						kardexv2.setEntradaValor(std::stoi(temporal[8]));
						kardexv2.setSalidaCant(std::stoi(temporal[9]));
						kardexv2.setSalidaValor(std::stoi(temporal[10]));
						kardexv2.setSaldoCant(std::stoi(temporal[11]));
						kardexv2.setSaldoValor(std::stoi(temporal[12]));

						add(kardexv2);
					}
				}
			}
			archivoKardexV2.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
};


