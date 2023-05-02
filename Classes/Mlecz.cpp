#include "../Headers/Mlecz.h"

Mlecz::Mlecz(int X, int Y, Swiat *swiat) {
    this->X = X;
    this->Y = Y;
    this->swiat = swiat;
    this->sila = 0;
    this->inicjatywa = 0;
    this->znak = 'd';
}

void Mlecz::akcja() {
    for (int i = 0 ; i < 3 ; ++i) {
        Roslina::akcja();
    }
}

void Mlecz::rozmnazanie(int x, int y) {
    Organizm* sadzonka = new Mlecz(x,y,swiat);
    swiat->mapa[x][y] = sadzonka;
    swiat->nowoNarodzone.add(sadzonka);
}