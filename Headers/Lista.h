#pragma once
#include "Organizm.h"

class Lista {
private:
    //element listy
    struct Node {
        Organizm* value;
        Node* next;
        Node* prev;
    };
    Node* beg;
    Node* end;
    int size;

public:
    Lista();
    void add(Organizm* o);
    int getSize() const;
    Organizm* getBeg();
    void naKoniec();
    Organizm* findElement(int x, int y);
    void delElement(int x, int y);
    ~Lista();
};