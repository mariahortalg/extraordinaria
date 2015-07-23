#ifndef FECHA
#define FECHA

#include <cstdlib>

//funciones de la clase fecha para las asignacion de los valores introducidos en la aplicacion

bool esCorrecta(unsigned int d, unsigned int m, int a);
bool esBisiesto (int a);
class Fecha
{
    public:
        Fecha(); //Constructor de la clase fecha.
        Fecha(unsigned int d, unsigned int m, int a); //Constructor de la clase fecha, recibe como parámetros un día (d), un mes (m) y un año (a).
        unsigned int getDia(); //Nos devuelve el día
        unsigned int getMes(); //Nos devuelve el mes
        int getAnho(); //Nos devuelve el año
        void setDia(int d); //asignacion del dia, mes y año
        void setMes(int m);
        void setAnho (int a);

        void imprimirFecha(); //Muestra por pantalla la fecha en formato d/m/a
        void cambiarFecha(unsigned int d, unsigned int m, int a); //Cambia la fecha
    private:
        unsigned int dia;
        unsigned int mes;
        int anho; //Años a.d.C.
};

#endif // FECHA

