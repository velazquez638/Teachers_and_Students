#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#include "Persona.h"
#include "Profesor.h"

Profesor::Profesor(char * _dni, char * _nombre, int _edad, Fecha _ingreso, char * _titulacion, bool _doctorado) : Persona(_dni, _nombre, _edad) { //Constructor Profesor Heredando de Persona
	ingreso = _ingreso;
	strcpy_s(titulacion, _titulacion);
	doctorado = _doctorado;
}

Profesor::Profesor() { 

}

Profesor::~Profesor() { 
	cout << "El profesor " << get_Nombre() << " acaba de ser eliminado de nuestra base de datos" << endl;
}

Fecha Profesor::getFecha() { 
	return ingreso;
}

char * Profesor::get_Titulacion() {
	return titulacion;
}

bool Profesor::get_Doctorado() {
	return doctorado;
}

void Profesor::set_Fecha(Fecha _ingreso) { 
	ingreso = _ingreso;
}

void Profesor::set_Titulacion(char * _titulacion) { 
	strcpy_s(titulacion, _titulacion);
}

void Profesor::set_Doctorado(bool _doctorado) { 
	doctorado = _doctorado;
}

void Profesor::visualizar() { 
	Persona::visualizar();
	cout << "Fecha de ingreso en la universidad: " << ingreso.dia << "/" << ingreso.mes << "/" << ingreso.ano << endl;
	cout << "Titulacion: " << titulacion << endl;
	if (doctorado == true)
		cout << "Doctorado: Si" << endl;
	else
		cout << "Doctorado: No" << endl;
}