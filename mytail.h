#ifndef MYTAIL_H
#define MYTAIL_H

#include "mystruct.h"

class TAILNODE{
public:
  TDATO mynode;
  TAILNODE *next;
private:
};	

class mytail {
public:
    //Estandar
    mytail();
    mytail(const mytail& orig);
    virtual ~mytail();
    //Práctica
    void show();
    void push(TDATO &d);
    TAILNODE& pop();
    void clear();
    int count();
    //Aux
    void debug(bool is_active);
private:
    void removeat(int at);
    TAILNODE& get(int i);
    void insert(TDATO &d, int at);
    int length = 0;
    bool debug_flag = false;
    TAILNODE* head_reference;
    TAILNODE* find(int i);
    void dmsg(std::string message);  
};

#endif /* MYTAIL_H */

