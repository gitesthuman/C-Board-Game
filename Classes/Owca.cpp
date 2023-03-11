#include "../Headers/Owca.h"

Owca::Owca(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 4;
    this->inicjatywa = 4;
    this->znak = 'O';
}

void Owca::rozmnazanie(int x, int y) {
    Organizm* dziecko = new Owca(x,y,swiat);
    swiat->mapa[x][y] = dziecko;
    swiat->nowoNarodzone.add(dziecko);
}