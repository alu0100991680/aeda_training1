#include <string>
#include <iostream>
#include "mytail.h"

using namespace std;

//==================
//Métodos estandares
//==================

mytail::mytail() {
}

mytail::mytail(const mytail& orig) {
}

mytail::~mytail() {
}

//================
//Métodos práctica
//================

TAILNODE * mytail::find(int at){
    TAILNODE *n = this->head_reference;
    for(int i=0;i<at;i++){
        n = n->next;
    }
    return n;
}

TAILNODE& mytail::get(int i){
    this->dmsg("F:GET->" + to_string(i));
    TAILNODE *d = this->find(i);
    return *d;
}

int mytail::count() {
    this->dmsg("F:COUNT");
    return this->length;
}

void mytail::show() {
    this->dmsg("F:SHOW");
    this->dmsg("F:SHOW:Lista de objectos");
    if (length==0){ this->dmsg("F:SHOW:Vacia"); }
    
    cout << "--------" << endl;
    for (int i=0; i<this->length; i++){
        TAILNODE *current_ = this->find(i);
        this->dmsg("F:SHOW:Objecto->" + to_string(i));
        cout << "Next->" << current_->next << endl;
        cout << current_->mynode.cod << endl;
        cout << current_->mynode.name << endl;
        cout << current_->mynode.surname << endl << endl;
    }
}

void mytail::clear(){
    this->dmsg("F:CLEAR");
    int fullcontent = this->length;
    for (int i=0;i<fullcontent;i++){
        this->removeat(0);
    }
    this->length = 0;
}

void mytail::push(TDATO &d) {
    this->dmsg("F:ADD");
    this->insert(d, 0);
}

 TAILNODE& mytail::pop() {
    this->dmsg("F:REMOVE");
    TAILNODE *c_aux = nullptr;
    if(0<this->length){
        TAILNODE *aux = this->find(this->length-1);
        c_aux = new TAILNODE(); // Hacemos una copia antes de borrarlo
        c_aux->mynode.cod = aux->mynode.cod;
        c_aux->mynode.name = aux->mynode.name;
        c_aux->mynode.surname = aux->mynode.surname;
        this->removeat(this->length-1);
    }
    return *c_aux;
}

void mytail::insert(TDATO &d, int at){
    this->dmsg("F:INSERT->" + to_string(at));
    if((0<=at)&&(at<=this->length)){
        TAILNODE *m = new TAILNODE();
        m->mynode.cod = d.cod;
        m->mynode.name = d.name;
        m->mynode.surname = d.surname; 

        if (at<this->length){
            TAILNODE *n = this->find(at);
            m->next = n; 

        }
        
        if (0<at){
            TAILNODE *p = this->find(at-1);
            p->next = m;
        }
        
        if (at==0){
            this->head_reference = m;
        }
        
        this->length++;
    }
}

void mytail::removeat(int at){
    this->dmsg("F:REMOVEAT->" + to_string(at));
    if((0<=at)&&(at<=this->length)){
        TAILNODE *c = this->find(at);
        if(0<at){
            TAILNODE *p = this->find(at-1);
            TAILNODE *n = nullptr;
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

void mytail::debug(bool is_active){
    this->debug_flag = is_active;
}

void mytail::dmsg(string message){
    if (this->debug_flag==true){
        cout << message << endl;
    }
}
