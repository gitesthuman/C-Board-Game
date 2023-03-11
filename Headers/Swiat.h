#pragma once
#include "Lista.h"

class Czlowiek;

class Swiat {
public:
    Lista organizmy;
    Lista nowoNarodzone;
    Organizm*** mapa;

    Swiat(int wysokosc, int szerokosc);
    void wykonajTure();
    void rysujSwiat() const;
    void dodajOrganizm(Organizm* organizm);
    void dodajOrganizm(Czlowiek czl);
    int getWysoskosc() const;
    int getSzerokosc() const;
    ~Swiat();

private:
    int M;
    int N;
    Czlowiek* czlowiek;
};