#ifndef CLASES_H
#define CLASES_H
#include <iostream>
#include "QString"
using namespace std;


class CProfesor{
private  :
    QString nombre, especialidad;
    int edad, years_experiencia;

       public :
    CProfesor(QString nombre, QString especialidad, int edad, int years_experiencia) {
           this->nombre = nombre;
           this->especialidad = especialidad;
           this->edad = edad;
           this->years_experiencia = years_experiencia;
       }

    int getExperiencia() {
           return years_experiencia;
       }

    void setExperiencia(int years_experiencia) {
           this->years_experiencia = years_experiencia;
       }

    int getEdad() {
           return edad;
       }

    void setEdad(int edad) {
           this->edad = edad;
       }

    QString getNombre() {
           return nombre;
       }

     void setNombre(QString nombre) {
           this->nombre = nombre;
       }

     QString getEspecialidad() {
           return especialidad;
       }

     void setEspecialidad(QString especialidad) {
           this->especialidad = especialidad;
       }
};



class CEstudiante{
private:
    QString name;
public:

    CEstudiante(QString name) {
            this->name = name;
        }

    QString getName() {
            return name;
        }

    void setName(QString name) {
            this->name = name;
        }
};




class EstudiantePregrado:public CEstudiante{

private :
    QString direccion,grado;

public :
    EstudiantePregrado(QString nombre,QString direccion, QString grado):CEstudiante(nombre) {
            this->direccion = direccion;
            this->grado = grado;
        }

     QString getGrado() {
            return grado;
        }

     void setGrado(QString grado) {
            this->grado = grado;
        }

     QString getDireccion() {
            return direccion;
        }

     void setDireccion(QString direccion) {
            this->direccion = direccion;
        }

};


class EstudiantePosgrado:public CEstudiante{

private :
    QString instituicion,grado;

public :
    EstudiantePosgrado(QString nombre,QString instituicion, QString grado):CEstudiante(nombre) {
        this->instituicion = instituicion;
        this->grado = grado;
    }

    QString getGrado() {
        return grado;
    }

    void setGrado(QString grado) {
        this->grado = grado;
    }

    QString getInstituicion() {
        return instituicion;
    }

    void setInstituicion(QString instituicion) {
        this->instituicion = instituicion;
    }
};




class CCursos{
    private:
        CEstudiante** estudiante;
        CProfesor ** profesor;
        int cantidadE=0;
        int cantidadP=0;
        int mes;
        QString nombre, tipo_de_sesion;
        int cantidad_Horas;

public:
        CCursos(QString nombre, QString tipo_de_sesion, int cantidad_horas,int mes) {
            this->mes=mes;
            this->profesor=new CProfesor*;
            this->estudiante=new CEstudiante*;
            this->nombre = nombre;
            this->tipo_de_sesion = tipo_de_sesion;
            this->cantidad_Horas = cantidad_horas;
        }

        int getCantidadEs(){
            return cantidadE;
        }

        ~CCursos(){
            for(int i=0;i<cantidadE;i++){
                delete estudiante[i];

            }
            for(int i=0;i<cantidadP;i++){
                delete profesor[i];

            }
            delete profesor;
            delete estudiante;

        }
        CEstudiante * getEstudiante(int pos){
            return this->estudiante[pos];
        }

        CProfesor* getProfesor(int pos){
            return profesor[pos];
        }

        int getMes(){
            return mes;
        }

        int getMatricula(){
            return cantidadE;
        }

        QString getTipo_de_sesion() {
            return tipo_de_sesion;
        }

        void setTipo_de_sesion(QString tipo_de_sesion) {
            this->tipo_de_sesion = tipo_de_sesion;
        }

        QString getNombre() {
            return nombre;
        }

        void setNombre(QString nombre) {
            this->nombre = nombre;
        }


