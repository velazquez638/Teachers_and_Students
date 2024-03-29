// PracticaFinal.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Persona.h"
#include "Profesor.h"
#include "Alumno.h"

void menu(); //funciones a usar
void gestion_Profesor();
void gestion_Alumno();
void alta_Profesor();
void alta_Alumno();
void consultar_Profesor();
void consultar_Alumno();
void modificar_Profesor();
void modificar_Alumno();
void baja_Alumno();
void baja_Profesor();

Alumno *A[45]; 
Profesor *P[45];
int cont_1 = 0, cont_2 = 0;

int main()
{
	menu();

	return 0;
}

void menu() { //menu principal por el que llamo a las finciones de alumno y profesor
	int opc;
	do {
		cout << "\tbienvenido a nuestra base de datos que accion desea realizar:" << endl << endl;
		cout << "-1- Gestion de un Profesor" << endl;
		cout << "-2- Gestion de un Alumno" << endl;
		cout << "-3- Salir" << endl;
		cin >> opc;
		system("cls");
		switch (opc)
		{
		case 1:
			gestion_Profesor();
			break;
		case 2:
			gestion_Alumno();
			break;
		case 3:
			cout << endl << "\tgracias por visitarnos" << endl << endl;
			break;
		default:
			cout << "Introduce una opcion correcta" << endl;
			system("cls");
			break;

		}
	} while (opc != 3);
}

void gestion_Profesor() { 
	int opcion_Profesor;
	do {
		cout << "-1- Alta de un profesor" << endl;
		cout << "-2- Baja de un profesor" << endl;
		cout << "-3- Modificar datos de un profesor" << endl;
		cout << "-4- Consultar datos de un profesor" << endl;
		cout << "-5- Volver al menu principal" << endl;
		cin >> opcion_Profesor;
		system("cls");
		switch (opcion_Profesor)
		{
		case 1:
			alta_Profesor();
			system("cls");
			break;
		case 2:
			baja_Profesor();
			system("cls");
			break;
		case 3:
			modificar_Profesor();
			system("cls");
			break;
		case 4:
			consultar_Profesor();
			system("cls");
			break;
		case 5:

			break;
		default:
			cout << "Introduzca una opcion correcta" << endl;
			system("cls");
		}
	} while (opcion_Profesor != 5);
}

void gestion_Alumno() { 
	int opcion_Alumno;
	do {
		cout << "-1- Alta de un alumno" << endl;
		cout << "-2- Baja de un alumno" << endl;
		cout << "-3- Modificar datos de un alumno" << endl;
		cout << "-4- Consultar datos de un alumno" << endl;
		cout << "-5- Volver al menu principal" << endl;
		cin >> opcion_Alumno;
		system("cls");
		switch (opcion_Alumno)
		{
		case 1:
			alta_Alumno();
			system("cls");
			break;
		case 2:
			baja_Alumno();
			system("cls");
			break;
		case 3:
			modificar_Alumno();
			system("cls");
			break;
		case 4:
			consultar_Alumno();
			system("cls");
			break;
		case 5:

			break;
		default:
			cout << "Introduzca una opcion correcta" << endl;
			system("cls");
		}
	} while (opcion_Alumno != 5);
}



void alta_Profesor() {
	char dni[9], nombre[50], titulacion[20];
	int edad;
	struct Fecha ingreso;
	bool doctorado;
	cout << "Dni: ";
	cin >> dni;
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Edad: ";
	cin >> edad;
	cout << "Fecha de ingreso en la universidad:" << endl;
	cout << "Dia: ";
	cin >> ingreso.dia;
	cout << "Mes: ";
	cin >> ingreso.mes;
	cout << "Ano: ";
	cin >> ingreso.ano;
	cout << "Titulacion: ";
	cin >> titulacion;
	cout << "Doctorado SI (1)  No (0): ";
	cin >> doctorado;


	P[cont_2] = new Profesor(dni, nombre, edad, ingreso, titulacion, doctorado); //se ingresa en el array
	cont_2++; 
}

void consultar_Profesor() {
	char dni2[9];
	bool esta = false;
	cout << "Ingrese el DNI del profesor a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_2; i++) {
		if (strcmp(dni2, P[i]->get_Dni()) == 0) { //en este punto busca al profesor en el array
			P[i]->visualizar();
			esta = true; 
			break;
		}
	}
	if (esta == false)
		cout << "La persona con DNI " << dni2 << " no se encuentra en la base de datos de profesores" << endl;
	system("pause");
}

