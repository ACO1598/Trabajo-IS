#ifndef MASTER_H_
#define MASTER_H_

#include<list>
#include<iostream>
#include"UsuarioNoIdentificado.h"
#include"Videojuego.h"
#include"Usuario.h"
#include"Administrador.h"
using namespace std;


class Master {
private:
	list<Videojuego> lista_Videojuegos;
	list<Usuario> lista_Usuarios;
	list<Administrador> lista_Adminnistradores;
	/*Usuario* u;
	Administrador* a;*/
public:
	inline Master() { }//this->u = NULL; this->a = NULL;}
}
	inline Master(Usuario* usu) { this->u = usu; }
	virtual ~Master();
	//Usuario* getUsuario();
	list<Videojuego> getListaVideojuegos();
	list<Usuario> getListaUsuario();              //Quito los const por ahora
	list<Administrador> getListaAdministrador();
	void setListaVideojuegos(list<Videojuego> listaVideojuegos);
	//void setUsuario(const Usuario* us);

	void setListaUsuarios(const list<Usuario>& lu);
	void setListaAdministradores(const list<Administrador>& la);

	void primerInicio();
	void reescribirBackup();


	void cerrarSesion();
	void cerrarPrograma();
};

#endif /* MASTER_H_ */