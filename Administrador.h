#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_

#include<iostream>
#include"Usuario.h"
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Master.h"
using namespace std;


class Administrador : public Usuario {
public:
	//Faltan constructores
	inline Administrador(){}
	inline Administrador(Administrador& a) { *this = a; }
	//Funciones heredadas
	void mostrar();
	void menu(Master m);
	//Funciones propias
	Videojuego modificarVideojuego(Videojuego v);
	void añadirVideojuego();
	void eliminarVideojuego(Master m);
	void eliminarUsuario(Master m);
	void mostrarListaDeUsuarios(Master m);
	void mostrarUsuario(Usuario u);
	void darPrivilegiosAdmin(Master m);
	Usuario buscarUsuario(Master m);




};
#endif // !_ADMINISTRADOR_H_