void modificar_Profesor() {
	char dni2[9], nombre2[50], titulacion2[20];
	int edad2;
	struct Fecha ingreso2;
	bool doctorado2;
	bool esta = false;
	cout << "Ingrese el DNI del profesor a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_2; i++) {
		if (strcmp(dni2, P[i]->get_Dni()) == 0) { 
			cout << "Nombre: ";
			cin >> nombre2;
			P[i]->set_Nombre(nombre2);
			cout << "Edad: ";
			cin >> edad2;
			P[i]->set_Edad(edad2);
			cout << "Fecha de ingreso en la universidad:" << endl;
			cout << "Dia: ";
			cin >> ingreso2.dia;
			cout << "Mes: ";
			cin >> ingreso2.mes;
			cout << "Ano: ";
			cin >> ingreso2.ano;
			P[i]->set_Fecha(ingreso2);
			cout << "Titulacion: ";
			cin >> titulacion2;
			P[i]->set_Titulacion(titulacion2);
			cout << "Doctorado <1> Si <0> No: ";
			cin >> doctorado2;
			P[i]->set_Doctorado(doctorado2);


			esta = true; 
			break;
		}
	}
	if (esta == false) 
		cout << "La persona con DNI " << dni2 << " no se encuentra en la base de datos de profesores" << endl;
	system("pause");
	system("cls");
}

void baja_Profesor() {
	char dni2[9];
	bool esta = false;
	cout << "Ingrese el DNI del profesor a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_2; i++) {
		if (strcmp(dni2, P[i]->get_Dni()) == 0) { 
			if (i == cont_2) {
				P[i]->~Profesor(); 
				P[i] = NULL; 
				cont_2--; 
				esta = true; 
				break;
			}
			else {
				P[i]->~Profesor(); 
				for (int j = i + 1; j < cont_2; j++)
					P[j - 1] = P[j];
				P[cont_2] = NULL;
				cont_2--; 
				esta = true; 
				break;
			}
		}
	}
	if (esta == false)
		cout << "La persona con DNI " << dni2 << " no se encuentra en la base de datos de profesores" << endl;
	system("pause");
}



void alta_Alumno() {
	char dni[9], nombre[50], curso[5];
	int edad;
	cout << "Dni: ";
	cin >> dni;
	cout << "Nombre: ";
	cin >> nombre;
	cout << "Edad: ";
	cin >> edad;
	cout << "Curso: ";
	cin >> curso;

	A[cont_1] = new Alumno(dni, nombre, edad, curso); 
	cont_1++; 
}

void modificar_Alumno() {
	char dni2[9], nombre2[50], curso2[5];
	int edad2;
	bool esta = false;
	cout << "Ingrese el DNI del alumno a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_1; i++) {
		if (strcmp(dni2, A[i]->get_Dni()) == 0) { 
			cout << "Nombre: ";
			cin >> nombre2;
			A[i]->set_Nombre(nombre2);
			cout << "Edad: ";
			cin >> edad2;
			A[i]->set_Edad(edad2);
			cout << "Curso: ";
			cin >> curso2;
			A[i]->set_Curso(curso2);

			esta = true; 
			break;
		}
	}
	if (esta == false) 
		cout << "La persona con DNI " << dni2 << " no se encuentra en la base de datos de alumnos" << endl;
	system("pause");
	system("cls");
}

void consultar_Alumno() {
	char dni2[9];
	bool esta = false;
	cout << "Ingrese el DNI del alumno a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_1; i++) {
		if (strcmp(dni2, A[i]->get_Dni()) == 0) { 
			A[i]->visualizar();
			esta = true; 
			break;
		}
	}
	if (esta == false) 
		cout << "La persona con DNI " << dni2 << " no se encuentra en la base de datos de alumnos" << endl;
	system("pause");
}

void baja_Alumno() {
	char dni2[9];
	bool esta = false;
	cout << "Ingrese el DNI del alumno a buscar: ";
	cin >> dni2;
	system("cls");
	for (int i = 0; i < cont_1; i++) { 
		if (strcmp(dni2, A[i]->get_Dni()) == 0) { 
			if (i == cont_1) {
				A[i]->~Alumno(); 
				A[i] = NULL; 
				cont_1--;
				esta = true; 
				break;
			}
			else {
				A[i]->~Alumno(); 
				for (int j = i+1; j < cont_1; j++)
					A[j - 1]=A[j];
				A[cont_1] = NULL;
				cont_1--; 
				esta = true; 
				break;
			}
		}
	}
	if (esta == false) 
		cout << "La persona con DNI " << dni2 << " no coincide con ninguno de nuestros alumnos." << endl;
	system("pause");
}