#ifndef DIALOG_ALUMNOS_H
#define DIALOG_ALUMNOS_H
#include "list.cpp"
#include "alumno.h"
#include "dialog_reuniones.h"

#include <QDialog>

namespace Ui {
class Dialog_alumnos;
}

class Dialog_alumnos : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_alumnos(QWidget *parent = 0);
    ~Dialog_alumnos();
    void actualizar();
    List<Alumno> *al;
    int numeroModificar = -1;
    bool modificando = false;
    void modificar();

private slots:
    void on_pushButton_Guardar_clicked();

private:
    Ui::Dialog_alumnos *ui;
    Alumno a;
    Reunion r;
};

#endif // DIALOG_ALUMNOS_H
