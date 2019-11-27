#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
#include"Usuario.h"
#include"Administrador.h"
#include<list>
using namespace std;


Usuario Administrador::buscarUsuario(Master m) {
	int id;
	bool enc = false;
	cout << "Introduzca el DNI del usuario: " << endl;
	cin >> id;
	Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end() && enc != true) {
		if (it->getID() == id) {
			enc = true;
			Usuario uenc(*it);
		}
		else if (it == usuarios.end() && enc == false) {
			cout << "Lo siento, este usuario no se encuentra en el sistema" << endl;
			Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
		}
		it++;
	}

	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::iterator it2 = admins.begin();
	while (it2 != admins.end() && enc != true) {
		if (it2->getID() == id) {
			enc = true;
			Administrador uenc(*it2);  //Administrador hecho con constructor de usuario
		}
		else if (it2 == admins.end() && enc == false) {
			cout << "Lo siento, este usuario no se encuentra en el sistema" << endl;
			Usuario uenc(0, 0, 0, "0", "0", "0", "0", "0");
		}
		it2++;
	}
	return uenc;
}

void Administrador::darPrivilegiosAdmin(Master m) {
	cout << "Busque el usuario al que desea hacer administrador" << endl;
	Usuario enc = buscarUsuario(m);
	if (enc.getID() != 0) {
		m.getListaUsuario().erase(enc);
		cout << "Usuario eliminado" << endl;
		Administrador nuevo(enc);                 //Administrador hecho con constructor de usuario
		m.getListaAdministrador.push_back(nuevo);
		cout << "Nuevo administrador añadido" << endl;
	}
}

void Administrador::eliminarUsuario(Master m) {
	Usuario enc = buscarUsuario(m);
	m.getListaUsuario().erase(enc);  //¿Que pasa si el usuario encontrado es un administrador o no se encuentra el usuario?
}

void Administrador::mostrarListaDeUsuarios(Master m) {
	list<Usuario> usuarios = m.getListaUsuario();
	list<Usuario>::iterator it = usuarios.begin();
	while (it != usuarios.end()) {
		cout << "Usuario con DNI: " << (*it).getID() << endl;
		it++;
	}
	//¿Y los administradores?
	list<Administrador> admins = m.getListaAdministrador();
	list<Administrador>::iterator it2 = admins.begin();
	while (it2 != admins.end()) {
		cout << "Administrador con DNI: " << (*it2).getID() << endl;
		it2++;
	}
}

void Administrador::mostrar() {
	cout << "\nDNI: " << this->getID() << endl;
	cout << "Nombre: " << this->getNombre() << endl;
	cout << "Apellidos: " << this->getApellidos() << endl;
	cout << "Fecha de naciminento: " << this->getFecha_nac() << endl;
	cout << "Telefono: " << this->getTelefono() << endl;
	cout << "E-mail: " << this->getEmail() << endl;
	cout << "Dirección: " << this->getDireccion() << endl;
	cout << "Contraseña: " << this->getContraseña() << endl;
}

