#include<iostream>
#include "Cliente.h"
using namespace std;

Cliente::Cliente(){
	cedula=0;
	nombre="";
	direccion="";
	numTarjeta=0;
	telefono=0;
	email="";
	estado="";
	
}
Cliente::~Cliente(){

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

string Cliente::toString(){}



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
