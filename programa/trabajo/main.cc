#include <iostream>//para imprimir
#include "alumnos_regulares.h"
#include "alumnos_egresados.h"
#include "alumnos_titulados.h"
#include "ramos_titular.h"
#include "ramos_regular_egresados.h"
#include "notas.h"
#include "tesis.h"
#include <fstream>
#include <string>
using namespace std;

struct nodo{
        alumnos_regulares alu;
        nodo *sig;
};

struct nodo1{
        alumnos_egresados alu;
        nodo1 *sig;
};

struct nodo2{
        alumnos_titulados alu;
        nodo2 *sig;
};

struct nodo_ramos_reg_egr{
        ramos_regular_egresados ramo;
        nodo_ramos_reg_egr *sig;
};

struct nodo_ramos_tit{
        ramos_titular ramo;
        nodo_ramos_tit *sig;
};

void ingresar_alumno_reg(nodo *&lista,alumnos_regulares alu_new);
void ingresar_alumno_egre(nodo1 *&lista,alumnos_egresados alu_new);
void ingresar_alumno_tit(nodo2 *&lista,alumnos_titulados alu_new);
void ingresar_ramos_reg_egr(nodo_ramos_reg_egr *&lista,ramos_regular_egresados ramo_new);
void ingresar_ramos_tit(nodo_ramos_tit *&lista,ramos_titular ramo_new);
int largo_reg(nodo *lista);
int largo_egre(nodo1 *lista);
int largo_tit(nodo2 *lista);
int largo_ramos_reg_egr(nodo_ramos_reg_egr *lista);
int largo_ramos_tit(nodo_ramos_tit *lista);
nodo *buscar_alumno_reg(nodo *lista,int rut, int inicio, int fin);
nodo1 *buscar_alumno_egre(nodo1 *lista,int rut, int inicio, int fin);
nodo2 *buscar_alumno_tit(nodo2 *lista,int rut, int inicio, int fin);
void menu_principal();
void menu1();
void menu2();
void menu3();
void menu_inscripcion_ramos_reg(nodo *alumno,nodo_ramos_reg_egr *lista_ramos);
void menu_inscripcion_ramos_egre(nodo1 *alumno,nodo_ramos_reg_egr *lista_ramos);
void menu_inscripcion_ramos_tit(nodo2 *alumno,nodo_ramos_tit *lista_ramos);
void lectura(nodo *&lista_alum,nodo_ramos_reg_egr *&lista_ramos);
int numero_matricula=0;

