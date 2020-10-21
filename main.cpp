#include<iostream>
#include "Menus.cpp"
#include <conio.h>

using namespace std;

int main (int argc, char *argv[]) {
	
	
	//guardar cliente
	//cout<<guardarCliente();
	//cout<<"\nPress any key\n";getch();system("cls");
	
	//actualizar cliente
	string b="";
	int resp=stoi(validarInput(b,"[^0-9]","Inserte cedula a actualizar"));b="";
	string campo=validarInput(b,"[^a-zA-Z ]","Campo a editar");b="";
	string valor=validarInput(b,"[*?]","Valor a guardar");
	cout<<actualizarCliente(resp,campo,valor);
	cout<<"\nPress any key\n";getch();system("cls");
	
	//listar todos los clientes
	cout<<"\n----Listar todos los clientes----\n";
	cout<<listarClientes();
	cout<<"\nPress any key\n";getch();system("cls");
	
	//listar todos los clientes activos
	cout<<"\n----Listar clientes activos----\n";
	cout<<listarClientesActivos();
	cout<<"\nPress any key\n";getch();system("cls");
	
	//listar todos los clientes suspendidos
	cout<<"\n----Listar clientes suspendidos----\n";
	cout<<listarClientesSusp();
	
	
	return 0;
}

