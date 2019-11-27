#ifndef _USUARIONOIDENTIFICADO_
#define _USUARIONOIDENTIFICADO_
#include<iostream>
#include"Videojuego.h"
#include"Master.h"
#include"Usuario.h"
#include"Administrador.h"
using namespace std;


class UsuarioNoIdentificado {
	public: 
		virtual void menu(Master m)=0;
		virtual void mostrar()=0;
};


#endif // !_USUARIONOIDENTIFICADO_



