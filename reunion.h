#ifndef REUNION
#define REUNION
#include "list.h"
#include "fecha.h"
#define MAX 50
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>

class Reunion{  //definimos los prototipos de las funciones que contendra nuestro cpp

private:
    int id;
    char fecha [MAX];
    Fecha fechaReunion;

public:
    Reunion();
    ~Reunion();
    char resumen [MAX];
    char nombre[MAX];
    int numeroAl;
    const char* getResumen() const;
    void setResumen(const char* value);

    const char* getFecha() const;
    void setFecha(const char* value);

    Fecha getFechaReunion();
    void setFechaReunion(Fecha value);

    void readFromFile(std::fstream &f);
    void writeToFile(std::fstream &f);
    /*void readFromBinaryFile(std::fstream &f);
    void writeToBinaryFile(std::fstream &f);
    std::string toStd ();
*/
    int compareName(Reunion r);
    bool compareId(Reunion r);

    // //////////////////WRITE TO FILE////////////////////////////////////////
// asignamos el archivo de escritura en este caso para escribir el contenido de la reunion.
    void writeToFile(std::ostream *f)
    {
        *f << resumen << "\n" << nombre << "\n" << numeroAl << "\n"
          << fechaReunion.getDia() << "\n" << fechaReunion.getMes() << "\n"
          << fechaReunion.getAnho() << "\n";
    }

    // //////////////////READ FROM FILE////////////////////////////////////////
// pasamos por referencia el archivo para su posterior lectura con el uso de la funcion getline para separar cada atributo.
    void readFromFile(std::istream *f)
    {
        std::string buffer;
        int bufferNum;
        f->getline(resumen, MAX);
        f->getline(nombre, MAX);
        //f->getline(telefono, 200);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        numeroAl = bufferNum;
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaReunion.setDia(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaReunion.setMes(bufferNum);
        std::getline(*f, buffer);
        std::istringstream(buffer) >> bufferNum;
        fechaReunion.setAnho(bufferNum);
    }
};

#endif // REUNION

