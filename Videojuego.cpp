/*
 * Videojuego.cpp
 *
 *  Created on: 20 nov. 2019
 *      Author: Alan
 */

#include "Videojuego.h"

Videojuego::Videojuego() {
	// TODO Auto-generated constructor stub

}

int Videojuego::getAnioLanzamiento() const {
	return anio_lanzamiento;
}

void Videojuego::setAnioLanzamiento(int anioLanzamiento) {
	anio_lanzamiento = anioLanzamiento;
}

const string& Videojuego::getDescripcion() const {
	return descripcion;
}

void Videojuego::setDescripcion(const string& descripcion) {
	this->descripcion = descripcion;
}

const string& Videojuego::getGenero() const {
	return genero;
}

void Videojuego::setGenero(const string& genero) {
	this->genero = genero;
}

const string& Videojuego::getId() const {
	return id;
}

void Videojuego::setId(const string& id) {
	this->id = id;
}

const string& Videojuego::getNombre() const {
	return nombre;
}

void Videojuego::setNombre(const string& nombre) {
	this->nombre = nombre;
}

const string& Videojuego::getPlataforma() const {
	return plataforma;
}

void Videojuego::setPlataforma(const string& plataforma) {
	this->plataforma = plataforma;
}

float Videojuego::getPrecio() const {
	return precio;
}

void Videojuego::setPrecio(float precio) {
	this->precio = precio;
}

Videojuego::~Videojuego() {
	// TODO Auto-generated destructor stub
}

Videojuego::comprobarID(){

}

Videojuego::mostrar(){
	cout<<"Nombre: "<<this->getNombre()<<endl;
	cout<<"Plataforma: "<<this->getPlataforma()<<endl;
	cout<<"Genero: "<<this->getGenero()<<endl;
	cout<<"Año de lanzamiento: "<<this->getAnioLanzamiento()<<endl;
	cout<<"Precio: "<<this->getPrecio()<<endl;
	cout<<"Descripción: "<<this->getDescripcion()<<endl;
}
