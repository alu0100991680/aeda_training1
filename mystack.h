#ifndef MYSTACK_H
#define MYSTACK_H

#include "mystruct.h"

class STACKNODE{
public:
  TDATO mynode;
  STACKNODE *next;
private:
};	

class mystack {
public:
    //Estandar
    mystack();
    mystack(const mystack& orig);
    virtual ~mystack();
    //Práctica
    void show();
    void push(TDATO &d);
    STACKNODE& pop();
    void clear();
    int count();
    //Aux
    void debug(bool is_active);
private:
    void removeat(int at);
    STACKNODE& get(int i);
    void insert(TDATO &d, int at);
    int length = 0;
    bool debug_flag = false;
    STACKNODE* head_reference;
    STACKNODE* find(int i);
    void dmsg(std::string message);   
};

#endif /* MYSTACK_H */

