#include <iostream>
#include <string>
#include "myvector.h"

using namespace std;

//==================
//Métodos estandares
//==================

myvector::myvector() {
}

//Constructor copia
myvector::myvector(const myvector& orig) {
}

myvector::~myvector() {
}

//================
//Métodos práctica
//================

void myvector::show() {
    this->dmsg("F:SHOW");
    this->dmsg("F:SHOW:Lista de objectos");
    if (length==0){ this->dmsg("F:SHOW:Vacia"); }
    
    //cout << "--------" << endl;
    for (int i=0;i<this->length;i++){
        this->dmsg("F:SHOW:Objecto->" + std::to_string(i));
        this->p_objects[i].show();
        //mytail *t = this->p_objects[i].show();
        /*cout << this->p_objects[i].cod << endl;
        cout << this->p_objects[i].name << endl;
        cout << this->p_objects[i].surname<< endl << endl;*/
    }
}

void myvector::add(mytail &d) {
    this->dmsg("F:ADD");
    
    //Creamos un vector y puntero asociado para volcar la nueva información
    this->resize(1);

    //Añadimos el nuevo dato a la cola
    /*this->p_objects[this->length].cod=d.cod;
    this->p_objects[this->length].name=d.name;
    this->p_objects[this->length].surname=d.surname;*/
    
    this->p_objects[this->length]=d;
    
    //Ampliamos el indicador de contenido
    this->length++;
}

void myvector::remove() {
    this->dmsg("F:REMOVE");
    if (0<this->length){
        //Creamos un vector y puntero asociado para volcar la nueva información
        //this->resize(-1);

        //Ampliamos el indicador de contenido
        this->length--;
    }
}

int myvector::count() {
    this->dmsg("F:COUNT");
    return this->length;
}

mytail& myvector::get(int i){
    this->dmsg("F:GET->" + std::to_string(i));
    return this->p_objects[i];
}

void myvector::resize(int i){
    this->dmsg("F:RESIZE->" +std::to_string(i));
    if ((this->max_limit<this->length+i)&&(0<=this->length+i)){
        this->p_objects = (mytail*)std::realloc(this->p_objects,(this->length+i)*sizeof(mytail));
        this->max_limit++;
    }else{
        this->dmsg("F:RESIZE:Not necessary resize");
    }
}

void myvector::insert(mytail &d, int at){
    this->dmsg("F:INSERT->"+ std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        this->resize(1);
        for(int i=this->length-1;at<=i;i--){
            this->p_objects[i+1] = this->p_objects[i];
        }
        /*this->p_objects[at].cod=d.cod;
        this->p_objects[at].name=d.name;
        this->p_objects[at].surname=d.surname;*/
        this->p_objects[at]=d;
        this->length++;
    }
}

void myvector::removeat(int at){
    this->dmsg("F:removeat->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        for(int i=at;i<this->length-1;i++){
            this->p_objects[i] = this->p_objects[i+1];
        }
        this->length--;
    }
}

void myvector::clear(){
    this->dmsg("F:CLEAR");
    int fullcontent = this->length;
    for (int i=0;i<fullcontent;i++){
        this->remove();
    }
    this->length = 0;
    this->max_limit = 0;
}

void myvector::debug(bool is_active){
    this->debug_flag = is_active;
}

void myvector::dmsg(std::string message){
    if (this->debug_flag==true){
        cout << message << endl;
    }
}