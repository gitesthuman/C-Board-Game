#include "../Headers/Trawa.h"

Trawa::Trawa(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 0;
    this->inicjatywa = 0;
    this->znak = 't';
}

void Trawa::rozmnazanie(int x, int y) {
    Organizm* sadzonka = new Trawa(x,y,swiat);
    swiat->mapa[x][y] = sadzonka;
    swiat->nowoNarodzone.add(sadzonka);
}