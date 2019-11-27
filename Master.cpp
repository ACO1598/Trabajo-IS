/*
 * Master.cpp
 *
 *  Created on: 20 nov. 2019
 *      Author: Alan
 */

#include "Master.h"

Master::Master() {

	UsuarioConectado= new Usuario();

	bool intento= true;
	bool resultado;

	//Realizar la carga del back-up, comprobando primero si existe

	//Si no existe es debido a que el programa se acaba de instalar por lo que llevamos a cabo el caso del primer inicio
	//if(back-up no existe)

	cout<<"Gracias por instalar Gamogames para continuar introduzca los datos del primer administrador"<<endl;
	resultado= this->añadirAdmin();
	if(resultado==false){
		//Manda el usuario al menu
	}


}

const list<Videojuego>& Master::getListaVideojuegos() const {
	return lista_Videojuegos;
}

const list<UsuarioNoIdentificado>& Master::getListaUsuarios() const {
	return lista_Usuarios;
}

void Master::setListaUsuarios(
		const list<UsuarioNoIdentificado>& listaUsuarios) {
	lista_Usuarios = listaUsuarios;
}

void Master::setListaVideojuegos(const list<Videojuego>& listaVideojuegos) {
	lista_Videojuegos = listaVideojuegos;
}

Master::~Master() {
	// TODO Auto-generated destructor stub
}

//Esta funcion devuelve si el hecho de añadir un usuario a tenido exito o no
bool Master::añadirUsuario(){
	bool res;
	string DNI, nombre, apellido, email, direccion, contraseña;
	int fecha_nac, telefono;

	cout<<"DNI: "<<endl;
	cin>>DNI;
	cout<<"Nombre: "<<endl;
	cin>>nombre;
	cout<<"Apellido: "<<endl;
	cin>>apellido;
	cout<<"Email: "<<endl;
	cin>>email;
	cout<<"Fecha de nacimiento (DD/MM/AAAA): "<<endl;
	cin>>fecha_nac;
	cout<<"Telefono: "<<endl;
	cin>>telefono;
	cout<<"Dirección: "<<endl;
	cin>>direccion;
	cout<<"Contraseña: "<<endl;
	cin>>contraseña;

	//Comprobamos que si el DNI ya existe
	bool existe= false;
	for(Usuario o: this->lista_Usuarios){
		if(o.getID()== DNI){
			existe= true;
			break;
		}
	}

	if(existe== false){
		Usuario newUs= new Usuario(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contraseña);
		this->lista_Usuarios.push_back(newUs);
		res= true;
	}else{
		res=false;
	}

	return res;
}

//Misma funcion que la funcion anterior solo que añadiendo un administrador
bool Master::añadirAdmin(){
	bool res;
	string DNI, nombre, apellido, email, direccion, contraseña;
	int fecha_nac, telefono;

	cout<<"DNI: "<<endl;
	cin>>DNI;
	cout<<"Nombre: "<<endl;
	cin>>nombre;
	cout<<"Apellido: "<<endl;
	cin>>apellido;
	cout<<"Email: "<<endl;
	cin>>email;
	cout<<"Fecha de nacimiento (DD/MM/AAAA): "<<endl;
	cin>>fecha_nac;
	cout<<"Telefono: "<<endl;
	cin>>telefono;
	cout<<"Dirección: "<<endl;
	cin>>direccion;
	cout<<"Contraseña: "<<endl;
	cin>>contraseña;

	//Comprobamos que si el DNI ya existe
	bool existe= false;
	for(Usuario o: this->lista_Usuarios){
		if(o.getID()== DNI){
			existe= true;
			break;
		}
	}

	if(existe== false){
		Administrador newUs= new Usuario(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contraseña);
		this->lista_Usuarios.push_back(newUs);
		res= true;
	}else{
		res=false;
	}

	return res;
}

void Master::primerInicio(){
	this->añadirAdmin();
}
