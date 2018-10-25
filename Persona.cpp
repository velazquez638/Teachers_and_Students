#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#include "Persona.h"

Persona::Persona(char *_dni, char *_nombre, int _edad) { 
	strcpy_s(dni, _dni);
	strcpy_s(nombre, _nombre);
	edad = _edad;
}

Persona::Persona() { 

}

Persona::~Persona() { 
}

char * Persona::get_Dni() { //para posteriormente manejar los datos usaremos getters y setters
	return dni;
}

char* Persona::get_Nombre() { 
	return nombre;
}

int Persona::get_Edad() { 
	return edad;
}

void Persona::set_Nombre(char *_nombre) { 
	strcpy_s(nombre, _nombre);
}

void Persona::set_Edad(int _edad) { 
	edad = _edad;
}

void Persona::visualizar() { 
	cout << "DNI: " << dni << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
}