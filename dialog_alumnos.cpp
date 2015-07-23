#include "dialog_alumnos.h"
#include "ui_dialog_alumnos.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

Dialog_alumnos::Dialog_alumnos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_alumnos)
{
    ui->setupUi(this);
}

Dialog_alumnos::~Dialog_alumnos()
{
    delete ui;
}

void Dialog_alumnos::on_pushButton_Guardar_clicked()  //boton añadir alumno
{
    if (modificando == true) { //asignacion de los valores introducidos
        QString name= ui->lineEdit_Nombre->text();
        QString surname= ui->lineEdit_Apellidos->text();
        QString emilio= ui->lineEdit_Email->text();
        int number= ui->lineEdit_Telefono->text().toInt();
        Fecha ord;
        Fecha ext;
        ord.setDia(ui->dateEdit->date().day());
        ord.setMes(ui->dateEdit->date().month());
        ord.setAnho(ui->dateEdit->date().year());
        ext.setDia(ui->dateEdit_2->date().day());
        ext.setMes(ui->dateEdit_2->date().month());
        ext.setAnho(ui->dateEdit_2->date().year());

        a.setNombre(name.toLocal8Bit().data());
        a.setApellidos(surname.toLocal8Bit().data());
        a.setEmail(emilio.toLocal8Bit().data());
        a.setTelefono(number);
        a.fechaOrdinaria = ord;
        a.fechaExtraordinaria = ext;


        auto it = al->begin();
        for(int i = 0; i<numeroModificar; ++i){
            it++;
        }

        al->erase(it);
        al->pushFront(a);

        this->close();
    }
    else{

        QString name= ui->lineEdit_Nombre->text();
        QString surname= ui->lineEdit_Apellidos->text();
        QString emilio= ui->lineEdit_Email->text();
        int number= ui->lineEdit_Telefono->text().toInt();
        Fecha ord;
        Fecha ext;
        ord.setDia(ui->dateEdit->date().day());
        ord.setMes(ui->dateEdit->date().month());
        ord.setAnho(ui->dateEdit->date().year());
        ext.setDia(ui->dateEdit_2->date().day());
        ext.setMes(ui->dateEdit_2->date().month());
        ext.setAnho(ui->dateEdit_2->date().year());

        a.setNombre(name.toLocal8Bit().data());
        a.setApellidos(surname.toLocal8Bit().data());
        a.setEmail(emilio.toLocal8Bit().data());
        a.setTelefono(number);
        srand(time(NULL));
        a.id = rand(); //Identificador unico - sirve para eliminar sus reuniones
        a.fechaOrdinaria = ord;
        a.fechaExtraordinaria = ext;

        al->pushFront(a);

        ui->lineEdit_Nombre->clear();
        ui->lineEdit_Apellidos->clear();
        ui->lineEdit_Email->clear();
        ui->lineEdit_Telefono->clear();

    }
}

void Dialog_alumnos::modificar() //funcion modificar, que será llamada desde la clase mainwindow una vez pulsado su boton
{
    auto it = al->begin();
    for(int i = 0; i<numeroModificar; ++i){
        it++;
    }

    modificando = true; //recuperamos los valores
    ui->lineEdit_Nombre->setText(it->getNombre());
    ui->lineEdit_Apellidos->setText(it->getApellidos());
    ui->lineEdit_Email->setText(it->getEmail());
    ui->lineEdit_Telefono->setText(QString(it->getTelefono()));
    ui->dateEdit->setDate(QDate(it->fechaOrdinaria.getAnho(), it->fechaOrdinaria.getMes(), it->fechaOrdinaria.getDia()));
    ui->dateEdit_2->setDate(QDate(it->fechaExtraordinaria.getAnho(), it->fechaExtraordinaria.getMes(), it->fechaExtraordinaria.getDia()));
}
