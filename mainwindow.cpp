#include "mainwindow.h"
#include <iostream>
using namespace std;
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       adiestramiento.insertarCurso(new CCursos("Ingles","Tarde",23,2));
        adiestramiento.insertarCurso(new CCursos("Ajedrez","Tarde",25,7));
        adiestramiento.insertarCurso(new CCursos("Literario","Tarde",55,2));
        adiestramiento.insertarCurso(new CCursos("Arte","Tarde",23,7));
        adiestramiento.insertarCurso(new CCursos("Letras","Tarde",44,7));

        adiestramiento.getCursos(0)->insertarProfesor(new CProfesor("Julio","Matematicas",23,5));
        adiestramiento.getCursos(1)->insertarProfesor(new CProfesor("Julio","Matematicas",23,2));
        adiestramiento.getCursos(2)->insertarProfesor(new CProfesor("Miguel","Matematicas",23,2));
        adiestramiento.getCursos(3)->insertarProfesor(new CProfesor("Miguel","Matematicas",23,2));
        adiestramiento.getCursos(4)->insertarProfesor(new CProfesor("Miguel","Matematicas",23,2));

        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Xanie","mec","526"));
        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Feo","msadec","5x6"));
        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Enrique","sadmec","f56"));
        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Aro","msec","5s6"));
        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Lucas","mecd","56f"));
        adiestramiento.getCursos(3)->insertarEstudiante(new EstudiantePosgrado("Mariano","mecf","s56"));
        ui->setupUi(this);
        ui->horasCursoLine->setValidator(this->validatorCantidad);
        ui->mesCursoLine->setValidator(this->validatorMes);
        ui->edadProfesorLine->setValidator(this->validatorCantidad);
        ui->experienciaProfesorLine->setValidator(this->validatorCantidad);

}

MainWindow::~MainWindow()
{
/*    delete cursos;
    delete est;
    delete prof;
    */delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    cursos=new CCursos(ui->lineNombreCurso->text(),
                       ui->sesionCursoLine->text(),
                       ui->horasCursoLine->text().toInt(),
                       ui->mesCursoLine->text().toInt());
    adiestramiento.insertarCurso(cursos);

}

void MainWindow::on_pushButton_2_clicked()
{
    if(adiestramiento.searchCursos(ui->ncursoSeleccionLine->text())!=-1){
        ui->estadoSeleccionCurso->setText("Seleccionado con exito");
        cursos=adiestramiento.getCursos(adiestramiento.searchCursos(ui->ncursoSeleccionLine->text()));
    }
    else{
        ui->estadoSeleccionCurso->setText("El curso no existe");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    prof=new CProfesor(ui->nombreProfesorLine->text(),
                       ui->especialidadProfesorLine->text(),
                       ui->edadProfesorLine->text().toInt(),
                       ui->experienciaProfesorLine->text().toInt());
    cursos->insertarProfesor(prof);
    ui->label_6->setText("Agregado correctamene");
}


void MainWindow::on_radioButton_clicked()
{
    ui->lotro1->setText("Institucion");
    ui->lotro2->setText("Grado cientifico");
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->lotro1->setText("Grado");
    ui->lotro2->setText("Direccion");
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->radioPosgrado->isChecked()){
        est=new EstudiantePosgrado(ui->nombreEstudianteLine->text(),
                                   ui->otroEstudianteLine1->text(),
                                   ui->otroEstudianteLine2->text()
                                  );
        cursos->insertarEstudiante(est);}
    else if(ui->radioPosgrado->isChecked()){
            est=new EstudiantePregrado(ui->nombreEstudianteLine->text(),
                                       ui->otroEstudianteLine1->text(),
                                       ui->otroEstudianteLine2->text()
                                      );
            cursos->insertarEstudiante(est);}

ui->label_6->setText("Agregado correctamente");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->mayorMatriculaCursoLabel->setText(adiestramiento.getCursos(adiestramiento.getPositionMayorMatricula())->getNombre()+" "
                                          +adiestramiento.getCursos(adiestramiento.getPositionMayorMatricula())->getProfesor(0)->getNombre());


}


void MainWindow::on_radioPregrado_clicked()
{
    ui->lotro1->setText("Grado");
    ui->lotro2->setText("Direccion");

}


void MainWindow::on_radioPosgrado_clicked()
{
    ui->lotro1->setText("Institucion");
    ui->lotro2->setText("Grado cientifico");
}


void MainWindow::on_pushButton_6_clicked()
{
    QString a,b;
    adiestramiento.ordenarCursos();
    for(int i=0;i<adiestramiento.getContador();i++){
        a+=(adiestramiento.getCursos(i)->getNombre()+" "+b.setNum(adiestramiento.getCursos(i)->getCantidad_Horas())+"\n");
    }
    ui->cursosOrdenados->setText(a);
}


void MainWindow::on_pushButton_9_clicked()
{
    switch(adiestramiento.getTrimestreCursos()){
        case 1:
        ui->MayorTrimestre->setText("Enero-Marzo");
        break;
    case 2:
        ui->MayorTrimestre->setText("Abril-Junio");
        break;
    case 3:
        ui->MayorTrimestre->setText("Julio-Septiembre");
        break;
    case 4:
        ui->MayorTrimestre->setText("Octubre-Diciembre");
        break;
    }

}


void MainWindow::on_pushButton_8_clicked()
{
    QString a;
    if(adiestramiento.searchCursos(ui->cursoDado->text())!=-1){
        ui->cursoDadoLabel->setText(adiestramiento.getCursos(adiestramiento.searchCursos(ui->cursoDado->text()))->getNombre()+" "+
                                    adiestramiento.getCursos(adiestramiento.searchCursos(ui->cursoDado->text()))->getProfesor(0)->getNombre()+" "+
                a.setNum(adiestramiento.getCursos(adiestramiento.searchCursos(ui->cursoDado->text()))->getCantidad_Horas())+" "+
                                    a.setNum(adiestramiento.getCursos(adiestramiento.searchCursos(ui->cursoDado->text()))->getMes()));

    }
    else{
        ui->cursoDadoLabel->setText("El curso no existe");
    }}


void MainWindow::on_pushButton_7_clicked()
{QString a;
    ui->labelmayorMatricula->setText(a.setNum(adiestramiento.getCursos(adiestramiento.getPositionMayorMatricula())->getMatricula()));
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->profesorClases->setText(adiestramiento.mayorProfesor());
}


void MainWindow::on_pushButton_12_clicked()
{
    QString estudiantes="",b,x=" \n ";
    if(adiestramiento.searchCursos(ui->lineEstudiantesOrdenados->text())!=-1){
        try {
            cursos=adiestramiento.getCursos(adiestramiento.searchCursos(ui->lineEstudiantesOrdenados->text()));
            cursos->ordenarEstudiantes();
            for(int i=0;i<cursos->getMatricula();i++){
                estudiantes+=(cursos->getEstudiante(i)->getName()+"\n");
            }
            ui->labelEstudiantesOrdenados->setText(estudiantes);
        } catch (QString a) {
            ui->labelEstudiantesOrdenados->setText(a);
        }
    }
    else{
        ui->labelEstudiantesOrdenados->setText("El curso no existe");
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->cursoQMasSImparte->setText(adiestramiento.getCursos(adiestramiento.getPositionMayorMatricula())->getNombre());
}

