#include "dialog_reuniones.h"
#include "ui_dialog_reuniones.h"
#include <QDebug>

Dialog_reuniones::Dialog_reuniones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_reuniones)
{
    ui->setupUi(this);
}

Dialog_reuniones::~Dialog_reuniones()
{
    delete ui;
}

void Dialog_reuniones::modificar()
{
    modificando = true;

    auto it = re->begin();
    for(int i = 0; i<numeroModificar; ++i){
        it++;
    }

    ui->lineEdit_Resumen->setText(it->resumen);
    //ui->dateEdit->setText(it->getApellidos());
}

void Dialog_reuniones::on_pushButton_Guardar_clicked() //añadir reunion
{

    if(modificando == false){
    QString resu= ui->lineEdit_Resumen->text();
    Fecha f;
    f.setDia(ui->dateEdit->date().day());
    f.setMes(ui->dateEdit->date().month());
    f.setAnho(ui->dateEdit->date().year());

    Reunion r;
    r.setResumen(resu.toLocal8Bit().data());
    r.setFechaReunion(f);

    auto it = al->begin();
    for(int i = 0; i < numero; ++i){
        it++;
    }
    strcpy_s(r.nombre, it->getNombre());
    r.numeroAl = it->id;

    re->pushFront(r);
    //re->writeToFile("owner.txt");

    ui->lineEdit_Resumen->clear();
    }
    else {
        QString resu= ui->lineEdit_Resumen->text();
        Fecha f;
        f.setDia(ui->dateEdit->date().day());
        f.setMes(ui->dateEdit->date().month());
        f.setAnho(ui->dateEdit->date().year());

        Reunion r;
        r.setResumen(resu.toLocal8Bit().data());
        r.setFechaReunion(f);

        auto it = re->begin();
        for(int i = 0; i<numeroModificar; ++i){
            it++;
        }

        auto it2 = al->begin();
        for(int i = 0; i < it->numeroAl; ++i){
            it2++;
        }
        strcpy_s(r.nombre, it2->getNombre());

        re->erase(it);
        re->pushFront(r);

        this->close();
    }
}

void Dialog_reuniones::on_pushButton_clicked() //salir
{
    this->close();
}
