#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clases.h"
#include <QMainWindow>
#include <QValidator>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_radioPregrado_clicked();

    void on_radioPosgrado_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    QValidator *validatorMes=new QIntValidator(1,12,this);
    QValidator *validatorCantidad=new QIntValidator(1,1000,this);

    CProfesor* prof;
    CEstudiante* est;
    CCursos *cursos;
    Adiestramiento adiestramiento;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
