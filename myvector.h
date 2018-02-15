#ifndef MYVECTOR_H
#define MYVECTOR_H

//#include "mystruct.h"
#include "mytail.h"

/* MODIFICACIÓN PARA ENTRENAMIENTO PRE-ENTREGA */

class myvector {
    
public:
    //Estandar
    myvector();
    myvector(const myvector& orig);
    virtual ~myvector();
    //Práctica
    void show();
    void add(mytail &d);
    void remove();
    int count();
    mytail& get(int i);
    void insert(mytail &d, int at);
    void removeat(int at);
    void clear();
    //Aux
    void debug(bool is_active);
private:
    void resize(int i);
    int length = 0;
    int max_limit = 0;
    bool debug_flag = false;
    struct mytail *p_objects;
    void dmsg(std::string message);
};

#endif
