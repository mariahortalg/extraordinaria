#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_alumnos.h"
#include "dialog_reuniones.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Llamamos creando un obejto de la clase dialog... a la ventana de alumnos
void MainWindow::on_actionA_adir_Alumnos_triggered()  //añadir alumno
{
    Dialog_alumnos *d= new Dialog_alumnos();
    d->al = &al;
    d->setModal(true);
    d->exec();
    ui->listWidget_Alumnos->clear();
    auto it = al.begin();
    //recorremos la lista alunnos pasada por referencia, y asignamos los valores de los campos introducidos previamente en la clase
    //dialog_alumno, añadiendolos así en el list widget correspondiente que los mostrará.
    for (std::size_t i = 0; i < al.size(); ++i){

        ui->listWidget_Alumnos->addItem(QString("Nombre %1, Apellidos %2, Email %3, Telefono %4")
                                        .arg(it->getNombre())
                                        .arg(it->getApellidos())
                                        .arg(it->getEmail())
                                        .arg(it->getTelefono()));
        it++;
    }
}

void MainWindow::on_actionModificar_Alumnos_triggered() //modificar alumno
{
    if(!ui->listWidget_Alumnos->selectedItems().isEmpty()){
        Dialog_alumnos d; //variable d de tipo dailog_alumnos, para acceso al contenido de su clase.
        d.setModal(true);
        d.al = &al;
        d.numeroModificar = ui->listWidget_Alumnos->currentRow(); //selecionamos el elemento
        d.modificar(); //modificamos
        d.exec();
        ui->listWidget_Alumnos->clear(); //limpiamos y actualizamos
        auto it = al.begin();
        for (std::size_t i = 0; i < al.size(); ++i){

            ui->listWidget_Alumnos->addItem(QString("Nombre %1, Apellidos %2, Email %3, Telefono %4")
                                            .arg(it->getNombre())
                                            .arg(it->getApellidos())
                                            .arg(it->getEmail())
                                            .arg(it->getTelefono()));
            it++;
        }
    }
}

void MainWindow::on_actionEliminar_Alumnos_triggered() //eliminar alumno
{
    if(!ui->listWidget_Alumnos->selectedItems().isEmpty()){ //mientras alla un alumno selecionado
        auto it = al.begin(); //iteradores
        auto it2 = re.begin();
        int pos = 0;
        for(int i = 0; i < ui->listWidget_Alumnos->currentRow(); i++){
            it++;
            pos++;
        }
        while(it2 != re.end()){
            qDebug("%d", it->id);
            qDebug("%d", it2->numeroAl);
            if(it->id == it2->numeroAl){
                re.erase(it2);
                it2 = re.begin();
            }
            else
                it2++;
        }
        al.erase(it);

        ui->listWidget_Alumnos->clear(); //actualizamos y volvemos a escribir los campos correspondientes
        ui->listWidget_Reuniones->clear();
        it = al.begin();
        for (std::size_t i = 0; i < al.size(); ++i){

            ui->listWidget_Alumnos->addItem(QString("Nombre %1, Apellidos %2, Email %3, Telefono %4")
                                            .arg(it->getNombre())
                                            .arg(it->getApellidos())
                                            .arg(it->getEmail())
                                            .arg(it->getTelefono()));
            it++;
        }

        it2 = re.begin();
        for (std::size_t i = 0; i < re.size(); ++i){
            ui->listWidget_Reuniones->addItem(QString("Nombre %1, Fecha %2-%3-%4, Resumen %5")
                                            .arg(it2->nombre)
                                            .arg(it2->getFechaReunion().getDia())
                                            .arg(it2->getFechaReunion().getMes())
                                            .arg(it2->getFechaReunion().getAnho())
                                            .arg(it2->getResumen()));
            it2++;
        }

    }
}

void MainWindow::on_actionA_adir_Reuniones_triggered() //añadir reunion
{
    if(!ui->listWidget_Alumnos->selectedItems().isEmpty()){ //Si se ha seleccionado un alumno
        Dialog_reuniones d;
        d.setModal(true);
        d.al = &al;
        d.re = &re;
        d.numero = ui->listWidget_Alumnos->currentRow();
        //d.actualizar();
        d.exec();
    }
    ui->listWidget_Reuniones->clear();
    auto it = re.begin();
    for (std::size_t i = 0; i < re.size(); ++i){
        ui->listWidget_Reuniones->addItem(QString("Nombre %1, Fecha %2-%3-%4, Resumen %5")
                                        .arg(it->nombre)
                                        .arg(it->getFechaReunion().getDia())
                                        .arg(it->getFechaReunion().getMes())
                                        .arg(it->getFechaReunion().getAnho())
                                        .arg(it->getResumen()));
        it++;
    }
}

