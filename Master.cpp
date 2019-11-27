#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
#include"Usuario.h"
#include"Administrador.h"
using namespace std;



Usuario* Master::getUsuario() {
	return this->u;
}


list<Videojuego> Master::getListaVideojuegos()  {
	return this->lista_Videojuegos;
}
list<Usuario> Master::getListaUsuario() {
	return lista_Usuarios;
}
list<Administrador> Master::getListaAdministrador() {
	return lista_Adminnistradores;
}



void Master::setListaVideojuegos(const list<Videojuego>& listaVideojuegos) {
	lista_Videojuegos = listaVideojuegos;
}
void Master::setListaUsuarios(const list<Usuario>& lu) {
	lista_Usuarios = lu;
}
void Master::setListaAdministradores(const list<Administrador>& la) {
	lista_Adminnistradores = la;
}
void setUsuario(const Usuario* us) {

}



Master::~Master() {
	// TODO Auto-generated destructor stub
}