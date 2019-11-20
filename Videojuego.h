/*
 * Videojuego.h
 *
 *  Created on: 20 nov. 2019
 *      Author: Alan
 */

#ifndef VIDEOJUEGO_H_
#define VIDEOJUEGO_H_

#include <iostream>
using namespace std;

class Videojuego {
private:
	string id, plataforma, genero, nombre, descripcion;
	int anio_lanzamiento;
	float precio;
public:
	Videojuego();
	virtual ~Videojuego();
	int getAnioLanzamiento() const;
	void setAnioLanzamiento(int anioLanzamiento);
	const string& getDescripcion() const;
	void setDescripcion(const string& descripcion);
	const string& getGenero() const;
	void setGenero(const string& genero);
	const string& getId() const;
	void setId(const string& id);
	const string& getNombre() const;
	void setNombre(const string& nombre);
	const string& getPlataforma() const;
	void setPlataforma(const string& plataforma);
	float getPrecio() const;
	void setPrecio(float precio);

	string comprobarID();
	void mostrar();
};

#endif /* VIDEOJUEGO_H_ */