        void ordenarEstudiantes(){

            for(int i=0;i<cantidadE;i++){
                   for(int j=0;j<cantidadE-1;j++){
                       if(this->estudiante[j]->getName()>estudiante[j+1]->getName()){
                           CEstudiante* aux=estudiante[j];
                           estudiante[j]=estudiante[j+1];
                           estudiante[j+1]=aux;
                       }
                   }
               }

                }


        int getCantidad_Horas() {
            return cantidad_Horas;
        }

        void insertarEstudiante(CEstudiante *estudiante){
            this->estudiante[cantidadE]=estudiante;
            this->cantidadE++;
        }

        void insertarProfesor(CProfesor *profesor){
            this->profesor[cantidadP]=profesor;
            cantidadP++;
        }

        void setCantidad_Horas(int cantidad_Horas) {
            this->cantidad_Horas = cantidad_Horas;
        }
};



class Adiestramiento{

private:
    CCursos **cursos;
    int contador=0;

public:
     Adiestramiento(){
         this->cursos=new CCursos*;

     }

     int getPositionMayorMatricula(){
         int pos=0;
         int mayor =cursos[0]->getMatricula();
         for(int i=0;i<contador;i++){
             if(mayor<cursos[i]->getMatricula()){
                 mayor=cursos[i]->getMatricula();
                 pos=i;
             }
         }
         return pos;
     }

     int getPositionMayorTiempo(){
         int pos=0;
         int mayor =cursos[0]->getCantidad_Horas();
         for(int i=0;i<contador;i++){
             if(mayor<cursos[i]->getCantidad_Horas()){
                 mayor=cursos[i]->getCantidad_Horas();
                 pos=i;
             }
         }
         return pos;
     }

     QString mayorProfesor(){
         QString prof=" j";
         int mayor=0;
         for(int i=0;i<contador;i++){
             int c=0;
             for(int j=0;j<contador;j++){
                 if((cursos[j]->getProfesor(0)->getNombre())==(cursos[i]->getProfesor(0)->getNombre())){
                     c++;
                 }
             if(c>mayor){
                 mayor=c;
                 prof=cursos[i]->getProfesor(0)->getNombre();
             }
             }
         }
         return prof;
     }

     int getTrimestreCursos(){
         QString a;
         int mes[4];
         for(int i=0;i<4;i++){
             mes[i]=0;
         }
         for(int i=0;i<contador;i++){
             if(cursos[i]->getMes()<=3){
                mes[0]++;
             }else if(cursos[i]->getMes()<=6 && cursos[i]->getMes()>3){
                 mes[1]++;
             }else if(cursos[i]->getMes()<=9 && cursos[i]->getMes()>6){
                 mes[2]++;
             }
             else{
                 mes[3]++;
             }
         }
         int pos=0;
         int mayor=mes[0];
          for(int i=0;i<4;i++){
             if(mes[i]>mayor){
                 mayor=mes[i];
                 pos=i;
             }
         }
         return pos+1;

     }

     CCursos * getCursos(int pos){
         return cursos[pos];
     }

     void ordenarCursos(){
         for(int i=0;i<contador;i++){
                for(int j=0;j<contador-1;j++){
                    if(cursos[j]->getCantidad_Horas()>cursos[j+1]->getCantidad_Horas()){
                        CCursos* aux=cursos[j];
                        cursos[j]=cursos[j+1];
                        cursos[j+1]=aux;
                    }
                }
            }
     }


     int searchCursos(QString nombre){
         int pos=-1;
         for(int i=0;i<contador;i++){
             if(cursos[i]->getNombre()==nombre){
                 pos=i;
             }
         }
         return pos;
     }



    void insertarCurso(CCursos* curso){
        cursos[contador]=curso;
        this->contador++;
    }

    int getContador(){
        return contador;
    }


    ~Adiestramiento(){
        for(int i=0;i<contador;i++){
            delete cursos[i];

        }
        delete cursos;
    }







};
















#endif // CLASES_H
