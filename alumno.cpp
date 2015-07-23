#include <iostream>
#include "list.h"
#include "list.cpp"
#include "alumno.h"
#include "fecha.h"
#define MAX 50

Alumno::Alumno(){//Constructor
    this ->id=0;
}

Alumno::~Alumno(){}//destructor

//asignacion de valores en cada uno de los getters y setters

int Alumno::getTelefono() const{
  return telefono;
}
void Alumno::setTelefono(int value){
  telefono = value;
}

const char* Alumno::getNombre() const{
  return nombre;
}
void Alumno::setNombre(const char * value){
  strcpy_s(nombre,MAX,value);
}

const char* Alumno::getApellidos() const{
  return apellidos;
}
void Alumno::setApellidos(const char * value){
  strcpy_s(apellidos,MAX,value);
}

const char* Alumno::getEmail() const{
  return email;
}
void Alumno::setEmail(const char * value){
    strcpy_s(email,MAX,value);
}
Fecha Alumno::getFechaOrdinaria()
{
    return (Fecha)this->fechaOrdinaria;
}
void Alumno::getFechaOrdinaria(Fecha * value){
    //strcpy_s(fechaOrdinaria,MAX,value);
}
Fecha Alumno::getFechaExtraordinaria()
{
    return fechaExtraordinaria;
}
void Alumno::getFechaExtraordinaria(Fecha * value){
    //strcpy_s(fechaExtraordinaria,MAX,value);
}

int Alumno::compareName(Alumno a){
  return strcmp(this->nombre,a.nombre);
}

bool Alumno::compareId(Alumno o){
  return (this->telefono=o.telefono);
}
