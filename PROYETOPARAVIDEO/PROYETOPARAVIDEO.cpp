// TheTrueDefinitvePOO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
// archivos header KARDEX VERSION 2mejorados
#include "KardexV2.h"
#include "KardexV2Vector.h"
// archivos CLASES PRODUCTO
#include "producto.h"
#include "productoVector.h"
// archivos CLASES VENDEDOR
#include"vendedor.h"
#include"vendedorVector.h"
// archivos CLASES USUARIOS VERSION 2
#include "UsuarioVersion2.h"
#include "UsuarioVersion2Vector.h"
// archivos CLASES CLIENTE
#include"cliente.h"
#include"clienteVector.h"
#include"clienteVectorEntidad.h"

using namespace std;

// VARIABLE GLOBAL
int logeoCorrecto = 0;

// vectores string GLOBALES
// strings at index 0 is not used, it is to make array
// indexing simple
string one[] = { "", "UNO ", "DOS ", "TRES ", "CUATRO ",
				 "CINCO ", "SEIS ", "SIETE ", "OCHO ",
				 "NUEVE ", "DIEZ ", "ONCE ", "DOCE ",
				 "TRECE ", "CATORCE ", "QUINCE ",
				 "DIECISEIS ", "DIECISIETE ", "DIECIOCHO ",
				 "DIECINUEVE " };

// strings at index 0 and 1 are not used, they is to
	// make array indexing simple
string ten[] = { "", "", "VEINTE Y ", "TREINTA Y ", "CUARENTA Y ",
				 "CINCUENTA Y ", "SESENTA Y ", "SETENTA Y ", "OCHENTA Y ",
				 "NOVENTA Y " };

//Crear un Objeto
VendedorVector vendedorVector;//Instancia de la clase AlumnoVector

//Creando otro objeto
ProductoVector productoVector;//Instancia de la clase ProductoVector

//Creando otro objeto KARDEX MEJORADO
KardexV2Vector kardexVectorv2;//Instancia de la clase KardexVector V2

//Crear un objeto
ClienteVector  clienteVector;//Instancia de la clase Cliente

//Crear un objeto
ClienteVectorEntidad  clienteVectorEntidad;//Instancia de la clase Cliente ENTIDAD 

//Crear un objeto
UsuarioVersion2Vector usuarioVectorVERSION2;//Instancia de la clase Cliente ENTIDAD 

//Prototipos
// ==== funcion para convertir numeros a letras
string	NumeroALetra(int, string);
string	convertirNumeroALetra(int);
// ==== MENU DE OPCIONES
void 	menuDeOpciones();
void	logeoORegistro();
void	mostrarFuncionesKARDEX();
void	mostrarFuncionesVENDEDOR();
void	mostrarFuncionesCLIENTE();
void	mostrarFuncionesPRODUCTO();
// ==== funciones de registro o inicio
void	registrarUsuarioVERSION2();
void	logearUsuarioVERSION2();
string	encriptar(string);
void	registrarUsuario();
void	logearUsuario();
// === funciones vendedor 
void 	adicionarVendedor();
void 	eliminarVendedor();
void	modificarVendedor();
void	buscarVendedor();
void	listarVendedor();
// === funciones cliente
void 	adicionarClientePersona();
void 	adicionarClienteEntidad();
void 	eliminarCliente();
void	modificarCliente();
void	buscarCliente();
void	listarCliente();
// === funciones producto
void	adicionarProducto();
void 	eliminarProducto();
void	modificarProducto();
void	buscarProducto();
void	listarProducto();
// === funciones VENTAS
void	realizarVenta();
void	mostrarVentas();
// === funciones Kardex Avanzadas (v2 mejoradas)
void	listarProductoParaKARDEXV2();
void	buscarProductoParaKardexV2();
void	V2entradaKardexV2();
void	V2salidaKardexV2();
void	V2listarKardexV2();

int main()
{
	logeoORegistro();
	if (logeoCorrecto == 1)
	{
		menuDeOpciones();
	}
	//menuDeOpciones();
}

//Implementacion
void menuDeOpciones()
{
	//Declarar Variables

	int opt;
	int opcionPrueuba;
	do
	{
		cout << "\n";
		cout << "\t" << "++" << " =============== MENU DE OPCIONES  =============== " << "++" << "\t" << endl;
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " ============= FUNCIONES VENDEDOR  =============== " << "++" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 1. MOSTRAR FUNCIONES == > " << "                     " << "||" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " ============= FUNCIONES CLIENTE ================= " << "++" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 2. MOSTRAR FUNCIONES == > " << "                     " << "||" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " ============= FUNCIONES PRODUCTOS =============== " << "++" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 3. MOSTRAR FUNCIONES == > " << "                     " << "||" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " =============== FUNCIONES VENTAS ================ " << "++" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 4. MOSTRAR FUNCIONES == > " << "                     " << "||" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " =========== FUNCIONES KARDEX MEJORADAS ========== " << "++" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 5. MOSTRAR FUNCIONES == > " << "                     " << "||" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "||" << " == 6. Salir == > " << "                                 " << "||" << "\t" << "\n";
		cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
		cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
		cout << "\n";
		cout << "\t" << "== DIGITE UNA OPCION ( 1 | 2 | 3 | 4 | 5 | 6) == > ";

		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			mostrarFuncionesVENDEDOR();
			break;
		case 2:
			system("cls");
			mostrarFuncionesCLIENTE();
			break;
		case 3:
			system("cls");
			mostrarFuncionesPRODUCTO();
			break;
		case 4:
			system("cls");
			realizarVenta();
			break;
		case 5:
			system("cls");
			mostrarFuncionesKARDEX();
			break;
		case 6:
			cout << "\n";
			cout << "\t" << "=========  Gracias por tu tiempo !!!! =========\n";
			exit(0);
			break;
			// === FUNCION SALIDA (END)
		default:
			cout << "Ingrese una opcion correcta [1-6] !! " << endl;
		}
	} while (opt != 6);
}

