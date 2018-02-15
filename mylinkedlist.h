#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "mystruct.h"

class LINKEDLISTNODE{
public:
  TDATO mynode;
  LINKEDLISTNODE *next;
private:
};	

class mylinkedlist {
public:
    //Estandar
    mylinkedlist();
    mylinkedlist(const mylinkedlist& orig);
    virtual ~mylinkedlist();
    //Práctica
    void show();
    void add(TDATO &d);
    void remove();
    void removeat(int at);
    void clear();
    LINKEDLISTNODE& get(int i);
    void insert(TDATO &d, int at);
    int count();
    //Aux
    void debug(bool is_active);
private:
    int length = 0;
    bool debug_flag = false;
    LINKEDLISTNODE* head_reference;
    LINKEDLISTNODE* find(int i);
    void dmsg(std::string message);
};

#endif /* MYLINKEDLIST_H */

