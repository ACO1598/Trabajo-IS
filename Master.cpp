/*
 * Master.cpp
 *
 *  Created on: 20 nov. 2019
 *      Author: Alan
 */

#include "Master.h"

Master::Master() {
	// TODO Auto-generated constructor stub

}

const list<Videojuego>& Master::getListaVideojuegos() const {
	return lista_Videojuegos;
}

void Master::setListaVideojuegos(const list<Videojuego>& listaVideojuegos) {
	lista_Videojuegos = listaVideojuegos;
}

Master::~Master() {
	// TODO Auto-generated destructor stub
}

