#include <iostream>
#include "reunion.h"
#define MAX 50

Reunion::Reunion(){//constructor
    this->id=0;
}

Reunion::~Reunion(){}//destructor

//asignacion de los valores en los getters y setters

const char* Reunion::getResumen() const{
  return resumen;
}
void Reunion::setResumen(const char * value){
    strcpy_s(resumen,MAX,value);
}

const char* Reunion::getFecha() const{
  return fecha;
}

void Reunion::setFecha(const char * value){
    strcpy_s(fecha,MAX,value);
}

Fecha Reunion::getFechaReunion()
{
    return fechaReunion;
}

void Reunion::setFechaReunion(Fecha value)
{
    fechaReunion = value;
}

int Reunion::compareName(Reunion o){
  return strcmp(this->fecha,o.fecha);
}

bool Reunion::compareId(Reunion o){
  return (this->id=o.id);
}


