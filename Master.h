/*
 * Master.h
 *
 *  Created on: 20 nov. 2019
 *      Author: Alan
 */

#include "Videojuego.h"
#include <iostream>
using namespace std;
#include <list>

#ifndef MASTER_H_
#define MASTER_H_

class Master {
private:
	list<Videojuego> lista_Videojuegos;
public:
	Master();
	virtual ~Master();
	const list<Videojuego>& getListaVideojuegos() const;
	void setListaVideojuegos(const list<Videojuego>& listaVideojuegos);

	void primerInicio();
	void reescribirBackup();


	void cerrarSesion();
	void cerrarPrograma();
};

#endif /* MASTER_H_ */
