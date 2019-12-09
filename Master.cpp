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

Administrador* Master::getAdministrador() {
	return this->a;
}


list<Videojuego> Master::getListaVideojuegos()  {
	return this->lista_Videojuegos;
}
list<Usuario> Master::getListaUsuario() {
	return lista_Usuarios;
}
list<Administrador> Master::getListaAdministrador() {
	return lista_Administradores;
}



void Master::setListaVideojuegos(list<Videojuego> listaVideojuegos) {
	lista_Videojuegos = listaVideojuegos;
}
void Master::setListaUsuarios(const list<Usuario>& lu) {
	lista_Usuarios = lu;
}
void Master::setListaAdministradores(const list<Administrador>& la) {
	lista_Administradores = la;
}

Master::~Master() {
	// TODO Auto-generated destructor stub
}

//Esta funcion devuelve si el hecho de a�adir un usuario a tenido exito o no
bool Master::a�adirUsuario() {
	bool res;
	string nombre, apellido, email, direccion, contrase�a;
	int fecha_nac, telefono, DNI;

	cout << "DNI: " << endl;
	cin >> DNI;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	cout << "Email: " << endl;
	cin >> email;
	cout << "Fecha de nacimiento (DD/MM/AAAA): " << endl;
	cin >> fecha_nac;
	cout << "Telefono: " << endl;
	cin >> telefono;
	cout << "Direcci�n: " << endl;
	cin >> direccion;
	cout << "Contrase�a: " << endl;
	cin >> contrase�a;

	//Comprobamos que si el DNI ya existe
	bool existe = false;
	for (Usuario o : this->lista_Usuarios) {
		if (o.getID() == DNI) {
			existe = true;
			break;
		}
	}

	if (existe == false) {
		Usuario newUs(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrase�a);
		this->lista_Usuarios.push_back(newUs);
		res = true;
	}
	else {
		res = false;
	}

	return res;
}

//Misma funcion que la funcion anterior solo que a�adiendo un administrador
bool Master::a�adirAdmin() {
	bool res;
	string nombre, apellido, email, direccion, contrase�a;
	int fecha_nac, telefono, DNI;

	cout << "DNI: " << endl;
	cin >> DNI;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	cout << "Email: " << endl;
	cin >> email;
	cout << "Fecha de nacimiento (DD/MM/AAAA): " << endl;
	cin >> fecha_nac;
	cout << "Telefono: " << endl;
	cin >> telefono;
	cout << "Direcci�n: " << endl;
	cin >> direccion;
	cout << "Contrase�a: " << endl;
	cin >> contrase�a;

	//Comprobamos que si el DNI ya existe
	bool existe = false;
	for (Usuario o : this->lista_Usuarios) {
		if (o.getID() == DNI) {
			existe = true;
			cout << "Este usuario ya existe como no administrador" << endl;
		}
	}

	for (Administrador a : this->getListaAdministrador) {
		if (a.getID() == DNI) {
			existe = true;
			cout << "Este usuario ya existe como administrador" << endl;
		}
	}

	if (existe == false) {
		Usuario newUs(DNI, fecha_nac, telefono, nombre, apellido, email, direccion, contrase�a);
		Administrador newAd(newUs);
		this->lista_Administradores.push_back(newAd);
		res = true;
	}
	else {
		res = false;
	}

	return res;
}

void Master::iniciarSesion(Master master) {
	string email;
	string contrase�a;
	cout << "Introduzca sus datos por favor" << endl;
	cout << "email: " << endl;
	cin >> email;
	cout << "contrase�a: " << endl;
	cin >> contrase�a;

	bool existe = false;

	for (Administrador a : this->lista_Administradores) {
		if (a.getEmail() == email) {
			existe = true;
			if (a.getContrase�a() == contrase�a) {
				cout << "Bienvenido" << endl;
				this->setAdministrador(a); //Si eliminamos este atributo del master esta funcion tendra que devolver un usuario o administrador
				a.menu(master);
			}
			else {
				cout << "La contrase�a no es correcta" << endl;
			}
			break;
		}
	}

	for (Usuario o : this->lista_Usuarios) {
		if (o.getEmail() == email) {
			existe = true;
			if (o.getContrase�a() == contrase�a) {
				cout << "Bienvenido" << endl;
				this->setUsuario(o);
				o.menu(master);
			}
			else {
				cout << "La contrase�a no es correcta" << endl;
			}
			break;
		}
	}

	if (existe == false) {
		cout << "El email introducido no existe" << endl;
	}
}

void Master::primerInicio() {
	list<Administrador> tempAd = this->getListaAdministrador;
	if (tempAd.empty) {
		cout << "Gracias por elegir GamoGames a continuacion se le pedira que introduzca sus datos como administrador" << endl;
		while (a�adirAdmin() == false) {
			cout << "Por favor introduzca un administrador valido" << endl;
		}
		cout << "A continuacion se le mostrara el menu de inicio" << endl;
	}
}

void Master::menuInicio() {
	cout << "-------------------------------- MEN� INICIO --------------------------------" << endl;
	cout << "\n\n1)Iniciar Sesi�n" << endl;
	cout << "\n\n2)Registrarse" << endl;
	cout << "\n\n3)Salir" << endl;
	int eleccion;
	cout << "\nIntroduzca un numero con su eleccion" << endl;
	cin >> eleccion;

	switch (eleccion) {
	case 1: 
		this->iniciarSesion();
		break;

	case 2: 
		bool bandera;
		bandera= this->a�adirUsuario();
		if (bandera == true) {
			cout << "Usuario registrado con exito, por favor inicie sesi�n" << endl;
		}
		else {
			cout << "Este usuario ya existe en el sistema" << endl;
		}
		menuInicio();
		break;

	case 3: 
		//Cerrar el programa , reescribir backups default

	default: 
		cout << "La opcion escogida no es valida, por favor vuelva a introducir un numero con su eleccion" << endl;
		cin >> eleccion;
	}

}