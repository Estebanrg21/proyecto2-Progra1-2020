#include<iostream>
#include "Clientes.h"
#include <string>
#include <regex>
#include <iterator>
#include <functional>
using namespace std;
string validarInput(string &data,string regx,string varName);

inline Cliente* crearCliente(){
	
	int ced=0, numTarjeta=0,telefono=0;
	string nombre="",direccion="",email="",estado="",data="";
	ced=stoi(validarInput(data,"[^0-9]","Cedula"));
	nombre=validarInput(data,"[^a-zA-Z ]","Nombre");
	direccion=validarInput(data,"[^a-zA-Z 0-9\.,]","Direccion");
	email=validarInput(data,"[^a-zA-Z0-9\-_.@]","Email");
	estado=validarInput(data,"[^a-zA-Z ]","Estado");
	numTarjeta=stoi(validarInput(data,"[^0-9]","Numero de tarjeta"));
	telefono=stoi(validarInput(data,"[^0-9]","Telefono"));
	Cliente *pc=new Cliente(ced,nombre,direccion,numTarjeta,telefono,email,estado);
	return pc;
	//!"#$%&/()=?¡'¿´+}{-.,;:_[¨*]4563dfg@32
}
inline string guardarCliente(){
	crearCliente();
}
	

inline string validarInput(string &data,string regx,string varName){
	
	function<string (string,string)> evalLine= 
		[&data,&evalLine](string regx,string varName) ->string{ 
			data="";
			regex reex(regx);
			cout<<"\n"+varName+":\n";getline(cin,data);
			smatch m;
			regex_search(data,m,reex,regex_constants::match_any);
			if(m.empty()){
				m.~match_results();
				if(data.empty()){
					evalLine(regx,varName);
				}
				else{
					return data;
				}
			}else{
				evalLine(regx,varName);
			}
			return data;
		};
	return evalLine(regx,varName);
	
}