void adicionarVendedor()
{
	//Crear Variables
	int 	cod;
	int numDeTelefono;
	int Dni;
	string 	nom;
	string	rpta;
	//Crear el Objeto de la clase alumno
	do
	{
		//Entrada de datos
		cod = vendedorVector.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Ingresar Nombre: ";
		getline(cin, nom);

		cout << "Ingresar DNI: ";
		cin >> Dni;
		cin.ignore();

		cout << "Ingresar Numero de telefono: ";
		cin >> numDeTelefono;
		cin.ignore();

		Vendedor vendedor;/*Crear el Objeto*/

		vendedor.setCodigo(cod);
		vendedor.setNombre(nom);
		vendedor.setNumeroTelefono(numDeTelefono);
		vendedor.setDNI(Dni);

		vendedorVector.add(vendedor);//Agregar el Objeto al vector dinamico

		vendedorVector.grabarEnArchivo(vendedor);

		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");

}


void listarVendedor()
{
	cout << "\t" << "++==============================================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "    NOMBRE" << setw(15) << "    NUMERO DE TELEFONO" << setw(10) << "DNI" << setw(7) << "||" << "\n";
	for (int i = 0; i < vendedorVector.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << vendedorVector.get(i).getCodigo() << setw(15) << vendedorVector.get(i).getNombre() << setw(15) << vendedorVector.get(i).getNumeroTelefono() << setw(18) << vendedorVector.get(i).getDNI() << setw(6) << "||" << "\n";
	}
	cout << "\t" << "++==============================================================++" << "\n";
	cout << "\n";
	system("pause");
	system("cls");
}



void eliminarVendedor()
{
	int cod;
	cout << "Ingresar el codigo a eliminar:";
	cin >> cod;
	Vendedor objAEliminar = vendedorVector.buscarPorCodigo(cod);
	if (objAEliminar.getNombre() != "Error")
	{
		vendedorVector.remove(objAEliminar);
		cout << "Registro Eliminado Satisfactoriamente";
		vendedorVector.grabarModificarEliminarArchivo();
	}
	else
	{
		cout << "No se encontro el registro!\n";
	}

}



void modificarVendedor()
{
	int cod;
	cout << "Ingresar el codigo a modificar:";
	cin >> cod;
	Vendedor objAModificar = vendedorVector.buscarPorCodigo(cod);

	cout << "Registro Encontrado\n";
	cout << "Codigo: " << objAModificar.getCodigo() << "\n";
	cout << "Nombre: " << objAModificar.getNombre() << "\n";
	cout << "DNI: " << objAModificar.getDNI() << "\n";
	cout << "NUMERO DE TELEFONO: " << objAModificar.getNumeroTelefono() << "\n";
	cin.ignore();

	string nomModificado;
	int dniModificado;
	int numberModificado;

	cout << "Modificar campos\n";

	cout << "ESCRIBIR NOMBRE\n";
	getline(cin, nomModificado);

	cout << "ESCRIBIR DNI\n";
	cin >> dniModificado;

	cout << "ESCRIBIR NUMERO DE TELEFONO\n";
	cin >> numberModificado;

	// bool modificar(Vendedor obj, string NOMBRE, int DNI, int NUMERO);
	bool estado = vendedorVector.modificar(objAModificar, nomModificado, dniModificado, numberModificado);
	if (estado = true)
	{
		cout << "Registro Modificado Satisfactoriamente\n";
		//Grabar en archivo
		vendedorVector.grabarModificarEliminarArchivo();
	}
	else
	{
		cout << "No se Edito el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
	system("cls");
}


void buscarVendedor()
{
	int cod;
	cout << "Ingresar el codigo a buscar:";
	cin >> cod;
	Vendedor alu = vendedorVector.buscarPorCodigo(cod);
	if (alu.getNombre() != "Error")
	{
		cout << "Registro Encontrado\n";
		cout << "Codigo: " << alu.getCodigo() << "\n";
		cout << "Nombre: " << alu.getNombre() << "\n";
		cout << "DNI: " << alu.getDNI() << "\n";
		cout << "NUMERO DE TELEFONO: " << alu.getNumeroTelefono() << "\n";
	}
	else
	{
		cout << "No se encontro el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
}

void adicionarClientePersona()
{
	//Crear Variables
	int 	  cod;
	int  dni;
	string 	  nom;
	string	  rpta;
	//Crear el Objeto de la clase Cliente
	do
	{
		//Entrada de datos
		cod = clienteVector.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Ingresar Nombre: ";
		getline(cin, nom);

		cout << "Ingresar DNI: ";
		cin >> dni;
		cin.ignore();

		Cliente cliente;/*Crear el Objeto*/

		cliente.setCodigo(cod);
		cliente.setNombre(nom);
		cliente.setRUC(dni);

		clienteVector.add(cliente);//Agregar el Objeto al vector dinamico

		clienteVector.grabarEnArchivo(cliente);

		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");

}

void 	adicionarClienteEntidad()
{
	//Crear Variables
	int 	  cod;
	int		  dni;
	string 	  nom;
	string	  rpta;
	//Crear el Objeto de la clase Cliente
	do
	{
		//Entrada de datos
		cod = clienteVectorEntidad.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Ingresar Nombre: ";
		getline(cin, nom);

		cout << "Ingresar RUC: ";
		cin >> dni;
		cin.ignore();

		Cliente cliente;/*Crear el Objeto*/

		cliente.setCodigo(cod);
		cliente.setNombre(nom);
		cliente.setRUC(dni);

		clienteVectorEntidad.add(cliente);//Agregar el Objeto al vector dinamico

		clienteVectorEntidad.grabarEnArchivo(cliente);

		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");
}


void listarCliente()
{

	cout << "\t" << setw(15) << "           LISTA DE CLIENTES PERSONAS" << "\n";
	cout << "\t" << "++===============================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "    NOMBRE" << setw(15) << " DNI " << setw(9) << "||" << "\n";
	cout << "\t" << "++===============================================++" << "\n";
	for (int i = 0; i < clienteVector.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << clienteVector.get(i).getCodigo() << setw(15) << clienteVector.get(i).getNombre() << setw(15) << clienteVector.get(i).getRUC() << setw(9) << "||" << "\n";
	}
	cout << "\t" << "++===============================================++" << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\t" << setw(15) << "           LISTA DE CLIENTES ENTIDADES" << "\n";
	cout << "\t" << "++===============================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "    NOMBRE" << setw(15) << " RUC " << setw(9) << "||" << "\n";
	cout << "\t" << "++===============================================++" << "\n";
	for (int i = 0; i < clienteVectorEntidad.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << clienteVectorEntidad.get(i).getCodigo() << setw(15) << clienteVectorEntidad.get(i).getNombre() << setw(15) << clienteVectorEntidad.get(i).getRUC() << setw(9) << "||" << "\n";
	}
	cout << "\t" << "++===============================================++" << "\n";
	cout << "\n";
	system("pause");
	system("cls");
}



void eliminarCliente()
{
	int cod;
	cout << "Ingresar el codigo a eliminar:";
	cin >> cod;
	Cliente objAEliminar = clienteVector.buscarPorCodigo(cod);
	if (objAEliminar.getNombre() != "Error")
	{
		clienteVector.remove(objAEliminar);
		cout << "Registro Eliminado Satisfactoriamente";
		clienteVector.grabarModificarELiminarArchivo();
	}
	else
	{
		cout << "No se encontro el registro!\n";
	}

}



void modificarCliente()
{
	int cod;
	cout << "Ingresar el codigo a modificar:";
	cin >> cod;
	Cliente objAModificar = clienteVector.buscarPorCodigo(cod);

	cout << "Registro Encontrado\n";
	cout << "Codigo: " << objAModificar.getCodigo() << "\n";
	cout << "Nombre: " << objAModificar.getNombre() << "\n";
	cout << "DNI o RUC: " << objAModificar.getRUC() << "\n";
	cin.ignore();

	string nomModificado;
	long int dniModificado;

	cout << "Modificar campos\n";

	cout << "ESCRIBIR NOMBRE\n";
	getline(cin, nomModificado);

	cout << "ESCRIBIR RUC\n";
	cin >> dniModificado;

	// bool modificar(Vendedor obj, string NOMBRE, int DNI, int NUMERO);
	bool estado = clienteVector.modificar(objAModificar, nomModificado, dniModificado);
	if (estado = true)
	{
		cout << "Registro Modificado Satisfactoriamente\n";
		//Grabar en archivo
		clienteVector.grabarModificarELiminarArchivo();
	}
	else
	{
		cout << "No se Edito el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
	system("cls");
}


void buscarCliente()
{
	int cod;
	cout << "Ingresar el codigo a buscar:";
	cin >> cod;
	Cliente cliente = clienteVector.buscarPorCodigo(cod);
	if (cliente.getNombre() != "Error")
	{
		cout << "Registro Encontrado\n";
		cout << "Codigo: " << cliente.getCodigo() << "\n";
		cout << "Nombre: " << cliente.getNombre() << "\n";
		cout << "DNI: " << cliente.getRUC() << "\n";
	}
	else
	{
		cout << "No se encontro el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
}

void  logeoORegistro()
{
	int opcion;

	cout << "\t" << "++===================================++" << "\n";
	cout << "\t" << "||" << setw(5) << " 1. Registrar Usuario " << setw(15) << "||" << "\n";
	cout << "\t" << "||" << setw(5) << " 2. Logear Usuario    " << setw(15) << "||" << "\n";
	cout << "\t" << "++===================================++" << "\n";
	cout << "\n";
	cout << "\t" << "Digite una opcion ( 1 | 2 )==== >> ";

	cin >> opcion;
	switch (opcion)
	{
	case 1:
		system("cls");
		registrarUsuarioVERSION2();
		//registrarUsuario();
		break;
	case 2:
		system("cls");
		logearUsuarioVERSION2();
		//logearUsuario();
		break;
	default:
		cout << "Ingrese una opcion correcta[1-2] !!" << endl;
	}

	system("pause");
}

string encriptar(string str)
{
	for (int i = 0; (i < 100 && str[i] != '\0'); i++) {
		str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value
	}
	return str;
}


void	registrarUsuarioVERSION2()
{
	//Crear Variables
	int 	cod;
	string	userNick;
	string	contra;
	string	encriptedContra;

	//Crear el Objeto de la clase usuario
	//Entrada de datos
	cod = usuarioVectorVERSION2.getCorrelativo();

	cout << "Codigo(" << cod << ")" << endl;
	cin.ignore();

	cout << "Digite su nombre de usuario (NO usar espacio): ";
	getline(cin, userNick);
	cin.ignore();

	cout << "Escriba su password (NO usar espacio): ";
	getline(cin, contra);
	cin.ignore();

	encriptedContra = encriptar(contra);

	UsuarioVersion2 usuario;/*Crear el Objeto*/

	usuario.setCodigo(cod);
	usuario.setNombreUsuario(userNick);
	usuario.setPassword(encriptedContra);

	usuarioVectorVERSION2.add(usuario);//Agregar el Objeto al vector dinamico
	usuarioVectorVERSION2.grabarEnArchivo(usuario);

	system("cls");//Limpiar
}



void	logearUsuarioVERSION2()
{
	//Crear Variables
	int 	cod;
	int		band = 0;
	int		bandIntentos = 0;
	int		bandIntentosRestantes = 3;
	string	userNick;
	string	contra;
	string	encriptedContra;

	//Crear el Objeto de la clase usuario
	// entrada de datos
	cin.ignore();
	cout << "Digite su nombre de usuario (NO usar espacio): ";
	getline(cin, userNick);

	UsuarioVersion2 objAVerificar = usuarioVectorVERSION2.buscarPorNombre(userNick);

	// algoritmo
	if (userNick.compare(objAVerificar.getNombreUsuario()) == 0)
	{
		cout << "SII EXISTE !!" << "\n";

		do
		{
			cout << "\nEscriba su password (NO usar espacio): ";
			getline(cin, contra);
			// hola1234
			// mkjhas356 
			// mkjhas356
				  //cin.ignore();

			contra = encriptar(contra);

			if (contra.compare(objAVerificar.getPassword()) == 0)
			{
				cout << "\nPASSWROD VERIFICADA !!" << endl;
				band = 1;
				logeoCorrecto = 1;
				system("pause");
				break;
			}
			else
			{
				cout << "\nPASSWROD INCORRECTA !!" << endl;
				cout << "Intentelo de nuevo " << endl;
				cout << "Numero de intentos restantes -> " << bandIntentosRestantes << endl;
				bandIntentosRestantes = bandIntentosRestantes - 1;
				bandIntentos = bandIntentos + 1;
			}
		} while (bandIntentos < 4);

		if (bandIntentos == 4)
		{
			cout << "\nNumero de intentos excedido !! " << endl;
			system("pause");
		}
	}
	else
	{
		cout << "NO EXISTE ESE USUARIO";
		system("pause");
	}

	system("cls");//Limpiar
}

void	adicionarProducto()
{
	//Crear Variables
	int			code;
	string 		nom;
	string		eltipoDocumentoxd;
	string		fechaConcatenada;
	string		eltipoOperacion = "02";
	string		day;
	string		month;
	string		year;
	string		elproveedor;
	//string		elproveedorConcatenado; /****/
	int			cant;
	int			precioConGanancia;
	int			precio;
	string		rpta;
	// variables para el kardex version 2
	int			valorInventairoV2;

	/*

	// Creando otro objeto

	ProductoVector productoVectorCREADO;//Instancia de la clase ProductoVector

	productoVectorCREADO.V2cargarDatosDelArchivoAlVectorV2(nom);

	*/

	do
	{
		//Entrada de datos
		code = productoVector.getCorrelativo();

		cout << "Codigo(" << code << ")" << endl;
		cin.ignore();

		cout << "Ingresar Nombre: ";
		getline(cin, nom);
		//cin.ignore();

		cout << "Llenar con 7 carac: ABCDEFG" << endl;
		cout << "Ingresar Proveedor: ";
		getline(cin, elproveedor);
		//cin.ignore();

		//elproveedorConcatenado = "    " + elproveedor;

		cout << "Ingresar la Fecha (DIA / MES / ANIO): ";

		cout << "\nIngresar el Dia: ";
		getline(cin, day);
		//cin.ignore();

		cout << "Ingresar el Mes: ";
		getline(cin, month);
		//cin.ignore();

		cout << "Ingresar el Anio: ";
		getline(cin, year);
		//cin.ignore();

		cout << "Ingresar el Tipo de Documento: ";
		getline(cin, eltipoDocumentoxd);
		//cin.ignore();

		cout << "Ingresar Cantidad: ";
		cin >> cant;
		cin.ignore();

		cout << "Ingresar Precio: ";
		cin >> precio;
		cin.ignore();

		// CONCATENANDO LA FECHA
		fechaConcatenada = day + "/" + month + "/" + year;

		// AUMENTANDO EL PRECIO PARA TENER GANANCIA
		precioConGanancia = precio + (0.2 * precio);
		precioConGanancia = precioConGanancia + (0.18 * precioConGanancia);

		Producto producto;/*Crear el Objeto*/

		//Creando otro objeto
		KardexV2Vector kardexvectorv2INICIAL;//Instancia de la clase KardexV2Vector
		// GRABANDO CON EN ARCHIVO CON EL NOMBRE QUE SE DIGITO EL PRODUCTO
		kardexvectorv2INICIAL.V2cargarDatosDelArchivoAlVectorV2(nom);

		//Creando otro objeto
		//ProductoVector productoVectorCREADO;//Instancia de la clase ProductoVector
		//productoVectorCREADO.V2cargarDatosDelArchivoAlVectorV2(nom);

		// ======== KARDEX =========
		KardexV2 kardexV2Inicial;/*Crear el Objeto*/
		kardexV2Inicial.setCodigo(1); // siempre sera uno ya que estamos añadiendo un nuevo producto


		// ==== SET-ING  al vector Producto
		producto.setCodigo(code);
		producto.setNombre(nom);
		producto.setProveedor(elproveedor);
		producto.setCantidad(cant);
		producto.setPrecio(precioConGanancia);

		// ======== KARDEX =========
		// === SET-ING al vector KARDEX VERSION 2
		valorInventairoV2 = cant * precio;

		// == FECHA
		kardexV2Inicial.setFecha(fechaConcatenada);
		// == TIPO DE DOCUMENTO
		kardexV2Inicial.setTipoDocumento(eltipoDocumentoxd);
		// == TIPO DE OPERACION
		kardexV2Inicial.setTipoOperacion(eltipoOperacion);
		// == tipo de compra
		kardexV2Inicial.setTipoCompra(elproveedor);
		// == valor unitario
		kardexV2Inicial.setValorUnitario(precio);
		// == entrada
		kardexV2Inicial.setEntradaCant(cant);
		kardexV2Inicial.setEntradaValor(valorInventairoV2);
		// == salidas
		kardexV2Inicial.setSalidaCant(0);
		kardexV2Inicial.setSalidaValor(0);
		// == saldos
		kardexV2Inicial.setSaldoCant(cant);
		kardexV2Inicial.setSaldoValor(valorInventairoV2);
		// === precio
		kardexV2Inicial.setprecioProduct(precio);


		productoVector.add(producto);//Agregar el Objeto al vector dinamico

		productoVector.grabarEnArchivo(producto);

		kardexvectorv2INICIAL.add(kardexV2Inicial);//Agregar el Objeto al vector dinamico

		kardexvectorv2INICIAL.V2grabarEnArchivoV2(kardexV2Inicial, nom);


		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");
}
void 	eliminarProducto()
{
	int code;
	cout << "Ingresar el codigo a eliminar:";
	cin >> code;
	Producto objAEliminar = productoVector.buscarPorCodigo(code);
	if (objAEliminar.getNombre() != "Error")
	{
		productoVector.remove(objAEliminar);
		cout << "Registro Eliminado Satisfactoriamente";
		productoVector.grabarModificarELiminarArchivo();
	}
	else
	{
		cout << "No se encontro el registro!\n";
	}
}

void	modificarProducto()
{
	int cod;
	cout << "Ingresar el codigo a modificar:";
	cin >> cod;
	Producto objAModificar = productoVector.buscarPorCodigo(cod);

	cout << "Registro Encontrado\n";
	cout << "Codigo: " << objAModificar.getCodigo() << "\n";
	cout << "Nombre: " << objAModificar.getNombre() << "\n";
	cout << "Cantidad: " << objAModificar.getCantidad() << "\n";
	cout << "Precio: " << objAModificar.getPrecio() << "\n";
	cin.ignore();

	string nomModificado;
	int cantidadModificado;
	int precioModificado;

	cout << "Modificar campos\n";

	cout << "ESCRIBIR NOMBRE\n";
	getline(cin, nomModificado);

	cout << "ESCRIBIR CANTIDAD\n";
	cin >> cantidadModificado;

	cout << "ESCRIBIR PRECIO\n";
	cin >> precioModificado;

	// bool modificar(Producto obj, string NOMBRE, int CANTIDAD, int PRECIO);
	bool estado = productoVector.modificar(objAModificar, nomModificado, cantidadModificado, precioModificado);
	if (estado == true)
	{
		cout << "Registro Modificado Satisfactoriamente\n";
		//Grabar en archivo
		productoVector.grabarModificarELiminarArchivo();
	}
	else
	{
		cout << "No se Edito el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
	system("cls");
}

void	buscarProducto()
{
	int cod;
	cout << "Ingresar el codigo a buscar:";
	cin >> cod;
	Producto al = productoVector.buscarPorCodigo(cod);
	if (al.getNombre() != "Error")
	{
		cout << "Registro Encontrado\n";
		cout << "Codigo: " << al.getCodigo() << "\n";
		cout << "Nombre: " << al.getNombre() << "\n";
		cout << "Cantidad: " << al.getCantidad() << "\n";
		cout << "Precio del producto: " << al.getPrecio() << "\n";
	}
	else
	{
		cout << "No se encontro el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	system("pause");
}

void	buscarProductoParaKardexV2(int cod)
{
	Producto al = productoVector.buscarPorCodigo(cod);
	if (al.getNombre() != "Error")
	{
		cout << "Producto Encontrado !!\n";
		//cout << "Codigo: " << al.getCodigo() << "\n";
		cout << "Nombre: " << al.getNombre() << "\n";
		//cout << "Cantidad: " << al.getCantidad() << "\n";
		//cout << "Precio del producto: " << al.getPrecio() << "\n";
	}
	else
	{
		cout << "No se encontro el registro!\n";
		system("pause");
		menuDeOpciones();
	}
	//system("pause");
}

void	listarProducto()
{
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "  NOMBRE" << setw(15) << "  PROVEEDOR" << setw(15) << "CANTIDAD" << setw(10) << "PRECIO" << setw(7) << "||" << "\n";
	cout << "\t" << "++======================================================================++" << "\n";
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << productoVector.get(i).getCodigo() << setw(15) << productoVector.get(i).getNombre() << setw(15) << productoVector.get(i).getProveedor() << setw(15) << productoVector.get(i).getCantidad() << setw(10) << productoVector.get(i).getPrecio() << setw(7) << " ||" << "\n";
	}
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\n";
	system("pause");
	system("cls");
}

void	listarProductoParaKARDEXV2()
{
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "  NOMBRE" << setw(15) << "  PROVEEDOR" << setw(15) << "CANTIDAD" << setw(10) << "PRECIO" << setw(7) << "||" << "\n";
	cout << "\t" << "++======================================================================++" << "\n";
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << productoVector.get(i).getCodigo() << setw(15) << productoVector.get(i).getNombre() << setw(15) << productoVector.get(i).getProveedor() << setw(15) << productoVector.get(i).getCantidad() << setw(10) << productoVector.get(i).getPrecio() << setw(7) << " ||" << "\n";
	}
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\n";
}

void	V2entradaKardexV2()
{
	//Crear Variables
	int 	  cod;
	string	fechaConcatenada;
	string	day;
	string	month;
	string	year;
	string	eltipoDocumentoo;
	string	eltipoOperacionn = "02";
	string	elproveedor;
	string	elproveedorConcatenado;
	// variables de precio y valor
	int		elprecioProducto;
	int		elvalorUnitario;
	// variables de entrada
	int 	elentradaCant;
	int 	elentradaValor;
	// variables de salvo
	int		elsaldoCant;
	int		elsaldoValor;
	// variables extra
	//cantidadModificado, precioModificado
	int		cantidadModificado;
	int		precioModificado;
	int		valorInventairo;
	int		valorEntradaCompra;
	// ==== STRINGS
	string	rpta;
	string	ArchivoBuscarNombre;
	string	CeEseVstring = ".csv";
	string	concetenadoArchivosBuscar;
	// === opcion codigo
	int		codigoSeleccionado;

	// === MOSTRANDO LA TABLA DE LISTA DE PRODUCTOS PARA ELEGIR
	listarProductoParaKARDEXV2();

	// === PIDIENDO QUE DIGITE EL CODIGO DE UN PRODUCTO 
	cout << "\t" << " == DIGITE UN CODIGO DEL PRODUCTO ( 1 | 2 | 3 ...) == > ";
	cin >> codigoSeleccionado;

	// === BUSCANDO EL CODIGO DEL PRODUCTO Y MOSTRANDOLO
	//buscarProductoParaKardexV2(codigoSeleccionado);

	Producto al = productoVector.buscarPorCodigo(codigoSeleccionado);
	// CREANDO UN OBJETO PARA MODIFICAR LA CANTIDAD DEL PRODUCTO Y EL VALOR DE VENTA
	Producto objAModificar = productoVector.buscarPorCodigo(codigoSeleccionado);

	ArchivoBuscarNombre = al.getNombre();
	cout << "\t" << " == SE ENCONTRO EL NOMBRE !! == > " << ArchivoBuscarNombre << "\n";

	//Creando otro objeto KARDEX MEJORADO
	KardexV2Vector kardexVectorV2ENTRADA;//Instancia de la clase KardexVector V2
	// CARGANDO DATOS DEL ARCHIVO BUSCADO 
	kardexVectorV2ENTRADA.V2cargarDatosDelArchivoAlVectorV2(ArchivoBuscarNombre);
	//concetenadoArchivosBuscar = ArchivoBuscarNombre + CeEseVstring;



	//Crear el Objeto de la clase KARDEX VERSION 2
	do
	{
		//Entrada de datos
		cod = kardexVectorV2ENTRADA.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Llenar con 7 carac: ABCDEFG" << endl;
		cout << "Ingresar Proveedor: ";
		getline(cin, elproveedor);
		//cin.ignore();

		elproveedorConcatenado = "    " + elproveedor;

		cout << "Ingresar la Fecha (DIA / MES / ANIO): ";

		cout << "\nIngresar el Dia: ";
		getline(cin, day);
		//cin.ignore();

		cout << "Ingresar el Mes: ";
		getline(cin, month);
		//cin.ignore();

		cout << "Ingresar el Anio: ";
		getline(cin, year);
		//cin.ignore();

		fechaConcatenada = day + "/" + month + "/" + year;

		cout << "Ingresar el Tipo de Documento: ";
		getline(cin, eltipoDocumentoo);
		//cin.ignore();

		// EN CASO DE QUE ES ENTRADA
		cout << "Ingresar la cantidad de productos a entrar: ";
		cin >> elentradaCant;
		cin.ignore();

		cout << "Ingresar el precio del producto de entrada: ";
		cin >> elprecioProducto;
		cin.ignore();

		// ==============
		KardexV2 kardexV2ENTRADA;/*Crear el Objeto*/
		kardexV2ENTRADA.setCodigo(cod);

		//Cardex cardexRef = cardexVector.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		KardexV2 kardexV2EntRefe = kardexVectorV2ENTRADA.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		valorEntradaCompra = elentradaCant * elprecioProducto;

		// == fecha
		kardexV2ENTRADA.setFecha(fechaConcatenada);
		// == tipo de documento
		kardexV2ENTRADA.setTipoDocumento(eltipoDocumentoo);
		// == tipo de documento
		kardexV2ENTRADA.setTipoOperacion(eltipoOperacionn);
		// == tipo de compra
		kardexV2ENTRADA.setTipoCompra(elproveedor);
		// == entrada
		kardexV2ENTRADA.setEntradaCant(elentradaCant);
		kardexV2ENTRADA.setEntradaValor(valorEntradaCompra);
		// == salidas
		kardexV2ENTRADA.setSalidaCant(0);
		kardexV2ENTRADA.setSalidaValor(0);
		// == saldos
		kardexV2ENTRADA.setSaldoCant((kardexV2EntRefe.getSaldoCant() + elentradaCant));
		kardexV2ENTRADA.setSaldoValor((kardexV2EntRefe.getSaldoValor() + valorEntradaCompra));
		// === precio
		kardexV2ENTRADA.setprecioProduct(elprecioProducto);
		// == valor unitario
		kardexV2ENTRADA.setValorUnitario((kardexV2ENTRADA.getSaldoValor()) / kardexV2ENTRADA.getSaldoCant());

		kardexVectorV2ENTRADA.add(kardexV2ENTRADA);//Agregar el Objeto al vector dinamico

		kardexVectorV2ENTRADA.V2grabarEnArchivoV2(kardexV2ENTRADA, ArchivoBuscarNombre);

		// CAMBIANDO LOS VALORES DEL PRODUCTO
		cantidadModificado = kardexV2ENTRADA.getSaldoCant();
		precioModificado = kardexV2ENTRADA.getValorUnitario();
		precioModificado = precioModificado + 0.2 * (precioModificado);
		precioModificado = precioModificado + 0.18 * (precioModificado);

		// bool modificar(Producto obj, string NOMBRE, int CANTIDAD, int PRECIO);
		bool estado = productoVector.modificarCantidadStockYPRECIO(objAModificar, cantidadModificado, precioModificado);
		if (estado == true)
		{
			//cout << "Registro Modificado Satisfactoriamente\n";
			//Grabar en archivo
			productoVector.grabarModificarELiminarArchivo();
		}
		else
		{
			cout << "No se Edito el registro!\n";
			system("pause");
			menuDeOpciones();
		}
		//system("pause");
		//system("cls");

		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar

	} while (rpta == "SI" || rpta == "si");

}

void	V2salidaKardexV2()
{
	//Crear Variables
	int 	cod;
	string	fechaConcatenada;
	string	day;
	string	month;
	string	year;
	string	eltipoDocumentoo;
	string	eltipoOperacionn = "01";
	string	elcliente;
	string	elclienteConcatenado;
	string	eltipocompra;
	// variables de precio y valor
	int		elprecioProducto;
	int		elvalorUnitario;
	// variables de Venta
	int 	lasalidaCant;
	int 	lasalidaValor;
	// variables de salvo
	int		elsaldoCant;
	int		elsaldoValor;
	// variables extra
	//cantidadModificado, precioModificado
	int		cantidadModificado;
	int		precioModificado;
	int		valorInventairo;
	int		valorEntradaCompra;
	// ==== STRINGS
	string	rpta;
	string	ArchivoBuscarNombre;
	string	CeEseVstring = ".csv";
	string	concetenadoArchivosBuscar;
	// === opcion codigo
	int		codigoSeleccionado;

	// === MOSTRANDO LA TABLA DE LISTA DE PRODUCTOS PARA ELEGIR
	listarProductoParaKARDEXV2();

	// === PIDIENDO QUE DIGITE EL CODIGO DE UN PRODUCTO 
	cout << "\t" << " == DIGITE UN CODIGO DEL PRODUCTO ( 1 | 2 | 3 ...) == > ";
	cin >> codigoSeleccionado;

	// === BUSCANDO EL CODIGO DEL PRODUCTO Y MOSTRANDOLO
	//buscarProductoParaKardexV2(codigoSeleccionado);

	Producto al = productoVector.buscarPorCodigo(codigoSeleccionado);
	// CREANDO UN OBJETO PARA MODIFICAR LA CANTIDAD DEL PRODUCTO Y EL VALOR DE VENTA
	Producto objAModificar = productoVector.buscarPorCodigo(codigoSeleccionado);

	ArchivoBuscarNombre = al.getNombre();
	cout << "\t" << " == SE ENCONTRO EL NOMBRE !! == > " << ArchivoBuscarNombre << "\n";

	//Creando otro objeto KARDEX MEJORADO
	KardexV2Vector kardexVectorV2SALIDA;//Instancia de la clase KardexVector V2
	// CARGANDO DATOS DEL ARCHIVO BUSCADO 
	kardexVectorV2SALIDA.V2cargarDatosDelArchivoAlVectorV2(ArchivoBuscarNombre);
	//concetenadoArchivosBuscar = ArchivoBuscarNombre + CeEseVstring;



	//Crear el Objeto de la clase KARDEX VERSION 2
	do
	{
		//Entrada de datos
		cod = kardexVectorV2SALIDA.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Llenar con 7 caracteres      : ABCDEFG" << endl;
		cout << "Ingresar el nombre de cliente: ";
		getline(cin, elcliente);
		//cin.ignore();

		elclienteConcatenado = "    " + elcliente;

		cout << "Ingresar la Fecha (DIA / MES / ANIO): ";

		cout << "\nIngresar el Dia: ";
		getline(cin, day);
		//cin.ignore();

		cout << "Ingresar el Mes: ";
		getline(cin, month);
		//cin.ignore();

		cout << "Ingresar el Anio: ";
		getline(cin, year);
		//cin.ignore();

		fechaConcatenada = day + "/" + month + "/" + year;

		cout << "Ingresar el Tipo de Documento: ";
		getline(cin, eltipoDocumentoo);
		//cin.ignore();

		// EN CASO DE QUE ES ENTRADA
		cout << "Ingresar la cantidad de productos a VENDER:";
		cin >> lasalidaCant;
		cin.ignore();

		// ==============
		KardexV2 kardexV2SALIDA;/*Crear el Objeto*/
		kardexV2SALIDA.setCodigo(cod);

		//Cardex cardexRef = cardexVector.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		KardexV2 kardexV2SALRefe = kardexVectorV2SALIDA.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		//valorEntradaCompra = elentradaCant * elprecioProducto;

		// == FECHA
		kardexV2SALIDA.setFecha(fechaConcatenada);
		// == TIPO DE DOCUMENTO
		kardexV2SALIDA.setTipoDocumento(eltipoDocumentoo);
		// == TIPO DE DOCUMENTO
		kardexV2SALIDA.setTipoOperacion(eltipoOperacionn);
		// == tipo de compra
		kardexV2SALIDA.setTipoCompra(elcliente);
		// == valor unitario
		kardexV2SALIDA.setValorUnitario(kardexV2SALRefe.getValorUnitario());
		// == entrada
		kardexV2SALIDA.setEntradaCant(0);
		kardexV2SALIDA.setEntradaValor(0);
		// == salidas
		kardexV2SALIDA.setSalidaCant(lasalidaCant);
		kardexV2SALIDA.setSalidaValor((kardexV2SALRefe.getValorUnitario()) * lasalidaCant);
		// == saldos
		kardexV2SALIDA.setSaldoCant(kardexV2SALRefe.getSaldoCant() - lasalidaCant);
		kardexV2SALIDA.setSaldoValor(kardexV2SALRefe.getSaldoValor() - kardexV2SALIDA.getSalidaValor());
		// === precio
		kardexV2SALIDA.setprecioProduct(objAModificar.getPrecio());

		kardexVectorV2SALIDA.add(kardexV2SALIDA);//Agregar el Objeto al vector dinamico

		kardexVectorV2SALIDA.V2grabarEnArchivoV2(kardexV2SALIDA, ArchivoBuscarNombre);

		// CAMBIANDO LOS VALORES DEL PRODUCTO
		cantidadModificado = kardexV2SALIDA.getSaldoCant();
		//precioModificado = kardexV2SALIDA.getValorUnitario();
		//precioModificado = precioModificado + 0.2 * (precioModificado);
		//precioModificado = precioModificado + 0.18 * (precioModificado);

		// bool modificar(Producto obj, string NOMBRE, int CANTIDAD, int PRECIO);
		bool estado = productoVector.modificarCantidadStock(objAModificar, cantidadModificado);
		if (estado == true)
		{
			//cout << "Registro Modificado Satisfactoriamente\n";
			//Grabar en archivo
			productoVector.grabarModificarELiminarArchivo();
		}
		else
		{
			cout << "No se Edito el registro!\n";
			system("pause");
			menuDeOpciones();
		}
		//system("pause");
		//system("cls");

		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");

}

void	V2listarKardexV2()
{
	string	ArchivoBuscarNombre;
	int		codigoSeleccionado;
	// llamando funcion para mostrar los productos
	listarProductoParaKARDEXV2();
	// === PIDIENDO QUE DIGITE EL CODIGO DE UN PRODUCTO 
	cout << "\t" << " == DIGITE UN CODIGO DEL PRODUCTO ( 1 | 2 | 3 ...) == > ";
	cin >> codigoSeleccionado;

	Producto productoListar = productoVector.buscarPorCodigo(codigoSeleccionado);
	// CREANDO UN OBJETO PARA MODIFICAR LA CANTIDAD DEL PRODUCTO Y EL VALOR DE VENTA
	Producto objAModificar = productoVector.buscarPorCodigo(codigoSeleccionado);

	ArchivoBuscarNombre = productoListar.getNombre();
	cout << "\n" << "\t" << " == SE ENCONTRO EL NOMBRE !! == > " << ArchivoBuscarNombre << "\n";
	cout << "\n";
	cout << "\t" << "++============== LEYENDA =============++" << "\n";
	cout << "\t" << "||                                    ||" << "\n";
	cout << "\t" << "||    01 -- > VENTA  DE PRODUCTO      ||" << "\n";
	cout << "\t" << "||    02 -- > COMPRA DE PRODUCTO      ||" << "\n";
	cout << "\t" << "||                                    ||" << "\n";
	cout << "\t" << "++====================================++" << "\n";
	cout << "\n";

	//Creando otro objeto KARDEX MEJORADO
	KardexV2Vector kardexVectorV2Listar;//Instancia de la clase KardexVector V2
	// CARGANDO DATOS DEL ARCHIVO BUSCADO 
	kardexVectorV2Listar.V2cargarDatosDelArchivoAlVectorV2(ArchivoBuscarNombre);
	//concetenadoArchivosBuscar = ArchivoBuscarNombre + CeEseVstring;

	cout << "\t" << "++================================================================================================================================++" << "\n";
	cout << "\t" << "||" << setw(5) << "FECHA" << setw(15) << "TIPO DE " << setw(10) << "TIPO DE" << setw(10) << "CODIGO" << setw(15) << "DETALLE" << setw(10) << "VALOR" << setw(18) << "ENTRADAS" << setw(20) << "SALIDAS" << setw(18) << "SALDOS" << setw(9) << "||" << "\n";
	cout << "\t" << "||" << setw(20) << " DOC. " << setw(10) << " OP. " << setw(46) << " CANT " << setw(10) << " VALOR " << setw(10) << " CANT " << setw(10) << " VALOR " << setw(10) << " CANT " << setw(10) << " VALOR " << setw(4) << "||" << "\n";
	cout << "\t" << "++================================================================================================================================++" << "\n";
	for (int i = 0; i < kardexVectorV2Listar.rows(); i++)
	{
		//cout << "\t" << "||  " << kardexVector.get(i).getCodigo() << "\t   " << kardexVector.get(i).getTipoCompra() << "\t   " << kardexVector.get(i).getValorUnitario() << "\t    " << kardexVector.get(i).getEntradaCant() << "\t   " << kardexVector.get(i).getEntradaValor() << "\t   " << kardexVector.get(i).getSalidaCant() << "\t   " << kardexVector.get(i).getSalidaValor() << "\t   " << kardexVector.get(i).getSaldoCant() << "\t    " << kardexVector.get(i).getSaldoValor() << "   " << " ||" << "\n";
		// 

		//cout << "\t" << "||" << setw(10) << productoVector.get(i).getCodigo() << setw(15) << productoVector.get(i).getNombre() << setw(15) << productoVector.get(i).getProveedor() << setw(15) << productoVector.get(i).getCantidad() << setw(10) << productoVector.get(i).getPrecio() << setw(7) << " ||" << "\n";

		cout << "\t" << "||" << setw(5) << kardexVectorV2Listar.get(i).getFecha() << setw(10) << kardexVectorV2Listar.get(i).getTipoDocumento() << setw(10) << kardexVectorV2Listar.get(i).getTipoOperacion() << setw(10) << kardexVectorV2Listar.get(i).getCodigo() << setw(15) << kardexVectorV2Listar.get(i).getTipoCompra() << setw(10) << kardexVectorV2Listar.get(i).getValorUnitario() << setw(10) << kardexVectorV2Listar.get(i).getEntradaCant() << setw(10) << kardexVectorV2Listar.get(i).getEntradaValor() << setw(10) << kardexVectorV2Listar.get(i).getSalidaCant() << setw(10) << kardexVectorV2Listar.get(i).getSalidaValor() << setw(10) << kardexVectorV2Listar.get(i).getSaldoCant() << setw(10) << kardexVectorV2Listar.get(i).getSaldoValor() << setw(5) << "||" << "\n";

		//suma = suma + (cardexVector.get(i).getEntrada() * cardexVector.get(i).getprecioProduct());
		//sumaCantidades = sumaCantidades + cardexVector.get(i).getEntrada();
	}
	cout << "\t" << "++================================================================================================================================++" << "\n";
	cout << "\n";

	//promedio = (suma / sumaCantidades);

	//cout << "\t" << "++=============>>>> El promedio de precios es: " << promedio;
	//cout << "\n";

	system("pause");
	system("cls");
}

void	mostrarFuncionesKARDEX()
{
	int opcionselecionarKardex;
	cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
	cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
	cout << "\t" << "||" << " == 1. Ejectuar el KARDEX (ENTRADA) == > " << "          " << "||" << "\n";
	cout << "\t" << "||" << " == 2. Ejectuar el KARDEX (SALIDA) == > " << "           " << "||" << "\n";
	cout << "\t" << "||" << " == 3. Listar KARDEX == > " << "                         " << "||" << "\n";
	cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
	cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
	cout << "\t" << "== DIGITE UNA OPCION ( 1 | 2 | 3 ) == > ";
	cin >> opcionselecionarKardex;
	switch (opcionselecionarKardex)
	{
	case 1:
		system("cls");
		V2entradaKardexV2();
		break;
	case 2:
		system("cls");
		V2salidaKardexV2();
		break;
	case 3:
		system("cls");
		V2listarKardexV2();
		break;
	default:
		cout << "Ingrese una opcion correcta [1-3] !! " << endl;
	}
}

void	mostrarFuncionesVENDEDOR()
{
	int opcionVendedor;
	cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
	cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
	cout << "\t" << "||" << " == 1. Ingresar Nuevos Vendedor == > " << "              " << "||" << "\n";
	cout << "\t" << "||" << " == 2. Eliminar Nuevos Vendedor == > " << "              " << "||" << "\n";
	cout << "\t" << "||" << " == 3. Modificar Nuevos Vendedor == > " << "             " << "||" << "\n";
	cout << "\t" << "||" << " == 4. Buscar Nuevos Vendedores == > " << "              " << "||" << "\n";
	cout << "\t" << "||" << " == 5. Listar Vendedores == > " << "                     " << "||" << "\n";
	cout << "\t" << "||" << "                                                   " << "||" << "\t" << "\n";
	cout << "\t" << "++" << " ================================================= " << "++" << "\t" << endl;
	cout << "\t" << "== DIGITE UNA OPCION ( 1 | 2 | 3 | 4 | 5) == > ";
	cin >> opcionVendedor;
	switch (opcionVendedor)
	{
	case 1:
		system("cls");
		adicionarVendedor();
		break;
	case 2:
		system("cls");
		eliminarVendedor();
		break;
	case 3:
		system("cls");
		modificarVendedor();
		break;
	case 4:
		system("cls");
		buscarVendedor();
		break;
	case 5:
		system("cls");
		listarVendedor();
		break;
	default:
		cout << "Ingrese una opcion correcta [1-5] !! " << endl;
	}
}

void	mostrarFuncionesPRODUCTO()
{
	int opcionProducto;
	cout << "\t" << "++" << " ======================================================= " << "++" << "\t" << endl;
	cout << "\t" << "||" << "                                                         " << "||" << "\t" << "\n";
	cout << "\t" << "||" << " == 1. Ingresar Nuevos Productos == > " << "                   " << "||" << "\n";
	cout << "\t" << "||" << " == 2. Eliminar Nuevos Productos == > " << "                   " << "||" << "\n";
	cout << "\t" << "||" << " == 3. Modificar Nuevos Productos == > " << "                  " << "||" << "\n";
	cout << "\t" << "||" << " == 4. Buscar Nuevos Productos == > " << "                     " << "||" << "\n";
	cout << "\t" << "||" << " == 5. Listar Productos == > " << "                            " << "||" << "\n";
	cout << "\t" << "||" << "                                                         " << "||" << "\t" << "\n";
	cout << "\t" << "++" << " ======================================================= " << "++" << "\t" << endl;
	cout << "\t" << "== DIGITE UNA OPCION ( 1 | 2 | 3 | 4 | 5 ) == > ";
	cin >> opcionProducto;
	switch (opcionProducto)
	{
	case 1:
		system("cls");
		adicionarProducto();
		break;
	case 2:
		system("cls");
		eliminarProducto();
		break;
	case 3:
		system("cls");
		modificarProducto();
		break;
	case 4:
		system("cls");
		buscarProducto();
		break;
	case 5:
		system("cls");
		listarProducto();
		break;
	default:
		cout << "Ingrese una opcion correcta [1-5] !! " << endl;
	}
}

void	mostrarFuncionesCLIENTE()
{
	int opcionProducto;
	cout << "\t" << "++" << " ======================================================= " << "++" << "\t" << endl;
	cout << "\t" << "||" << "                                                         " << "||" << "\t" << "\n";
	cout << "\t" << "||" << " == 1. Ingresar Nuevos Clientes (PERSONAS) == > " << "         " << "||" << "\n";
	cout << "\t" << "||" << " == 2. Ingresar Nuevos Clientes (ENTIDADES) == > " << "        " << "||" << "\n";
	cout << "\t" << "||" << " == 3. Eliminar Nuevos Clientes == > " << "                    " << "||" << "\n";
	cout << "\t" << "||" << " == 4. Modificar Nuevos Clientes == > " << "                   " << "||" << "\n";
	cout << "\t" << "||" << " == 5. Buscar Nuevos Clientes == > " << "                      " << "||" << "\n";
	cout << "\t" << "||" << " == 6. Listar Clientes == > " << "                             " << "||" << "\n";
	cout << "\t" << "||" << "                                                         " << "||" << "\t" << "\n";
	cout << "\t" << "++" << " ======================================================= " << "++" << "\t" << endl;
	cout << "\t" << "== DIGITE UNA OPCION ( 1 | 2 | 3 | 4 | 5 | 6) == > ";
	cin >> opcionProducto;
	switch (opcionProducto)
	{
	case 1:
		//void 	adicionarClientePersona();
		//void 	adicionarClienteEntidad();
		system("cls");
		adicionarClientePersona();
		break;
	case 2:
		system("cls");
		adicionarClienteEntidad();
		break;
	case 3:
		system("cls");
		eliminarCliente();
		break;
	case 4:
		system("cls");
		modificarCliente();
		break;
	case 5:
		system("cls");
		buscarCliente();
		break;
	case 6:
		system("cls");
		listarCliente();
		break;
	default:
		cout << "Ingrese una opcion correcta [1-5] !! " << endl;
	}
}

void	realizarVenta()
{
	//Crear Variables
	int 	cod;
	string	fechaConcatenada;
	string	day;
	string	month;
	string	year;
	string	eltipoDocumentoo;
	string	eltipoOperacionn;
	string	elcliente;
	string	elclienteConcatenado;
	string	eltipocompra;
	// variables de precio y valor
	int		elprecioProducto;
	int		elvalorUnitario;
	// variables de Venta
	int 	lasalidaCant;
	int 	lasalidaValor;
	// variables de salvo
	int		elsaldoCant;
	int		elsaldoValor;
	// variables extra
	int		precioMostrarValorUnitario;
	int		numeroapasarLetra;
	//cantidadModificado, precioModificado
	int		cantidadModificado;
	int		precioModificado;
	int		valorInventairo;
	int		valorEntradaCompra;
	// ==== STRINGS
	string	rpta;
	string	ArchivoBuscarNombre;
	string	CeEseVstring = ".csv";
	string	concetenadoArchivosBuscar;
	// === opcion codigo
	int		codigoSeleccionado;

	// === MOSTRANDO LA TABLA DE LISTA DE PRODUCTOS PARA ELEGIR
	listarProductoParaKARDEXV2(); /***/

	// === PIDIENDO QUE DIGITE EL CODIGO DE UN PRODUCTO 
	cout << "\t" << " == DIGITE UN CODIGO DEL PRODUCTO ( 1 | 2 | 3 ...) == > ";
	cin >> codigoSeleccionado;

	// === BUSCANDO EL CODIGO DEL PRODUCTO Y MOSTRANDOLO
	//buscarProductoParaKardexV2(codigoSeleccionado);

	Producto al = productoVector.buscarPorCodigo(codigoSeleccionado);
	// CREANDO UN OBJETO PARA MODIFICAR LA CANTIDAD DEL PRODUCTO Y EL VALOR DE VENTA
	Producto objAModificar = productoVector.buscarPorCodigo(codigoSeleccionado);
	Producto productoListar = productoVector.buscarPorCodigo(codigoSeleccionado);

	ArchivoBuscarNombre = al.getNombre();
	cout << "\t" << " == SE ENCONTRO EL NOMBRE !! == > " << ArchivoBuscarNombre << "\n";

	//Creando otro objeto KARDEX MEJORADO
	KardexV2Vector kardexVectorV2SALIDA;//Instancia de la clase KardexVector V2
	// CARGANDO DATOS DEL ARCHIVO BUSCADO 
	kardexVectorV2SALIDA.V2cargarDatosDelArchivoAlVectorV2(ArchivoBuscarNombre);
	//concetenadoArchivosBuscar = ArchivoBuscarNombre + CeEseVstring;



	//Crear el Objeto de la clase KARDEX VERSION 2
	do
	{
		//Entrada de datos
		cod = kardexVectorV2SALIDA.getCorrelativo();

		cout << "Codigo(" << cod << ")" << endl;
		cin.ignore();

		cout << "Llenar con 7 caracteres      : ABCDEFG" << endl;
		cout << "Ingresar el nombre de cliente: ";
		getline(cin, elcliente);
		//cin.ignore();

		elclienteConcatenado = "    " + elcliente;

		cout << "Ingresar la Fecha (DIA / MES / ANIO): ";

		cout << "\nIngresar el Dia: ";
		getline(cin, day);
		//cin.ignore();

		cout << "Ingresar el Mes: ";
		getline(cin, month);
		//cin.ignore();

		cout << "Ingresar el Anio: ";
		getline(cin, year);
		//cin.ignore();

		fechaConcatenada = day + "/" + month + "/" + year;

		cout << "Ingresar el Tipo de Documento: ";
		getline(cin, eltipoDocumentoo);
		//cin.ignore();

		if (eltipoDocumentoo[0] == 'F')
		{
			eltipoOperacionn = "01";
		}
		else if (eltipoDocumentoo[0] == 'B')
		{
			eltipoOperacionn = "02";
		}

		cout << "Ingresar la cantidad de productos a VENDER:";
		cin >> lasalidaCant;
		cin.ignore();

		// ==============
		KardexV2 kardexV2SALIDA;/*Crear el Objeto*/
		kardexV2SALIDA.setCodigo(cod);

		//Cardex cardexRef = cardexVector.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		KardexV2 kardexV2SALRefe = kardexVectorV2SALIDA.buscarPorCodigo((cod - 1));/*Crear el Objeto para ubicar al stock anterior*/

		//valorEntradaCompra = elentradaCant * elprecioProducto;

		// == FECHA
		kardexV2SALIDA.setFecha(fechaConcatenada);
		// == TIPO DE DOCUMENTO
		kardexV2SALIDA.setTipoDocumento(eltipoDocumentoo);
		// == TIPO DE DOCUMENTO
		kardexV2SALIDA.setTipoOperacion(eltipoOperacionn);
		// == tipo de compra
		kardexV2SALIDA.setTipoCompra(elcliente);
		// == valor unitario
		kardexV2SALIDA.setValorUnitario(kardexV2SALRefe.getValorUnitario());
		// == entrada
		kardexV2SALIDA.setEntradaCant(0);
		kardexV2SALIDA.setEntradaValor(0);
		// == salidas
		kardexV2SALIDA.setSalidaCant(lasalidaCant);
		kardexV2SALIDA.setSalidaValor((kardexV2SALRefe.getValorUnitario()) * lasalidaCant);
		// == saldos
		kardexV2SALIDA.setSaldoCant(kardexV2SALRefe.getSaldoCant() - lasalidaCant);
		kardexV2SALIDA.setSaldoValor(kardexV2SALRefe.getSaldoValor() - kardexV2SALIDA.getSalidaValor());
		// === precio
		kardexV2SALIDA.setprecioProduct(objAModificar.getPrecio());

		kardexVectorV2SALIDA.add(kardexV2SALIDA);//Agregar el Objeto al vector dinamico

		kardexVectorV2SALIDA.V2grabarEnArchivoV2(kardexV2SALIDA, ArchivoBuscarNombre);

		// CAMBIANDO LOS VALORES DEL PRODUCTO
		cantidadModificado = kardexV2SALIDA.getSaldoCant();
		//precioModificado = kardexV2SALIDA.getValorUnitario();
		//precioModificado = precioModificado + 0.2 * (precioModificado);
		//precioModificado = precioModificado + 0.18 * (precioModificado);

		// bool modificar(Producto obj, string NOMBRE, int CANTIDAD, int PRECIO);
		bool estado = productoVector.modificarCantidadStock(objAModificar, cantidadModificado);
		if (estado == true)
		{
			//cout << "Registro Modificado Satisfactoriamente\n";
			//Grabar en archivo
			productoVector.grabarModificarELiminarArchivo();
		}
		else
		{
			cout << "No se Edito el registro!\n";
			system("pause");
			menuDeOpciones();
		}

		cout << "\n";
		cout << "\t" << "++============== LEYENDA =============++" << "\n";
		cout << "\t" << "||                                    ||" << "\n";
		cout << "\t" << "||          01 -- > FACTURA           ||" << "\n";
		cout << "\t" << "||          02 -- > BOLETA            ||" << "\n";
		cout << "\t" << "||                                    ||" << "\n";
		cout << "\t" << "++====================================++" << "\n";
		cout << "\n";
		cout << "\t" << " ==>> TIPO DE OPERACION: " << kardexV2SALIDA.getTipoOperacion() << "\n";
		cout << "\t" << " ==>> CODIGO DE FACTURA: " << kardexV2SALIDA.getTipoDocumento() << "\n";
		cout << "\t" << " ==>> CLIENTE          : " << kardexV2SALIDA.getTipoCompra() << "\n";
		cout << "\n";
		cout << "\t" << "++================================================++" << "\n";
		cout << "\t" << "||                DETALLE DE VENTA                ||" << "\n";
		/*
		* // AUMENTANDO EL PRECIO PARA TENER GANANCIA
		precioConGanancia = precio + (0.2 * precio);
		precioConGanancia = precioConGanancia + (0.18 * precioConGanancia);
		*/

		// primero, se asigna el valor del precio a la variable "precioMostrarValorUnitario"
		precioMostrarValorUnitario = productoListar.getPrecio();
		// segundo, se divide entro 1.2 para sacarle la ganancia del 20%
		precioMostrarValorUnitario = precioMostrarValorUnitario / 1.2;
		// tercero se dividi entre 1.8 para sacarle el IGV pero tomando como referencia que ya saco la gancia del 20%
		precioMostrarValorUnitario = precioMostrarValorUnitario / 1.8;

		cout << "\t" << "++================================================++" << "\n";
		cout << "\t" << "||" << setw(10) << "CANTIDAD" << setw(10) << "  NOMBRE" << setw(15) << "V. UNIT" << setw(10) << "V. VENTA" << setw(5) << "||" << "\n";
		cout << "\t" << "++================================================++" << "\n";
		cout << "\t" << "||" << setw(10) << lasalidaCant << setw(10) << productoListar.getNombre() << setw(10) << precioMostrarValorUnitario << setw(10) << productoListar.getPrecio() << setw(10) << "||" << "\n";
		cout << "\t" << "++================================================++" << "\n";
		cout << "\t" << setw(44) << "IC:            ---->" << lasalidaCant * productoListar.getPrecio() << "\n";
		cout << "\t" << setw(44) << "18%            ---->" << (lasalidaCant * 0.18 * productoListar.getPrecio()) << "\n";
		numeroapasarLetra = lasalidaCant * 1.18 * productoListar.getPrecio();
		cout << "\t" << setw(44) << "TOTAL A APAGAR ---->" << lasalidaCant * 1.18 * productoListar.getPrecio() << "\n";
		cout << "\n";
		cout << "\t" << "SON: " << convertirNumeroALetra(numeroapasarLetra) << " SOLES";
		cout << "\n";


		cout << "\n" << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls");//Limpiar
	} while (rpta == "SI" || rpta == "si");

}

void	mostrarVentas()
{
	cout << "\n";
	cout << "\t" << "++============== LEYENDA =============++" << "\n";
	cout << "\t" << "||                                    ||" << "\n";
	cout << "\t" << "||          01 -- > FACTURA           ||" << "\n";
	cout << "\t" << "||          02 -- > BOLETA            ||" << "\n";
	cout << "\t" << "||                                    ||" << "\n";
	cout << "\t" << "++====================================++" << "\n";
	cout << "\n";
	cout << "\t" << " ==>> CODIGO DE FACTURA: " << "\n";
	cout << "\t" << " ==>> CLIENTE          : " << "\n";
	cout << "\t" << "                         DETALLE DE VENTA " << "\n";
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\t" << "||" << setw(10) << "CODIGO" << setw(15) << "  NOMBRE" << setw(15) << "  PROVEEDOR" << setw(15) << "CANTIDAD" << setw(10) << "PRECIO" << setw(7) << "||" << "\n";
	cout << "\t" << "++======================================================================++" << "\n";
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << "\t" << "||" << setw(10) << productoVector.get(i).getCodigo() << setw(15) << productoVector.get(i).getNombre() << setw(15) << productoVector.get(i).getProveedor() << setw(15) << productoVector.get(i).getCantidad() << setw(10) << productoVector.get(i).getPrecio() << setw(7) << " ||" << "\n";
	}
	cout << "\t" << "++======================================================================++" << "\n";
	cout << "\n";
}

string	NumeroALetra(int n, string s)
{
	// n is 1- or 2-digit number
	string str = "";
	// if n is more than 19, divide it
	if (n > 19)
		str += ten[n / 10] + one[n % 10];
	else
		str += one[n];

	// if n is non-zero
	if (n)
		str += s;

	return str;
}

// Function to print a given number in words
string convertirNumeroALetra(int n)
{
	// stores word representation of given number n
	string out;

	// handles digits at ten millions and hundred
	// millions places (if any)
	out += NumeroALetra((n / 10000000), "DIEZ MILLONES ");

	// handles digits at hundred thousands and one
	// millions places (if any)
	out += NumeroALetra(((n / 100000) % 100), "CIEN MIL ");

	// handles digits at thousands and tens thousands
	// places (if any)
	out += NumeroALetra(((n / 1000) % 100), "MIL ");

	// handles digit at hundreds places (if any)
	out += NumeroALetra(((n / 100) % 10), "CIEN ");

	if (n > 100 && n % 100)
		out += "Y ";

	// handles digits at ones and tens places (if any)
	out += NumeroALetra((n % 100), "");

	//Handling the n=0 case
	if (out == "")
		out = "CERO";

	return out;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
