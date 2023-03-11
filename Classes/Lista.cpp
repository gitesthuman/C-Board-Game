#include "../Headers/Lista.h"
#include <iostream>

Lista::Lista() {
    beg = nullptr;
    end = nullptr;
    size = 0;
}

void Lista::add(Organizm* o) {
    if (size == 0) {
        Node* N = new Node;
        N->value = o;
        N->next = N;
        N->prev = N;
        beg = N;
        end = N;
        size = 1;
    }
    else {
        Node* N = new Node;
        N->value = o;
        if (beg->value->inicjatywa < o->inicjatywa) {
            N->next = beg;
            N->prev = end;
            end->next = N;
            beg->prev = N;
            beg = N;
            size++;
            return;
        }
        Node* tmp = beg->next;
        while (tmp->value->inicjatywa >= o->inicjatywa && tmp != beg)
            tmp = tmp->next;
        N->next = tmp;
        N->prev = tmp->prev;
        tmp->prev->next = N;
        tmp->prev = N;
        if (tmp == beg) end = N;
        size++;
    }
}

int Lista::getSize() const {
    return size;
}

Organizm* Lista::getBeg() {
    return beg->value;
}

void Lista::naKoniec() {
    end = beg;
    beg = beg->next;
}

Lista::~Lista() {
    if (size > 0) {
        while (beg != end) {
            Node *tmp = beg->next;
            delete beg;
            beg = tmp;
        }
        delete beg;
    }
}

Organizm* Lista::findElement(int x, int y) {
    Node* tmp = beg;
    if(tmp->value->X == x && tmp->value->Y == y) return beg->value;
    tmp = beg->next;
    while (tmp != beg) {
        if (tmp->value->X == x && tmp->value->Y == y) return tmp->value;
        tmp = tmp->next;
    }
    return nullptr;
}

void Lista::delElement(int x, int y) {
    if (size == 1) {
        delete beg;
        beg = nullptr;
        end = nullptr;
        size = 0;
    }
    else if (size>1) {
        Node* tmp = beg;
        if(tmp->value->X == x && tmp->value->Y == y) {
            end->next = beg->next;
            beg->next->prev = end;
            Node* tmp = beg->next;
            delete beg;
            beg = tmp;
            size--;
        }
        tmp = beg->next;
        while (tmp != beg) {
            if (tmp->value->X == x && tmp->value->Y == y) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                if (tmp == end) end = end->prev;
                delete tmp;
                size--;
                return;
            }
            tmp = tmp->next;
        }
    }
}