#ifndef ALUMNO
#define ALUMNO
#define MAX 50
#include "list.h"
#include "reunion.h"
#include "fecha.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include "reunion.h"

//contiene los atributos y protoripos de las funciones correspondientes
class Alumno{
private:
    char nombre[MAX];
    char apellidos[MAX];
    int telefono;
    char email[MAX];


public:
    Alumno();
    ~Alumno();
    int id ;
    Fecha fechaOrdinaria;
    Fecha fechaExtraordinaria;

    int getTelefono() const;
    void setTelefono(int value);

    const char* getNombre() const;
    void setNombre(const char* value);

    const char* getApellidos() const;
    void setApellidos(const char* value);

    const char* getEmail() const;
    void setEmail(const char* value);

    Fecha getFechaOrdinaria();
    void setFechaOrdinaria(Fecha * value);
    Fecha getFechaExtraordinaria();
    void setFechaExtraordinaria(Fecha *value);

    void readFromFile(std::fstream &f);
    void writeToFile(std::fstream &f);
    /*void readFromBinaryFile(std::fstream &f);
    void writeToBinaryFile(std::fstream &f);
    std::string toStd ();
*/
    int compareName(Alumno a);
    bool compareId(Alumno a);
    //int compareId(Owner o);
    void getFechaOrdinaria(Fecha *value);
    void getFechaExtraordinaria(Fecha *value);

// //////////////////WRITE TO FILE////////////////////////////////////////

    // asignacion de un archivo de tipo escritura pasado a la funcion writeToFile para escribir los respectivos campos
    void writeToFile(std::ostream *f)
    {
        *f << nombre << std::endl << apellidos << std::endl << telefono << std::endl
          << email << std::endl << id << std::endl
          << fechaOrdinaria.getDia() << std::endl << fechaOrdinaria.getMes() << std::endl
             << fechaOrdinaria.getAnho() << std::endl << fechaExtraordinaria.getDia() << std::endl
                << fechaExtraordinaria.getMes() << std::endl << fechaExtraordinaria.getAnho() << std::endl;
    }

    // //////////////////READ FROM FILE////////////////////////////////////////

// asignacion de un archivo de tipo lectura pasado a la funcion readFromFile para leer los atributos gracias a la funcion getline
// que separa cada uno de estos.
    void readFromFile(std::istream *f)
    {
        std::string buffer;
        int bufferNum;
        f->getline(nombre, MAX);
        f->getline(apellidos, MAX);
        //f->getline(telefono, MAX);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        telefono = bufferNum;
        f->getline(email, MAX);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        id = bufferNum;
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaOrdinaria.setDia(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaOrdinaria.setMes(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaOrdinaria.setAnho(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaExtraordinaria.setDia(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaExtraordinaria.setMes(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaExtraordinaria.setAnho(bufferNum);
    }
};


#endif // ALUMNO