void MainWindow::on_actionModificar_Reuniones_triggered() //pulsando el boton modificar
{
    if(!ui->listWidget_Reuniones->selectedItems().isEmpty()){ //si el elemento esta seleciionado:
        Dialog_reuniones d; //creamos la variable d de tipo dialog_reuniones para poder acceder a su contenido.
        d.setModal(true);
        d.al = &al;
        d.re = &re;
        d.numeroModificar = ui->listWidget_Reuniones->currentRow(); //asignamos la posicion actual
        d.modificar(); //llamamos a su funcion modificar
        d.exec();
        ui->listWidget_Reuniones->clear(); //limpiamos y actualizamos.
        auto it = re.begin();
        for (std::size_t i = 0; i < re.size(); ++i){
            ui->listWidget_Reuniones->addItem(QString("Nombre %1, Fecha %2-%3-%4, Resumen %5")
                                            .arg(it->nombre)
                                            .arg(it->getFechaReunion().getDia())
                                            .arg(it->getFechaReunion().getMes())
                                            .arg(it->getFechaReunion().getAnho())
                                            .arg(it->getResumen()));
            it++;
        }
    }
}

void MainWindow::on_actionEliminar_Reuniones_triggered()  //Boton eliminar
{
    if(!ui->listWidget_Reuniones->selectedItems().isEmpty()){  //si el elemnto esta selecionado:
        auto it = re.begin();
        for(int i = 0; i < ui->listWidget_Reuniones->currentRow(); i++){  //selecionamos el elemento usando el current row, posicion actual
            it++;
        }
        re.erase(it); //eliminamos dicho elemento con la funcion de la lista erase.

        ui->listWidget_Reuniones->clear();  //limpiamos y actualizamos
        it = re.begin();
        for (std::size_t i = 0; i < re.size(); ++i){
            ui->listWidget_Reuniones->addItem(QString("Nombre %1, Fecha %2-%3-%4, Resumen %5")
                                            .arg(it->nombre)
                                            .arg(it->getFechaReunion().getDia())
                                            .arg(it->getFechaReunion().getMes())
                                            .arg(it->getFechaReunion().getAnho())
                                            .arg(it->getResumen()));
            it++;
        }

    }
}

//con esta funcion conseguimos guardar de manera independiente tanto reuniones como alumnos, es decir dos archivos txt.
//adememas una de las fomas mas eficientes de cara al usuario es elegir el lugar donde se va a guardar, por lo que el programa nos
//permitira eligir primero el destino del txt de alumnos y posteriormete el de reuniones.
void MainWindow::on_actionGuardar_triggered() //pulsando el boton guardar
{
    QString fileName = QFileDialog::getSaveFileName(this, //permitimos la determinacion de la ruta
                tr("Guardar "), "",
                tr("Alumnos (*.txt);;All Files (*)")); //asignacion del tipo de archivo
    if (fileName.isEmpty())
        return;

    std::string fileN = fileName.toStdString();

  al.writeToFile(fileN);  //guardardando en la lista de alumnos.

  fileName = QFileDialog::getSaveFileName(this,
              tr("Guardar "), "",
              tr("Reuniones (*.txt);;All Files (*)"));
  if (fileName.isEmpty())
      return;

  fileN = fileName.toStdString();
  re.writeToFile(fileN); //guardardando en la lista de reuniones.
}


//Ocurre lo mismo con el boton cargar, el usuario eligira la nuevamente la ruta de acceso donde se ubican los archivos txt previamente
//guardados. Priemero cargara el contenido de alumnos y acto seguido el de reuniones.
void MainWindow::on_actionCargar_triggered() //pulsando el boton cargar
{
    QString fileName = QFileDialog::getOpenFileName(this,
                tr("Cargar Alumnos"), "",
                tr("Alumnos (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    std::string fileN = fileName.toStdString();

    al.readFromFile(fileN);

    fileName = QFileDialog::getOpenFileName(this,
                tr("Cargar Reuniones"), "",
                tr("Reuniones (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    fileN = fileName.toStdString();

    re.readFromFile(fileN);

    ui->listWidget_Alumnos->clear();  //limpiamos lo que hay en los widgets y asignamos los valores leidos en ambos widgets
    ui->listWidget_Reuniones->clear();
    auto it = al.begin();
    for (std::size_t i = 0; i < al.size(); ++i){

        ui->listWidget_Alumnos->addItem(QString("Nombre %1, Apellidos %2, Email %3, Telefono %4")  //asignamos los items a los widgets
                                        .arg(it->getNombre())
                                        .arg(it->getApellidos())
                                        .arg(it->getEmail())
                                        .arg(it->getTelefono()));
        it++;
    }

    auto it2 = re.begin();
    for (std::size_t i = 0; i < re.size(); ++i){
        ui->listWidget_Reuniones->addItem(QString("Nombre %1, Fecha %2-%3-%4, Resumen %5")
                                        .arg(it2->nombre)
                                        .arg(it2->getFechaReunion().getDia())
                                        .arg(it2->getFechaReunion().getMes())
                                        .arg(it2->getFechaReunion().getAnho())
                                        .arg(it2->getResumen()));
        it2++;
    }
}
