#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#include "Persona.h"
#include "Alumno.h"


Alumno::Alumno(char * _dni, char * _nombre, int _edad, char * _curso) : Persona(_dni, _nombre, _edad) { //hereda de la clase persona
	strcpy_s(curso, _curso); //comando que me iguala terminos
}

Alumno::Alumno() { 

}

Alumno::~Alumno() { 
	cout << "El alumno " << get_Nombre() << " acaba de ser eliminado de la base de datos de la universidad" << endl;
}

char * Alumno::get_Curso() { 
	return curso;
}

void Alumno::set_Curso(char * _curso) { 
	strcpy_s(curso, _curso);
}

void Alumno::visualizar() { 
	Persona::visualizar();
	cout << "Curso: " << curso << endl;
}