int main(int argc, char** argv) {
    //objetos
    alumnos_regulares new_alum_reg;
    alumnos_egresados new_alum_egr;
    alumnos_titulados new_alum_tit;
    ramos_regular_egresados new_ramo_reg_egre;
    ramos_titular new_ramo_tit;
    
    //nodos (listas)
    nodo *lista_alum_reg= NULL;
    nodo1 *lista_alum_egre= NULL;
    nodo2 *lista_alum_tit= NULL;
    nodo_ramos_reg_egr *lista_ramos_reg_egr= NULL;
    nodo_ramos_tit *lista_ramos_tit= NULL;
    
    //variables buffer
    string nombre1,empresa_practica1,empresa_actual,nombre_carrera,nombre_area_ramo,nombre_empresa_auspiciadora,unidad_dicta_ramo;
    int rut1,fecha_egreso1,promedio1,ano_titulacion,opcion,opcion1,opcion2,opcion3,salir,numero_semestre;
    
    //nodos (listas con 1 elemnto)
    nodo *alumno_find_reg;
    nodo1 *alumno_find_egre;
    nodo2 *alumno_find_tit;
    
    lectura(lista_alum_reg,lista_ramos_reg_egr);
    
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
                        new_alum_reg.setnombre(nombre1);
                        new_alum_reg.setrut(rut1);
                        numero_matricula++;
                        new_alum_reg.setnumero_matricula(numero_matricula);
                        ingresar_alumno_reg(lista_alum_reg,new_alum_reg);                      
                        break;
                    case 2://Ingresar alumnos egresados
                        cout<<"Ingrese nombre"<<endl;
                        cin>>nombre1;                    
                        cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                        cin>>rut1;
                        cout<<"Ingrese fecha egreso ej(05101996)"<<endl;
                        cin>>fecha_egreso1;
                        cout<<"Ingrese empresa practica"<<endl;
                        cin>>empresa_practica1;
                        new_alum_egr.setnombre(nombre1);
                        new_alum_egr.setrut(rut1);
                        new_alum_egr.setfecha_egreso(fecha_egreso1);
                        new_alum_egr.setempresa_practica(empresa_practica1);
                        numero_matricula++;
                        new_alum_egr.setnumero_matricula(numero_matricula);
                        ingresar_alumno_egre(lista_alum_egre,new_alum_egr);
                        break;
                    case 3://Ingresar alumnos titulados
                        cout<<"Ingrese nombre"<<endl;
                        cin>>nombre1;                    
                        cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                        cin>>rut1;
                        cout<<"Ingrese fecha egreso ej(05101996)"<<endl;
                        cin>>fecha_egreso1;
                        cout<<"Ingrese empresa practica"<<endl;
                        cin>>empresa_practica1;
                        cout<<"Ingrese empresa actual"<<endl;
                        cin>>empresa_actual;
                        cout<<"Ingrese ano titulacion ej(05101996)"<<endl;
                        cin>>ano_titulacion;                    
                        new_alum_tit.setnombre(nombre1);
                        new_alum_tit.setrut(rut1);
                        new_alum_tit.setfecha_egreso(fecha_egreso1);
                        new_alum_tit.setempresa_practica(empresa_practica1);
                        new_alum_tit.setempresa_actual(empresa_actual);
                        new_alum_tit.setano_titulacion(ano_titulacion);
                        numero_matricula++;
                        new_alum_tit.setnumero_matricula(numero_matricula);
                        ingresar_alumno_tit(lista_alum_tit,new_alum_tit);                       
                        break;
                    default:
                        break;
                }
                break;
            case 2:// Buscar alumnos
                menu3();
                cin>>opcion3;
                switch(opcion3){
                    case 1 :// Buscar alumnos regulares
                        if(lista_alum_reg==NULL){
                            cout<<"Ingrese estudiantes"<<endl;
                        }
                        else{
                            cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                            cin>>rut1;
                            alumno_find_reg=buscar_alumno_reg(lista_alum_reg,rut1,0,largo_reg(lista_alum_reg));
                            while(alumno_find_reg==NULL){
                                cout<<"No encontrado digite nuevamente"<<endl;
                                cin>>rut1;
                                alumno_find_reg=buscar_alumno_reg(lista_alum_reg,rut1,0,largo_reg(lista_alum_reg));
                            }
                            cout<<"-------------------------------------------------"<<endl;
                            cout<<"*************************************************"<<endl;
                            cout<<"Nombre: "<<alumno_find_reg->alu.getnombre()<<endl; 
                            cout<<"Rut: "<<alumno_find_reg->alu.getrut()<<endl; 
                            cout<<"N matricula: "<<alumno_find_reg->alu.getnumero_matricula()<<endl;
                            alumno_find_reg->alu.get_prom();
                            menu_inscripcion_ramos_reg(alumno_find_reg,lista_ramos_reg_egr);
                        }
                        break;
                    case 2:// Buscar alumnos egresados
                        if(lista_alum_egre==NULL){
                            cout<<"Ingrese estudiantes egresados"<<endl;
                        }
                        else{
                            cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                            cin>>rut1;
                            alumno_find_egre=buscar_alumno_egre(lista_alum_egre,rut1,0,largo_egre(lista_alum_egre));
                            while(alumno_find_egre==NULL){
                                cout<<"No encontrado digite nuevamente"<<endl;
                                cin>>rut1;
                                alumno_find_egre=buscar_alumno_egre(lista_alum_egre,rut1,0,largo_egre(lista_alum_egre));
                            }
                            cout<<"-------------------------------------------------"<<endl;
                            cout<<"*************************************************"<<endl;
                            cout<<"Nombre: "<<alumno_find_egre->alu.getnombre()<<endl; 
                            cout<<"Rut: "<<alumno_find_egre->alu.getrut()<<endl; 
                            cout<<"N matricula: "<<alumno_find_egre->alu.getnumero_matricula()<<endl;
                            alumno_find_egre->alu.get_prom();  
                            cout<<"Fecha egreso: "<<alumno_find_egre->alu.getfecha_egreso()<<endl; 
                            cout<<"Empresa de practica: "<<alumno_find_egre->alu.getempresa_practica()<<endl;                                        
                            menu_inscripcion_ramos_egre(alumno_find_egre,lista_ramos_reg_egr);
                        }
                        break;
                    case 3:// Buscar alumnos titulados
                        if(lista_alum_tit==NULL){
                            cout<<"Ingrese estudiantes titulados"<<endl;
                        }
                        else{
                            cout<<"Ingrese rut del alumno sin puntos ni guion verificador ej(12345678)"<<endl;
                            cin>>rut1;
                            alumno_find_tit=buscar_alumno_tit(lista_alum_tit,rut1,0,largo_tit(lista_alum_tit));
                            while(alumno_find_tit==NULL){
                                cout<<"No encontrado digite nuevamente"<<endl;
                                cin>>rut1;
                                alumno_find_tit=buscar_alumno_tit(lista_alum_tit,rut1,0,largo_tit(lista_alum_tit));
                            }
                            cout<<"-------------------------------------------------"<<endl;
                            cout<<"*************************************************"<<endl;
                            cout<<"Nombre: "<<alumno_find_tit->alu.getnombre()<<endl; 
                            cout<<"Rut: "<<alumno_find_tit->alu.getrut()<<endl; 
                            cout<<"N matricula: "<<alumno_find_tit->alu.getnumero_matricula()<<endl;
                            alumno_find_tit->alu.get_prom_tit();
                            cout<<"Fecha egreso: "<<alumno_find_tit->alu.getfecha_egreso()<<endl; 
                            cout<<"Empresa de practica: "<<alumno_find_tit->alu.getempresa_practica()<<endl; 
                            cout<<"Año titulacion : "<<alumno_find_tit->alu.getano_titulacion()<<endl;  
                            cout<<"Empresa actual : "<<alumno_find_tit->alu.getempresa_actual()<<endl;
                            menu_inscripcion_ramos_tit(alumno_find_tit,lista_ramos_tit);
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
                        new_ramo_reg_egre.setnombre_ramo(nombre1);
                        new_ramo_reg_egre.setnombre_carrera(nombre_carrera);
                        new_ramo_reg_egre.setnumero_semestre(numero_semestre);
                        ingresar_ramos_reg_egr(lista_ramos_reg_egr,new_ramo_reg_egre);
                        break;
                    case 2://ingresar ramos titulares
                        cout<<"Ingrese nombre de ramo"<<endl;
                        cin>>nombre1;                    
                        cout<<"Ingrese nombre de carrera"<<endl;
                        cin>>nombre_carrera;
                        cout<<"Ingrese numero de semestre"<<endl;
                        cin>>numero_semestre;
                        cout<<"Ingrese nombre de area del ramo"<<endl;
                        cin>>nombre_area_ramo;                    
                        cout<<"Ingrese nombre de la empresa auspiciadora"<<endl;
                        cin>>nombre_empresa_auspiciadora;
                        cout<<"Ingrese la unidad que dicta el ramo"<<endl;
                        cin>>unidad_dicta_ramo;
                        new_ramo_tit.setnombre_ramo(nombre1);
                        new_ramo_tit.setnombre_carrera(nombre_carrera);
                        new_ramo_tit.setnumero_semestre(numero_semestre);
                        new_ramo_tit.setnombre_area_ramo(nombre_area_ramo);
                        new_ramo_tit.setnombre_empresa_auspiciadora(nombre_empresa_auspiciadora);
                        new_ramo_tit.setunidad_dicta_ramo(unidad_dicta_ramo);
                        ingresar_ramos_tit(lista_ramos_tit,new_ramo_tit);
                        break;
                    default:
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
    }
    while(opcion != 4);
    return 0;
}

