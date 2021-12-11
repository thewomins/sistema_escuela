#include <iostream>
#include "alumnos/alumnos_regulares.h"
#include "alumnos/alumnos_egresados.h"
#include "alumnos/alumnos_titulados.h"
#include "ramos/ramos_regular_egresados.h"
#include "listas/lista_alum_regular.h"
#include "listas/lista_alum_egresado.h"
#include "listas/lista_alum_titulados.h"
#include "listas/lista_ramos_regular_egresados.h"
#include "listas/lista_ramos_titular.h"
#include "ramos/ramos_titular.h"
#include <cstdlib>
//#include <fstream>
#include <string>
using namespace std;

void menu_principal();
void menu1();
void menu2();
void menu3();
//void menu_inscripcion_ramos_reg(Listas *lista, int rut);
int numero_matricula=0;
void imprimir_datos_alumnos(alumnos_regulares alumno1, alumnos_regulares alumno2, alumnos_regulares alumno3);

int main(int argc, char** argv) {

    Lista_alumno_regular *lista_alumnos_regulares = Lista_alumno_regular::getintance();
    Lista_ramos_regular *lista_ramos_regular = new Lista_ramos_regular();
    Lista_ramos_titular *lista_ramos_titular = new Lista_ramos_titular();
    Lista_alumno_egresador *lista_alumnos_egresados = Lista_alumno_egresador::getintance();
    Lista_alumno_titulado *lista_alumnos_titulados = Lista_alumno_titulado::getintance();

    alumnos_regulares alumno1("pepe",15,0);
    alumnos_regulares alumno2("mario",16,1);
    alumnos_regulares alumno3("roerto",14,2);
    alumnos_regulares alumno4("laerto pepre",14,3);

    alumnos_egresados alumnoe1("pepo",1958,6,"pf",2010);
    alumnos_egresados alumnoe2("pepog",53,7,"pf",2019);
    alumnos_egresados alumnoe3("pepob",46,8,"pf",2020);
    alumnos_egresados alumnoe4("pepo",1958,6,"pf",2010);

    alumnos_titulados alumnot1("popo",94,10,"pof",1998,"pf",2000);
    alumnos_titulados alumnot2("piipi",56,11,"pof",2004,"pf",2008);
    alumnos_titulados alumnot3("paparaipiciopi",1256,12,"pof",2006,"pf",2010);
    alumnos_titulados alumnot4("popo",94,10,"pof",1998,"pf",2000);

    
    //imprimir_datos_alumnos(alumno1, alumno2, alumno3);
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    
    lista_alumnos_regulares->ingresar_alumno_regular(alumno2);
    //lista_alumnos_regulares->ingresar_alumno_regular(&alumno4);
    lista_alumnos_regulares->ingresar_alumno_regular(alumno3);
    lista_alumnos_regulares->imprimir_lista_completa();
    cout<<lista_alumnos_regulares->largo_lista()<<endl;

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    
    lista_alumnos_egresados->ingresar_alumno_egresado(alumnoe2);
    lista_alumnos_egresados->ingresar_alumno_egresado(alumnoe3);
    //lista_alumnos_egresados->ingresar_alumno_egresado(&alumnoe4);
    lista_alumnos_egresados->imprimir_lista_completa();
    cout<<lista_alumnos_egresados->largo_lista()<<endl;

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    lista_alumnos_titulados->ingresar_alumno_titulado(alumnot1);
    lista_alumnos_titulados->ingresar_alumno_titulado(alumnot2);
    lista_alumnos_titulados->ingresar_alumno_titulado(alumnot3);
    //lista_alumnos_titulados->ingresar_alumno_titulado(&alumnot4);
    lista_alumnos_titulados->imprimir_lista_completa();
    cout<<lista_alumnos_titulados->largo_lista()<<endl;

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    ramos_regular_egresados ramo1("programacion", "ici", 1);
    ramos_regular_egresados ramo2("nombre ramo1", "ico", 2);
    ramos_regular_egresados ramo3("nombre ramo2", "pici", 3);
    ramos_regular_egresados ramo4("nombre ramo", "ici", 1);

    ramos_titular ramot1("titulado1","ici",5,"informatica","pf","nose");
    ramos_titular ramot2("titulado2","ico",5,"iconomer","ranger","nosejose");
    ramos_titular ramot3("titulado3","med",5,"medicina","u","nose12");
    ramos_titular ramot4("titulado1","ici",5,"informatica","pf","nose");

    lista_ramos_regular->ingresar_ramo_alumno_regular(&ramo1);
    lista_ramos_regular->ingresar_ramo_alumno_regular(&ramo1);
    lista_ramos_regular->ingresar_ramo_alumno_regular(&ramo1);
    lista_ramos_regular->ingresar_ramo_alumno_regular(&ramo1);

    lista_ramos_titular->ingresar_ramo_titular(&ramot1);
    lista_ramos_titular->ingresar_ramo_titular(&ramot2);
    lista_ramos_titular->ingresar_ramo_titular(&ramot3);
    lista_ramos_titular->ingresar_ramo_titular(&ramot4);

    ramos_regular_egresados *ramo5;
    ramos_titular *ramot5;

    ramo5 = lista_ramos_regular->buscar_ramo("nombre ramo");
    lista_ramos_regular->imprimir_datos_ramos();

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    ramot5 = lista_ramos_titular->buscar_ramo("titulado3");
    lista_ramos_titular->imprimir_datos_ramos();

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    alumno1.lista_ramos->ingresar_ramo_alumno_regular(&ramo1);

    lista_alumnos_regulares->ingresar_alumno_regular(alumno1);
    lista_alumnos_regulares->buscar_alumno_reg(15, 0, lista_alumnos_regulares->largo_lista()-1)->lista_ramos->imprimir_datos_ramos();
    
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    alumnoe1.lista_ramos->ingresar_ramo_alumno_regular(&ramo2);

    lista_alumnos_egresados->ingresar_alumno_egresado(alumnoe1);
    lista_alumnos_egresados->buscar_alumno_egre(1958,0,lista_alumnos_egresados->largo_lista()-1)->lista_ramos->imprimir_datos_ramos();

    cout<<"------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    alumnot1.lista_ramos_tit->ingresar_ramo_titular(&ramot1);

    lista_alumnos_titulados->ingresar_alumno_titulado(alumnot1);
    lista_alumnos_titulados->buscar_alumno_tit(94,0,lista_alumnos_titulados->largo_lista()-1)->lista_ramos_tit->imprimir_datos_ramos();

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
                        lista_alumnos_regulares->ingresar_alumno_regular(alu);                      
                    break;
                }    
                break;                    
            case 2:// Buscar alumnos
                menu3();
                cin>>opcion3;
                switch(opcion3){
                    case 1 :// Buscar alumnos regulares
                        if(lista_alumnos_regulares==NULL){
                            cout<<"Ingrese estudiantes"<<endl;
                        }
                        else{
                            cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                            cin>>rut1;
                            //menu_inscripcion_ramos_reg(lista_alumnos_regulares, rut1);
                        }
                        break;
                    case 2:// imprimir alumnos
                        if(lista_alumnos_regulares==NULL){
                            cout<<"Ingrese estudiantes"<<endl;
                        }
                        else{
                            lista_alumnos_regulares->imprimir_lista_completa();
                        }
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
                        //lista->ingresar_ramo_alumno_regular(ramo);
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

void imprimir_datos_alumnos(alumnos_regulares alumno1, alumnos_regulares alumno2, alumnos_regulares alumno3){
    cout<<"alumno 1: "<<endl;
    cout<<"nombre: "<<alumno1.getnombre()<<endl;
    cout<<"rut: "<<alumno1.getrut()<<endl;
    cout<<"matricula: "<<alumno1.getnumero_matricula()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"alumno 2: "<<endl;
    cout<<"nombre: "<<alumno2.getnombre()<<endl;
    cout<<"rut: "<<alumno2.getrut()<<endl;
    cout<<"matricula: "<<alumno2.getnumero_matricula()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"alumno 3: "<<endl;
    cout<<"nombre: "<<alumno3.getnombre()<<endl;
    cout<<"rut: "<<alumno3.getrut()<<endl;
    cout<<"matricula: "<<alumno3.getnumero_matricula()<<endl;
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
/*
void menu_inscripcion_ramos_reg(Lista_alumno_regular *lista, int rut, Lista_ramos_regular *ramos){
    int opcion,posicion,pos,nota;
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
}*/