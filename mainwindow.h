#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "alumno.h"
#include <QMainWindow>
#include "alumno.h"
#include "list.cpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionA_adir_Alumnos_triggered();

    void on_actionModificar_Alumnos_triggered();

    void on_actionA_adir_Reuniones_triggered();

    void on_actionModificar_Reuniones_triggered();

    void on_actionEliminar_Alumnos_triggered();

    void on_actionEliminar_Reuniones_triggered();

    void on_actionGuardar_triggered();

    void on_actionCargar_triggered();

private:
    Ui::MainWindow *ui;
    List<Alumno> al;  //definición de lista de alumnos para su posterior uso.
    List<Reunion> re; //definicion de la lista reunion
};

#endif // MAINWINDOW_H