void ingresar_alumno_reg(nodo *&lista,alumnos_regulares alu_new){
    nodo *p = new nodo();
    p->alu=alu_new;
    nodo *aux1=lista; 
    nodo *aux2; 
    while((aux1!=NULL)&&(aux1->alu.getrut()<p->alu.getrut())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista == aux1){
        lista = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

void ingresar_alumno_egre(nodo1 *&lista,alumnos_egresados alu_new){
    nodo1 *p = new nodo1();
    p->alu=alu_new;
    nodo1 *aux1=lista; 
    nodo1 *aux2; 
    while((aux1!=NULL)&&(aux1->alu.getrut()<p->alu.getrut())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista == aux1){
        lista = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

void ingresar_alumno_tit(nodo2 *&lista,alumnos_titulados alu_new){
    nodo2 *p = new nodo2();
    p->alu=alu_new;
    nodo2 *aux1=lista; 
    nodo2 *aux2; 
    while((aux1!=NULL)&&(aux1->alu.getrut()<p->alu.getrut())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista == aux1){
        lista = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

int largo_reg(nodo *lista){
    nodo *aux=lista;
    int contador=0;
    if(lista==NULL){
        return 0;
    }
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
}
int largo_egre(nodo1 *lista){
    nodo1 *aux=lista;
    int contador=0;
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
}
int largo_tit(nodo2 *lista){
    nodo2 *aux=lista;
    int contador=0;
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
}

nodo *buscar_alumno_reg(nodo *lista,int rut, int inicio, int fin){
    int medio=(inicio+fin)/2;
    nodo *aux=lista;
    if(inicio>fin){
        return NULL;//no encontrado
    }
    for(int i=0; i<medio;i++){
        aux=aux->sig;
    }
    if(aux->alu.getrut()<rut){
        buscar_alumno_reg(lista,rut,medio+1,fin);
    }
    else if(aux->alu.getrut()>rut){
        buscar_alumno_reg(lista,rut,inicio,medio-1);
    }
    else {
        return aux;//enconrado devuelve el nodo donde esta el alumno buscado
    }
}

nodo1 *buscar_alumno_egre(nodo1 *lista,int rut, int inicio, int fin){
    int medio=(inicio+fin)/2;
    nodo1 *aux=lista;
    if(inicio>fin){
        return NULL;//no encontrado
    }
    for(int i=0; i<medio;i++){
        aux=aux->sig;
    }
    if(aux->alu.getrut()<rut){
        buscar_alumno_egre(lista,rut,medio+1,fin);
    }
    else if(aux->alu.getrut()>rut){
        buscar_alumno_egre(lista,rut,inicio,medio-1);
    }
    else {
        return aux;//enconrado devuelve el nodo donde esta el alumno buscado
    }
}

nodo2 *buscar_alumno_tit(nodo2 *lista,int rut, int inicio, int fin){
    int medio=(inicio+fin)/2;
    nodo2 *aux=lista;
    if(inicio>fin){
        return NULL;//no encontrado
    }
    for(int i=0; i<medio;i++){
        aux=aux->sig;
    }
    if(aux->alu.getrut()<rut){
        buscar_alumno_tit(lista,rut,medio+1,fin);
    }
    else if(aux->alu.getrut()>rut){
        buscar_alumno_tit(lista,rut,inicio,medio-1);
    }
    else {
        return aux;//enconrado devuelve el nodo donde esta el alumno buscado
    }
}

void ingresar_ramos_reg_egr(nodo_ramos_reg_egr *&lista,ramos_regular_egresados ramo_new){
    nodo_ramos_reg_egr *p = new nodo_ramos_reg_egr();
    p->ramo=ramo_new;
    nodo_ramos_reg_egr *aux1=lista; 
    nodo_ramos_reg_egr *aux2; 
    while((aux1!=NULL)&&(aux1->ramo.getnumero_semestre()<p->ramo.getnumero_semestre())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista == aux1){
        lista = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

void ingresar_ramos_tit(nodo_ramos_tit *&lista,ramos_titular ramo_new){
    nodo_ramos_tit *p = new nodo_ramos_tit();
    p->ramo=ramo_new;
    nodo_ramos_tit *aux1=lista; 
    nodo_ramos_tit *aux2; 
    while((aux1!=NULL)&&(aux1->ramo.getnombre_ramo()<p->ramo.getnombre_ramo())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if(lista == aux1){
        lista = p;
    }
    else{
        aux2->sig=p;
    }
    p->sig=aux1;
}

int largo_ramos_reg_egr(nodo_ramos_reg_egr *lista){
    nodo_ramos_reg_egr *aux=lista;
    int contador=0;
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
}

int largo_ramos_tit(nodo_ramos_tit *lista){
    nodo_ramos_tit *aux=lista;
    int contador=0;
    while(aux->sig!=NULL){
        contador++;
        aux=aux->sig;
    }
    return contador;
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

void menu_inscripcion_ramos_reg(nodo *alumno,nodo_ramos_reg_egr *lista_ramos){
    int opcion,posicion,pos,nota;
    nodo_ramos_reg_egr *aux=lista_ramos;
    nodo_ramos_reg_egr *aux2=lista_ramos;
    cout<<"*************************************************"<<endl;
    cout<<" 1) Inscribir ramos"<<endl;//inscripcion de ramos a alumno
    cout<<" 2) Ver ramos inscritos y notas"<<endl;//notas dentro de ramos
    cout<<" 3) Ingresar notas"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1://inscribir ramo ya ingresado
            for(int i=0;i<=largo_ramos_reg_egr(lista_ramos);i++){
                cout<<i+1<<")"<<aux->ramo.getnombre_ramo()<<endl;
                aux=aux->sig;
            }
            cout<<"Ingrese numero del ramo a inscribir"<<endl;
            cin>>posicion;
            for(int j=0;j<posicion-1;j++){
                aux2=aux2->sig;
            }
            alumno->alu.ingresar_ramos(aux2->ramo);
            break;
        case 2:           
            cout<<"*************************************************"<<endl;
            alumno->alu.get_ramos();
            cout<<"*************************************************"<<endl;
            break;
        case 3:
            alumno->alu.get_ramos_1();
            cout<<"Ingrese numero del ramo a ingresar notas"<<endl;
            cin>>pos;
            cout<<"Ingrese nota a ingresar"<<endl;
            cin>>nota;
            alumno->alu.ingresar_nota(nota,pos-1);
            break;
        default:
            break;
    }
}

void menu_inscripcion_ramos_egre(nodo1 *alumno,nodo_ramos_reg_egr *lista_ramos){
    int opcion,posicion,pos,nota;
    nodo_ramos_reg_egr *aux=lista_ramos;
    nodo_ramos_reg_egr *aux2=lista_ramos;
    cout<<"*************************************************"<<endl;
    cout<<" 1) Inscribir ramos"<<endl;//inscripcion de ramos a alumno
    cout<<" 2) Ver ramos inscritos y notas"<<endl;//notas dentro de ramos
    cout<<" 3) Ingresar notas"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1://inscribir ramo ya ingresado
            for(int i=0;i<=largo_ramos_reg_egr(lista_ramos);i++){
                cout<<i+1<<")"<<aux->ramo.getnombre_ramo()<<endl;
                aux=aux->sig;
            }
            cout<<"Ingrese numero del ramo a inscribir"<<endl;
            cin>>posicion;
            for(int j=0;j<posicion-1;j++){
                aux2=aux2->sig;
            }
            alumno->alu.ingresar_ramos(aux2->ramo);
            break;
        case 2:  
            cout<<"*************************************************"<<endl;
            alumno->alu.get_ramos();
            cout<<"*************************************************"<<endl;
            break;
        case 3: 
            alumno->alu.get_ramos_1();
            cout<<"Ingrese numero del ramo a ingresar notas"<<endl;
            cin>>pos;
            cout<<"Ingrese nota a ingresar"<<endl;
            cin>>nota;
            alumno->alu.ingresar_nota(nota,pos-1);
            break;
        default:
            break;
    }
}

void menu_inscripcion_ramos_tit(nodo2 *alumno,nodo_ramos_tit *lista_ramos){
    int opcion,posicion,pos,nota;
    string titulo,profesor_guia;
    nodo_ramos_tit *aux=lista_ramos;
    nodo_ramos_tit *aux2=lista_ramos;
    cout<<"*************************************************"<<endl;
    cout<<" 1) Inscribir ramos"<<endl;//inscripcion de ramos a alumno
    cout<<" 2) Ver ramos inscritos y notas"<<endl;//notas dentro de ramos
    cout<<" 3) Ingresar notas"<<endl;
    cout<<" 4) Ingresar tesis"<<endl;
    cout<<" 5) Ver tesis"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1://inscribir ramo ya ingresado
            for(int i=0;i<=largo_ramos_tit(lista_ramos);i++){
                cout<<i+1<<")"<<aux->ramo.getnombre_ramo()<<endl;
                aux=aux->sig;
            }
            cout<<"Ingrese numero del ramo a inscribir"<<endl;
            cin>>posicion;
            for(int j=0;j<posicion-1;j++){
                aux2=aux2->sig;
            }
            alumno->alu.ingresar_ramos_tit(aux2->ramo);
            break;
        case 2:  
            cout<<"*************************************************"<<endl;
            alumno->alu.get_ramos_tit();
            cout<<"*************************************************"<<endl;
            break;
        case 3:
            alumno->alu.get_ramos_tit_1();
            cout<<"Ingrese numero del ramo a ingresar notas"<<endl;
            cin>>pos;
            cout<<"Ingrese nota a ingresar"<<endl;
            cin>>nota;
            alumno->alu.ingresar_nota_tit(nota,pos-1);
            break;
        case 4 :
            cout<<"Ingrese titulo tesis"<<endl;
            cin>>titulo;
            cout<<"Ingrese nombre profesor guia"<<endl;
            cin>>profesor_guia;
            alumno->alu.set_tesis(titulo,profesor_guia);
            break;
        case 5:
            alumno->alu.get_tesis();
            break;
        default:
            break;
    }
}

void lectura(nodo *&lista_alum,nodo_ramos_reg_egr *&lista_ramos){
    ifstream archivo;
    archivo.open("datos.txt",ios::in);
    string texto;
    alumnos_regulares alu_new;
    ramos_regular_egresados ramo_new;
    if(archivo.fail()){
        cout<<"error al leer archivo"<<endl;
    }
    getline(archivo,texto,'\n');
    alu_new.setnombre(texto);
    getline(archivo,texto,'\n');
    alu_new.setrut(stoi(texto));
    numero_matricula++;
    alu_new.setnumero_matricula(numero_matricula);
    ingresar_alumno_reg(lista_alum,alu_new);
    getline(archivo,texto,'\n');
    alu_new.setnombre(texto);
    getline(archivo,texto,'\n');
    alu_new.setrut(stoi(texto));
    numero_matricula++;
    alu_new.setnumero_matricula(numero_matricula);
    ingresar_alumno_reg(lista_alum,alu_new);
    getline(archivo,texto,'\n');
    ramo_new.setnombre_ramo(texto);
    getline(archivo,texto,'\n');
    ramo_new.setnombre_carrera(texto);
    getline(archivo,texto,'\n');
    ramo_new.setnumero_semestre(stoi(texto));
    ingresar_ramos_reg_egr(lista_ramos,ramo_new);
    getline(archivo,texto,'\n');
    ramo_new.setnombre_ramo(texto);
    getline(archivo,texto,'\n');
    ramo_new.setnombre_carrera(texto);
    getline(archivo,texto,'\n');
    ramo_new.setnumero_semestre(stoi(texto));
    ingresar_ramos_reg_egr(lista_ramos,ramo_new);
    archivo.close();
}