#include<iostream>
#include "Cliente.h"
#include <sstream> 
#include <string>
using namespace std;
using json = nlohmann::json;
Cliente::Cliente(){
	cedula=0;
	nombre="";
	direccion="";
	numTarjeta=0;
	telefono=0;
	email="";
	estado="";
	
}

Cliente::Cliente(nlohmann::basic_json<> jdata,string key){
	cedula=stoi(key);
	nombre=jdata["nombre"];
	direccion=jdata["direccion"];
	numTarjeta=stoi((string)jdata["numTarjeta"]);
	telefono=stoi((string)jdata["telefono"]);
	email=jdata["email"];
	estado=jdata["estado"];
}

Cliente::~Cliente(){
	//cout<<"\ndeleted: "<<to_string(cedula)<<"\n";
}
Cliente::Cliente(int c,string n, string dir, int nt, int tel, string em, string es){
	cedula=c;
	nombre=n;
	direccion=dir;
	numTarjeta=nt;
	telefono=tel;
	email=em;
	estado=es;
}

int** Cliente::getPedidos(){
	
}

string Cliente::toString() const{
	stringstream ss;
	ss<<"\nCedula: "<<to_string(cedula);
	ss<<"\nNombre: "<<nombre;
	ss<<"\nDireccion: "<<direccion;
	ss<<"\nEmail: "<<email;
	ss<<"\nEstado: "<<estado;
	ss<<"\nNumero de tarjeta: "<<to_string(numTarjeta);
	ss<<"\nNumero de telefono: "<<to_string(telefono)<<"\n";
	return ss.str();
}

int Cliente::getCedula(){
	return cedula;
}
void Cliente::setCedula(int cedula){
	this->cedula=cedula;
}
string Cliente::getNombre(){
	return nombre;
}
void Cliente::setNombre(string nombre){
	this->nombre=nombre;
}
string Cliente::getDireccion(){
	return direccion;
}
void Cliente::setDireccion(string direccion){
	this->direccion=direccion;
}
int Cliente::getNumTarjeta(){
	return numTarjeta;
}
void Cliente::setNumTarjeta(int numTarjeta){
	this->numTarjeta=numTarjeta;
}
int Cliente::getTelefono(){
	return telefono;
}
void Cliente::setTelefono(int telefono){
	this->telefono=telefono;
}
string Cliente::getEmail(){
	return email;
}
void Cliente::setEmail(string email){
	this->email=email;
}
string Cliente::getEstado(){
	return estado;
}
void Cliente::setEstado(string estado){
	this->estado=estado;
}


ostream&operator<<(ostream& os, const Cliente&cl)
{
	os << cl.toString();
	return os;
}
