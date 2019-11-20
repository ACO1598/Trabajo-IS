#ifndef _USUARIONOIDENTIFICADO_
#define _USUARIONOIDENTIFICADO_

#include<iostream>
using namespace std;

class UsuarioNoIdentificado {
	public: 
		inline UsuarioNoIdentificado() {}
		virtual void menu()=0;
		virtual void mostrar()=0;
};

class Usuario:public UsuarioNoIdentificado {
private:
	int ID; //DNI
	string nombre;
	string apellidos;
	int fecha_nac;
	int telefono;
	string email;
	string direccion;
	string contraseña;
public: 
	//Constructor
	inline Usuario(int id, int f, int t, string n, string a, string e, string d, string c) {
		this->ID = id; this->fecha_nac = f; this->telefono = t;
		this->nombre = n; this->apellidos = a; this->email = e; this->direccion = d; this->contraseña = c;
	}
	inline Usuario(Usuario & u) { *this = u; }
	//Observadores
	inline string getNombre() const { return this->nombre; }
	inline string getApellidos() const { return this->apellidos; }
	inline string getEmail() const { return this->email; }
	inline string getDireccion() const { return this->direccion; }
	inline string getContraseña() const { return this->contraseña; }
	inline int getID() const { return this->ID; }
	inline int getFecha_nac() const { return this->fecha_nac; }
	inline int getTelefono() const { return this->telefono; }
	//Modificadores
	inline void setID(int id) { this->ID = id; }
	inline void setFecha_nac(int f) { this->fecha_nac = f; }
	inline void setTelefono(int t) { this->telefono = t; }
	inline void setNombre(string n) { this->nombre = n; }
	inline void setApellidos(string a) { this->apellidos = a; }
	inline void setEmail(string e) { this->email = e; }
	inline void setDireccion(string d) { this->direccion = d; }
	inline void setContraseña(string c) { this->contraseña = c; }

	//Funciones heredadas
	void mostrar();
	void menu();

	//Funciones propias
	void modificarDatosPersonales(); 
	void darseDeBaja();
	void mostrarListaDeVideojuegos();
	void buscarVideojuego();
	void busquedaPorFiltrado();

};

class Administrador: public Usuario {
public:

	//Funciones heredadas
	void mostrar();
	void menu();
	//Funciones propias
	Videojuego modificarVideojuego(Videojuego v);
	void añadirVideojuego();
	void eliminarVideojuego();
	void mostrarListaDeUsuarios();
	void mostrarUsuario(Usuario u);
	void darPrivilegiosAdmin();
	Usuario buscarUsuario();




};
#endif // !_USUARIONOIDENTIFICADO_



