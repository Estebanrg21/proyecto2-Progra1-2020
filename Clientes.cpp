#include<iostream>
#include "Menus.cpp"

using namespace std;
using json = nlohmann::json;

int Clientes::instancias=0;
Clientes::Clientes(){
	instancias++;
	mynum=instancias;
}
Clientes::~Clientes(){
	//cout<<"\ndeleted "<<to_string(mynum)<<"\n";
}



bool Clientes::ingresarCliente(Cliente& cl){
	
	try{
		ifstream clientesJson("./db/Clientes.json");
		json jmain;
		clientesJson>>jmain;
		clientesJson.close();
		json arr=json::array({});
		json jcbody = json::object({ 
			{"nombre", cl.getNombre()},
			{"direccion",(cl.getDireccion())},
			{"numTarjeta",to_string(cl.getNumTarjeta())},
			{"telefono",to_string(cl.getTelefono())},
			{"email",cl.getEmail()},
			{"estado",cl.getEstado()},
			{"pedidos",arr}
		}); 
		jmain["clientes"].emplace(to_string(cl.getCedula()),jcbody);
		ofstream writer("./db/Clientes.json");
		writer << setw(4) << jmain << std::endl;
		writer.close();
		return true;
	}catch(...){
		return false;
	}
	
	return false;
}


string Clientes::actualizarCliente(int ced,string field, string val){
	ifstream clientesJson("./db/Clientes.json");
	json jmain;
	clientesJson>>jmain;
	clientesJson.close();
	auto cliente=jmain["clientes"].find(to_string(ced));
	if(cliente!= jmain["clientes"].end() && (field!="pedidos")){
		try{
			
			if(!(((*cliente)[field]==(val)))){
				(*cliente)[field]=val;
				Cliente p(*cliente,cliente.key());
				ofstream writer("./db/Clientes.json");
				writer << setw(4) << jmain << std::endl;
				writer.close();
				return(p.toString());
			}
			return "No actualizado, el campo "+field+" ya se encontraba con el valor "+val;
		}catch(...){
			return "No actualizado (el tipo del campo no corresponde)";
		}
	}else{
		return "No actualizado (el cliente no existe o introdujo un campo invalido)";
	}
	return "No actualizado (error desconocido)";
	
}


bool Clientes::eliminarCliente(int ced){
	ifstream clientesJson("./db/Clientes.json");
	json jmain;
	clientesJson>>jmain;
	clientesJson.close();
	auto cliente=jmain["clientes"].find(to_string(ced));
	if(cliente!= jmain["clientes"].end()){
		jmain["clientes"].erase(cliente);
		ofstream writer("./db/Clientes.json");
		writer << setw(4) << jmain << std::endl;
		writer.close();
		return true;
	}else{
		return false;
	}
	return false;
	
}
Lista<Cliente> Clientes::listarClientes(){
	ifstream clientesJson("./db/Clientes.json");
	json jmain;
	clientesJson>>jmain;
	clientesJson.close();
	Lista<Cliente>l;
	for (auto& el : jmain["clientes"].items()){
		l.append(Cliente(el.value(),el.key()));
	}
	return l;
}
Lista<Cliente> Clientes::listarClientesActivos(){
	ifstream clientesJson("./db/Clientes.json");
	json jmain;
	clientesJson>>jmain;
	clientesJson.close();
	Lista<Cliente>l;
	for (auto& el : jmain["clientes"].items()){
		if(el.value()["estado"]=="activo"){
			l.append(Cliente(el.value(),el.key()));
		}
	}
	return l;
}
Lista<Cliente> Clientes::listarClientesSusp(){
	ifstream clientesJson("./db/Clientes.json");
	json jmain;
	clientesJson>>jmain;
	clientesJson.close();
	Lista<Cliente>l;
	for (auto& el : jmain["clientes"].items()){
		if(el.value()["estado"]=="suspendido"){
			l.append(Cliente(el.value(),el.key()));
		}
	}
	return l;
}

