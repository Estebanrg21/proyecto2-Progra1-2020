#ifndef CLIENTES_H
#define CLIENTES_H
#include<iostream>
#include "Cliente.h"
#include "ListaEnlazada.hpp"
#include "json.hpp"
#include <fstream>
#include <iomanip>
#include <typeinfo> 
using namespace std;
using json = nlohmann::json;

class Clientes{
public:
	Clientes();
	~Clientes();
	static int instancias;
	int mynum;
	bool eliminarCliente(int ced);
	Lista<Cliente>listarClientes();
	Lista<Cliente> listarClientesActivos();
	Lista<Cliente> listarClientesSusp();
	bool ingresarCliente(Cliente& cl);
	string actualizarCliente(int ced,string field, string val);
	
};
#endif



