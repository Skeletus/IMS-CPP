#pragma once
//class KardexV2
#include<string>
#include"producto.h"
using namespace std;
class KardexV2 :public Producto
{
private:
	int		codigo;
	string	tipoOperacion;
	string	tipoDocumento;
	string	fecha;
	string	tipocompra;
	// === entradas
	int 	entradaCant;
	int 	entradaValor;
	// === valor unitario
	int		valorUnitario;
	// === salidas
	int		salidaCant;
	int		salidaValor;
	// === saldos
	int		saldoCant;
	int		saldoValor;
	int		precioProducto;

public:
	KardexV2(int _codigo, string _nombre, string _proveedor, int _cantidad, int _precio, int codigo, string fecha,
		string tipoDocumento, string tipoOperacion, string tipocompra, int entradaCant, int entradaValor, int valorUnitario, int salidaCant, int	salidaValor,
		int saldoCant, int	saldoValor, int precioProducto) :Producto(_codigo, _nombre, _proveedor, _cantidad, _precio)
	{
		this->codigo = codigo;
		this->tipoOperacion = tipoOperacion;
		this->tipoDocumento = tipoDocumento;
		this->fecha = fecha;
		this->tipocompra = tipocompra;
		this->entradaCant = entradaCant;
		this->entradaValor = entradaValor;
		this->valorUnitario = valorUnitario;
		this->salidaCant = salidaCant;
		this->salidaValor = salidaValor;
		this->saldoCant = saldoCant;
		this->saldoValor = saldoValor;
		this->precioProducto = precioProducto;
	}

	KardexV2()
	{

	}

	~KardexV2()
	{

	}

	void	setCodigo(int cod)
	{
		codigo = cod;
	}

	void	setFecha(string nom)
	{
		fecha = nom;
	}

	void	setTipoDocumento(string nom)
	{
		tipoDocumento = nom;
	}

	void	setTipoOperacion(string nom)
	{
		tipoOperacion = nom;
	}

	void	setTipoCompra(string nom)
	{
		tipocompra = nom;
	}

	void	setValorUnitario(int cod)
	{
		valorUnitario = cod;
	}

	void	setEntradaCant(int ent)
	{
		entradaCant = ent;
	}

	void	setEntradaValor(int ent)
	{
		entradaValor = ent;
	}

	void	setSalidaCant(int sal)
	{
		salidaCant = sal;
	}

	void	setSalidaValor(int sal)
	{
		salidaValor = sal;
	}

	void	setSaldoCant(int sal)
	{
		saldoCant = sal;
	}

	void	setSaldoValor(int sal)
	{
		saldoValor = sal;
	}

	void	setprecioProduct(int pre)
	{
		precioProducto = pre;
	}

	// ======== GETTERS

	int 	getCodigo()
	{
		return this->codigo;
	}

	string	getFecha()
	{
		return this->fecha;
	}

	string	getTipoDocumento()
	{
		return this->tipoDocumento;
	}

	string	getTipoOperacion()
	{
		return this->tipoOperacion;
	}

	string	getTipoCompra()
	{
		return this->tipocompra;
	}

	int		getValorUnitario()
	{
		return this->valorUnitario;
	}

	int		getEntradaCant()
	{
		return this->entradaCant;
	}

	int		getEntradaValor()
	{
		return this->entradaValor;
	}

	int		getSalidaCant()
	{
		return this->salidaCant;
	}

	int		getSalidaValor()
	{
		return this->salidaValor;
	}

	int		getSaldoCant()
	{
		return this->saldoCant;
	}

	int		getSaldoValor()
	{
		return this->saldoValor;
	}

	int		getprecioProduct()
	{
		return this->precioProducto;
	}

};



