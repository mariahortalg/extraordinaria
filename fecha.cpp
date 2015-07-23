#include "fecha.h"

using namespace std;

Fecha::Fecha(){}

Fecha::Fecha(unsigned int d, unsigned int m, int a)
{
    dia = d;
    mes = m;
    anho = a;
}
unsigned int Fecha::getDia()
{
    return dia;
}
unsigned int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnho()
{
    return anho;
}
void Fecha::setDia(int d){
    dia= d;
}
void Fecha::setMes(int m){
    mes= m;
}
void Fecha::setAnho(int a){
    anho=a;
}

void Fecha::imprimirFecha()
{

}
void Fecha::cambiarFecha(unsigned int d, unsigned int m, int a)
{
    if(esCorrecta(d,m,a))
    {
        dia = d;
        mes = m;
        anho = a;
    }
    else
    {
        //cout<<"\nLa fecha introducida es incorrecta. Datos no modificados.";
    }

}
bool esCorrecta(unsigned int d, unsigned int m, int a)
{
    unsigned int arrayDiasMes[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    if(a==0) return false; //Aporte de susmel en comentarios.
    if(d<=0||d>31) return false;
    if(m<=0||m>12) return false;
    if(m==2 && d>29) return false;
    if(arrayDiasMes[m-1]<d) return false;
    if(m==2 && d==29 && !esBisiesto(a)) return false;
    return true;

}
bool esBisiesto(int a)
{
    if ((a%4==0)||(a%400==0)&&(a%100!=0)) return true;
    else return false;
}

