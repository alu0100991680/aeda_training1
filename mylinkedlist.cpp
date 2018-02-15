#include <string>
#include <iostream>
#include "mylinkedlist.h"

using namespace std;

//==================
//Métodos estandares
//==================

mylinkedlist::mylinkedlist() {
}

mylinkedlist::mylinkedlist(const mylinkedlist& orig) {
}

mylinkedlist::~mylinkedlist() {
}

//================
//Métodos práctica
//================

LINKEDLISTNODE * mylinkedlist::find(int at){
    LINKEDLISTNODE *n = this->head_reference;
    for(int i=0;i<at;i++){
        n = n->next;
    }
    return n;
}

void mylinkedlist::add(TDATO &d) {
    this->dmsg("F:ADD");

    LINKEDLISTNODE *n = new LINKEDLISTNODE();
    if (0<this->length){
        n->mynode.cod = d.cod;
        n->mynode.name = d.name;
        n->mynode.surname = d.surname;

        LINKEDLISTNODE *d = this->find(this->length-1);
        
        d->next = n;
        
    }else{
        //first
        n->mynode.cod = d.cod;
        n->mynode.name = d.name;
        n->mynode.surname = d.surname;
        n->next = nullptr;
        
        // Puntero head
        this->head_reference = n;
    }
    
    //Ampliamos el indicador de contenido
    this->length++;

}

void mylinkedlist::remove() {
    this->dmsg("F:REMOVE");
    if (0<this->length){
        //Creamos un vector y puntero asociado para volcar la nueva información
        //this->resize(-1);
            //Añadimos el nuevo dato a la cola

        //Ampliamos el indicador de contenido
        if(1<this->length){
            LINKEDLISTNODE *d = this->find(this->length-1);
            delete d->next;
            this->length--;
        }else{
            delete this->head_reference;
        }
    }
}

LINKEDLISTNODE& mylinkedlist::get(int i){
    this->dmsg("F:GET->" + to_string(i));
    LINKEDLISTNODE *d = this->find(i);
    return *d;
}

int mylinkedlist::count() {
    this->dmsg("F:COUNT");
    return this->length;
}

void mylinkedlist::show() {
    this->dmsg("F:SHOW");
    this->dmsg("F:SHOW:Lista de objectos");
    if (length==0){ this->dmsg("F:SHOW:Vacia"); }
    
    cout << "--------" << endl;
    for (int i=0; i<this->length; i++){
        LINKEDLISTNODE *current_ = this->find(i);
        this->dmsg("F:SHOW:Objecto->" + to_string(i));
        cout << "Next->" << current_->next << endl;
        cout << current_->mynode.cod << endl;
        cout << current_->mynode.name << endl;
        cout << current_->mynode.surname << endl << endl;
    }
}

void mylinkedlist::clear(){
    this->dmsg("F:CLEAR");
    int fullcontent = this->length;
    for (int i=0;i<fullcontent;i++){
        this->remove();
    }
    this->length = 0;
}

void mylinkedlist::insert(TDATO &d, int at){
    this->dmsg("F:INSERT->" + to_string(at));
    if((0<=at)&&(at<=this->length)){
        LINKEDLISTNODE *m = new LINKEDLISTNODE();
        m->mynode.cod = d.cod;
        m->mynode.name = d.name;
        m->mynode.surname = d.surname; 

        if (at<this->length){
            LINKEDLISTNODE *n = this->find(at);
            m->next = n; 

        }
        
        if (0<at){
            LINKEDLISTNODE *p = this->find(at-1);
            p->next = m;
        }
        
        if (at==0){
            this->head_reference = m;
        }
        
        this->length++;
    }
}

void mylinkedlist::removeat(int at){
    this->dmsg("F:REMOVEAT->" + to_string(at));
    if((0<=at)&&(at<=this->length)){
        LINKEDLISTNODE *c = this->find(at);
        if(0<at){
            LINKEDLISTNODE *p = this->find(at-1);
            LINKEDLISTNODE *n = nullptr;
            if (at+1<this->length){        
                n= this->find(at+1);
            }
            p->next = n;
        }else{
            this->head_reference = c->next;
        }

        delete c;
        this->length--;
    }
}

//===========
//Métodos Aux
//===========

void mylinkedlist::debug(bool is_active){
    this->debug_flag = is_active;
}

void mylinkedlist::dmsg(string message){
    if (this->debug_flag==true){
        cout << message << endl;
    }
}
