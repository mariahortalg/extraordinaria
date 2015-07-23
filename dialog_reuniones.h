#ifndef DIALOG_REUNIONES_H
#define DIALOG_REUNIONES_H
#include "list.cpp"
#include "reunion.h"
#include "alumno.h"
#include <QDialog>

namespace Ui {
class Dialog_reuniones;
}

class Dialog_reuniones : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_reuniones(QWidget *parent = 0);
    ~Dialog_reuniones();
    void actualizar();
    int numero = 0; //Se corresponde con alumno seleccionado
    List<Alumno> *al; //La lista entera de alumnos - no puedo pasar ni el alumno ni la lista reunion direactamente ya que dice que es temporal
    List<Reunion> *re;
    int numeroModificar = -1;
    bool modificando = false;
    void modificar();

private slots:
    void on_pushButton_Guardar_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_reuniones *ui;
    //Reunion r;

};

#endif // DIALOG_REUNIONES_H
