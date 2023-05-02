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
    int getWysoskosc() const;
    int getSzerokosc() const;
    bool isHumanAlive();
    void killHuman();
    ~Swiat();

private:
    int M;
    int N;
    Czlowiek* czlowiek;
};