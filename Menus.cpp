#include<iostream>
#include "Clientes.h"
#include <string>
#include <regex>
#include <iterator>
#include <functional>
#include <stdlib.h>//included specifically for system("cls")

using namespace std;
using json = nlohmann::json;
string guardarCliente(Cliente&cl,Clientes&ch);
string guardarCliente();
string validarInput(string &data,string regx,string varName);
Cliente* crearCliente();

/************** CLIENTES WRAPPERS **************/
inline string guardarCliente(){
	Clientes* ch = new Clientes;
	Cliente *p= crearCliente();
	string resp="";
	if(!(ch->ingresarCliente(*p))){
		resp=guardarCliente(*p,*ch);
	}
	if(resp==""){resp=p->toString();}
	delete ch;
	delete p;
	return resp;
}
	
inline string guardarCliente(Cliente&cl,Clientes&ch){
	string resp="";
	if(!(ch.ingresarCliente(cl))){
		int op=stoi(validarInput(resp,"[^0-9]","Dato no agregado, desea volver a intentarlo?\n1- Si\n0- No"));
		if(op){resp="";guardarCliente(cl,ch);}
	}
	resp="";
	resp=cl.toString();
	return resp;
}
		
inline string actualizarCliente(int ced, string campo, string valor){
	Clientes a;
	return a.actualizarCliente(ced,campo,valor);
}
	
inline bool eliminarCliente(int ced){
	Clientes a;
	return a.eliminarCliente(ced);
}
inline Lista<Cliente> listarClientes(){
	Clientes a;
	return a.listarClientes();
}

inline Lista<Cliente> listarClientesActivos(){
	Clientes a;
	return a.listarClientesActivos();
}

inline Lista<Cliente> listarClientesSusp(){
	Clientes a;
	return a.listarClientesSusp();
}
/************** CLIENTES WRAPPERS **************/




inline Cliente* crearCliente(){
	int ced=0, numTarjeta=0,telefono=0;
	string nombre="",direccion="",email="",estado="",data="";
	ced=stoi(validarInput(data,"[^0-9]","Cedula:"));
	nombre=validarInput(data,"[^a-zA-Z ]","Nombre:");
	direccion=validarInput(data,"[^a-zA-Z 0-9\.,]","Direccion:");
	email=validarInput(data,"[^a-zA-Z0-9\-_.@]","Email:");
	estado=validarInput(data,"[^a-zA-Z ]","Estado:");
	numTarjeta=stoi(validarInput(data,"[^0-9]","Numero de tarjeta:"));
	telefono=stoi(validarInput(data,"[^0-9]","Telefono:"));
	Cliente *pc=new Cliente(ced,nombre,direccion,numTarjeta,telefono,email,estado);
	return pc;
	
	//!"#$%&/()=?¡'¿´+}{-.,;:_[¨*]456 3dfg@32
}
	

inline string validarInput(string &data,string regx,string varName){
	
	function<string (string,string)> evalLine= 
		[&data,&evalLine](string regx,string varName) ->string{ 
			data="";
			regex reex(regx);
			system("cls");
			cout<<"\n"+varName+"\n";getline(cin,data);
			smatch m;
			regex_search(data,m,reex,regex_constants::match_any);
			if(m.empty()){
				m.~match_results();
				if(data.empty()){
					system("cls");
					evalLine(regx,varName);
				}
				else{
					return data;
				}
			}else{
				system("cls");
				evalLine(regx,varName);
			}
			return data;
		};
	return evalLine(regx,varName);
	
}


