#include <iostream>
#include <vector>
#include "mystruct.h"
#include "myvector.h"
#include "mystack.h"
#include "mytail.h"
#include "mylinkedlist.h"

using namespace std;

int main(int argc, char** argv) {
    
    TDATO a;
    a.cod = 1;
    a.name = "Ramón";  
    a.surname = "Negrillo Valdivia";
    
    TDATO b;
    b.cod = 2;
    b.name = "Yezer";  
    b.surname = "Gonzalez Mella";
    
    TDATO c;
    c.cod = 3;
    c.name = "Rayco";  
    c.surname = "Serpa Alemani";
    
    TDATO d;
    d.cod = 4;
    d.name = "Ana Maria";  
    d.surname = "Nesoya Marquez";
    
    // Ejemplo de una estructura de datos, dentro de otra
    // Una clase MYVECTOR que contiene N clases MYTAIL
    // NOTA: Para hacer esto hay que modificar previamente la clase
    // MYVECTOR para que en vez de trabarja con TDATO, lo hiciera con 
    // estructuras MYTAIL
    
    myvector *v = new myvector();
    mytail *t1 = new mytail();
    mytail *t2 = new mytail();
    
    t1->push(a);
    t1->push(b);
    
    t2->push(c);
    t2->push(d);
    
    v->add(*t1);   // OJO! *t1 no t1... importante
    v->add(*t2);
    
    v->show();
    return 0;
}

