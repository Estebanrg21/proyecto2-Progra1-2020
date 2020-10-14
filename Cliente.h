#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
using namespace std;
class Cliente{
private:
	int cedula;
	string nombre;
	string direccion;
	int numTarjeta;
	int telefono;
	string email;
	string estado;
	
public:
	Cliente();
	~Cliente();
	Cliente(int c,string n, string dir, int nt, int tel, string em, string es);
	int** getPedidos();
	string toString();
	int getCedula();
	void setCedula(int cedula);
	string getNombre();
	void setNombre(string nombre);
	string getDireccion();
	void setDireccion(string direccion);
	int getNumTarjeta();
	void setNumTarjeta(int numTarjeta);
	int getTelefono();
	void setTelefono(int telefono);
	string getEmail();
	void setEmail(string email);
	string getEstado();
	void setEstado(string estado);
	
};
#endif
