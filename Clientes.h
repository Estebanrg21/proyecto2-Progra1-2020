#ifndef CLIENTES_H
#define CLIENTES_H
#include<iostream>
#include "Cliente.h"
using namespace std;
class Clientes{
public:
	Clientes();
	~Clientes();
	Cliente* crearCliente();
	Cliente* actualizarCliente();
	bool eliminarCliente(int ced);
	Cliente** listarClientes();
	Cliente** listarClientesActivos();
	Cliente** listarClientesSusp();
	string ingresarCliente(Cliente cl);
};
#endif
