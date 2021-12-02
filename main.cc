#include <iostream>
#include "alumnos_regulares/alumnos_regulares.h"
#include "alumnos_egresados/alumnos_egresados.h"
#include "alumnos_titulados/alumnos_titulados.h"
#include "ramos_titular/ramos_titular.h"
#include "ramos_regular_egresados/ramos_regular_egresados.h"
#include "notas/notas.h"
#include "Listas.h"
#include "tesis/tesis.h"
#include <cstdlib>
//#include <fstream>
#include <string>
using namespace std;

void menu_principal();
void menu1();
void menu2();
void menu3();
void menu_inscripcion_ramos_reg(Listas *lista, int rut);
int numero_matricula=0;

int main(int argc, char** argv) {
    
    //nodos (listas)
    Listas *lista=Listas::getintance();

    //variables buffer
    string nombre1,empresa_practica1,empresa_actual,nombre_carrera,nombre_area_ramo,nombre_empresa_auspiciadora,unidad_dicta_ramo;
    int rut1,fecha_egreso1,promedio1,ano_titulacion,opcion,opcion1,opcion2,opcion3,salir,numero_semestre;
    
    //lectura(lista lista_alum_reg,lista lista_ramos_reg_egr);
    
    //menu
    do {
        menu_principal();
        cin>>opcion;
        switch(opcion){
            case 1 ://Ingresar alumnos
                menu1();
                cin>>opcion1;
                switch(opcion1){
                    case 1://Ingresar alumnos regulares
                        cout<<"Ingrese nombre"<<endl;
                        cin>>nombre1;                    
                        cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                        cin>>rut1;
                        alumnos_regulares alu(nombre1,rut1,numero_matricula);
                        numero_matricula++;
                        lista->ingresar_alumno_regular(alu);                      
                    break;
                }    
                break;                    
            case 2:// Buscar alumnos
                menu3();
                cin>>opcion3;
                switch(opcion3){
                    case 1 :// Buscar alumnos regulares
                        if(lista==NULL){
                            cout<<"Ingrese estudiantes"<<endl;
                        }
                        else{
                            cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                            cin>>rut1;
                            menu_inscripcion_ramos_reg(lista, rut1);
                        }
                    break;
                }                                                       
                break;
            case 3: //ingresar ramos
                menu2();
                cin>>opcion2;
                switch(opcion2){
                    case 1 ://ingresar ramos regulares y egresados
                        cout<<"Ingrese nombre de ramo"<<endl;
                        cin>>nombre1;                    
                        cout<<"Ingrese nombre de carrera"<<endl;
                        cin>>nombre_carrera;
                        cout<<"Ingrese numero de semestre"<<endl;
                        cin>>numero_semestre;
                        ramos_regular_egresados ramo(nombre1,nombre_carrera,numero_semestre);
                        lista->ingresar_ramo_alumno_regular(ramo);
                        break;
                }
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"opcion incorrecta"<<endl;
                break;
        }
    }while(opcion != 4);

    return 0;
}


void menu_principal(){
    cout<<"------------------------------------"<<endl;
    cout<<" 1) Ingresar alumnos"<<endl;
    cout<<" 2) Buscar alumnos"<<endl;
    cout<<" 3) Ingresar ramos"<<endl;
    cout<<" 4) Salir "<<endl;
    cout<<"------------------------------------"<<endl;
}

void menu1(){
    cout<<"------------------------------------"<<endl;
    cout<<" 1) Ingresar alumno regular"<<endl;
    cout<<" 2) Ingresar alumno egresado"<<endl;
    cout<<" 3) Ingresar alumno titulado"<<endl;
    cout<<"------------------------------------"<<endl;
}

void menu2(){
    cout<<"------------------------------------"<<endl;
    cout<<"1) Ingresar ramos alumnos regulares y egresados"<<endl;
    cout<<"2) Ingresar ramos alumnos titulados"<<endl;
    cout<<"------------------------------------"<<endl;
}

void menu3(){
    cout<<"------------------------------------"<<endl;
    cout<<"1) Buscar alumno regular"<<endl;
    cout<<"2) Buscar alumno egresado"<<endl;
    cout<<"3) Buscar alumno titulado"<<endl;
    cout<<"------------------------------------"<<endl;
}

void menu_inscripcion_ramos_reg(Listas *lista, int rut){
    int opcion,posicion,pos,nota;
    ramos_regular_egresados ramo;
    int pos1 = lista->buscar_alumno_reg(rut,0,lista->largo_reg());
    lista->iterator_siguiente(pos1);
    lista->imprimir_alu();
    cout<<"*************************************************"<<endl;
    cout<<" 1) Inscribir ramos"<<endl;//inscripcion de ramos a alumno
    cout<<" 2) Ver ramos inscritos y notas"<<endl;//notas dentro de ramos
    cout<<" 3) Ingresar notas"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1://inscribir ramo ya ingresado
            for(int i=1;i<=lista->largo_ramos_reg();i++){
                ramo=lista->obtener_ramo(i);
                cout<<i<<")"<<ramo.getnombre_ramo()<<endl;
            }
            cout<<"Ingrese numero del ramo a inscribir"<<endl;
            cin>>posicion;
            ramo=lista->obtener_ramo(posicion);
            lista->lista_alum_reg->alu.ingresar_ramos(ramo);
            lista->iterator_anterior(pos1);
            break;
        case 2:           
            cout<<"*************************************************"<<endl;
            lista->lista_alum_reg->alu.get_ramos();
            cout<<"*************************************************"<<endl;
            lista->iterator_anterior(pos1);
            break;
        case 3: 
            lista->lista_alum_reg->alu.muestra_ramos();
            cout<<"Ingrese numero del ramo a ingresar notas"<<endl;
            cin>>pos;
            cout<<"Ingrese nota a ingresar"<<endl;
            cin>>nota;
            lista->lista_alum_reg->alu.ingresar_nota(nota,pos-1);
            lista->iterator_anterior(pos1);
            break;
        default:
            break;
    }
}