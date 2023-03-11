#include "../Headers/Wilk.h"

Wilk::Wilk(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 9;
    this->inicjatywa = 5;
    this->znak = 'W';
}

void Wilk::rozmnazanie(int x, int y) {
    Organizm* dziecko = new Wilk(x,y,swiat);
    swiat->mapa[x][y] = dziecko;
    swiat->nowoNarodzone.add(dziecko);
}